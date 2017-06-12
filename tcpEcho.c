/*
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *    ======== tcpEcho.c ========
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>

 /* NDK Header files */
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/_stack.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

/* Example/Board Header files */
#include "Board.h"

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

#define TCPPACKETSIZE 1024
#define TCPPORT 8000
#define NUMTCPWORKERS 1

//*****************************************************************************
//
// System clock rate in Hz.
//
//*****************************************************************************
uint32_t g_ui32SysClock;


void delay(void)
{
    //SysCtlDelay(g_ui32SysClock);
    Task_sleep(10);

}


/*
 *  ======== tcpWorker ========
 *  Task to handle TCP connection. Can be multiple Tasks running
 *  this function.
 */
Void tcpWorker(UArg arg0, UArg arg1)
{
    SOCKET clientfd = (SOCKET)arg0;
    int nbytes;
    bool flag = true;
    char *buffer;
    Error_Block eb;

    fdOpenSession(TaskSelf());

    System_printf("tcpWorker: start clientfd = 0x%x\n", clientfd);
    System_flush();
    /* Make sure Error_Block is initialized */
    Error_init(&eb);

    /* Get a buffer to receive incoming packets. Use the default heap. */
    buffer = Memory_alloc(NULL, TCPPACKETSIZE, 0, &eb);
    if (buffer == NULL) {
        System_printf("tcpWorker: failed to alloc memory\n");System_flush();
        Task_exit();
    }

    /* Loop while we receive data */
    while (flag) {
        nbytes = recv(clientfd, (char *)buffer, TCPPACKETSIZE, 0);
        if (nbytes > 0) {
            /* Echo the data back */
            char *buffer2 = "I like turtles.";
            nbytes = 15;
            send(clientfd, (char *)buffer2, nbytes, 0 );
        }
        else {
            fdClose(clientfd);
            flag = false;
        }
    }
    System_printf("tcpWorker stop clientfd = 0x%x\n", clientfd);System_flush();

    /* Free the buffer back to the heap */
    Memory_free(NULL, buffer, TCPPACKETSIZE);

    fdCloseSession(TaskSelf());
    /*
     *  Since deleteTerminatedTasks is set in the cfg file,
     *  the Task will be deleted when the idle task runs.
     */
    Task_exit();
}

/*
 *  ======== tcpHandler ========
 *  Creates new Task to handle new TCP connections.
 */
Void tcpHandler(UArg arg0, UArg arg1)
{
    SOCKET lSocket;
    struct sockaddr_in sLocalAddr;

    fdOpenSession(TaskSelf());

    lSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (lSocket < 0) {
        System_printf("tcpHandler: socket failed\n");System_flush();
        Task_exit();
        return;
    }
    System_printf("lsocket: %d\n",&lSocket);
      System_flush();
    memset((char *)&sLocalAddr, 0, sizeof(sLocalAddr));
    sLocalAddr.sin_family = AF_INET;
    //sLocalAddr.sin_len = sizeof(sLocalAddr);
    sLocalAddr.sin_addr.s_addr = inet_addr("192.168.1.6");//htonl(INADDR_ANY);
    sLocalAddr.sin_port = htons(arg0);

    while(connect(lSocket, (struct sockaddr *)&sLocalAddr, sizeof(sLocalAddr)) < 0){
        SysCtlDelay(g_ui32SysClock/100/3);
    }

    System_flush();
    char *buffer2 = "I like satyricon.";
    int nbytes = 17;
   // while (true) {
        send(lSocket, (char *)buffer2, nbytes, 0 );

//      nbytes = recv(lSocket, (char *)buffer, TCPPACKETSIZE, 0);
//      if (nbytes > 0) {
//          System_printf("%s", buffer);
//      }
//      System_flush();
        fdCloseSession(TaskSelf());
        Task_sleep(1000);
//    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Handle taskHandle;
    Task_Params taskParams;
    Error_Block eb;

    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                    SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
                    SYSCTL_CFG_VCO_480), 120000000);

    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Board_initEMAC();

    System_printf("Starting the TCP Echo example\nSystem provider is set to "
                  "SysMin. Halt the target to view any SysMin contents in"
                  " ROV.\n");
    /* SysMin will only print to the console when you call flush or exit */
    System_flush();

    /*
     *  Create the Task that farms out incoming TCP connections.
     *  arg0 will be the port that this task listens to.
     */
    Task_Params_init(&taskParams);
    Error_init(&eb);

    taskParams.stackSize = 1024;
    taskParams.priority = 1;
    taskParams.arg0 = TCPPORT;
    taskHandle = Task_create((Task_FuncPtr)tcpHandler, &taskParams, &eb);
    if (taskHandle == NULL) {
        System_printf("main: Failed to create tcpHandler Task\n");System_flush();
    }

    /* Start BIOS */
    BIOS_start();

    return (0);
}
