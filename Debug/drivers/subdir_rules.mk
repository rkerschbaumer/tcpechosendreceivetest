################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
drivers/Kentec320x240x16_ssd2119_8bit.obj: ../drivers/Kentec320x240x16_ssd2119_8bit.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/ndk_2_25_00_09/packages/ti/ndk/inc/bsd" --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/TivaWare_C_Series-2.1.1.71b" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="drivers/Kentec320x240x16_ssd2119_8bit.d" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/frame.obj: ../drivers/frame.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/ndk_2_25_00_09/packages/ti/ndk/inc/bsd" --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/TivaWare_C_Series-2.1.1.71b" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="drivers/frame.d" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/pinout.obj: ../drivers/pinout.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/ndk_2_25_00_09/packages/ti/ndk/inc/bsd" --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/TivaWare_C_Series-2.1.1.71b" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="drivers/pinout.d" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/touch.obj: ../drivers/touch.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/ndk_2_25_00_09/packages/ti/ndk/inc/bsd" --include_path="C:/Users/christoph/workspace/tcpEcho_EK_TM4C1294XL_TI" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/TivaWare_C_Series-2.1.1.71b" --include_path="C:/ti/tirex-content/tirtos_tivac_2_16_00_08/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="C:/ti/ccs700/ccsv7/tools/compiler/ti-cgt-arm_16.9.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="drivers/touch.d" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


