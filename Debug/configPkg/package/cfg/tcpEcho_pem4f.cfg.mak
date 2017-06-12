# invoke SourceDir generated makefile for tcpEcho.pem4f
tcpEcho.pem4f: .libraries,tcpEcho.pem4f
.libraries,tcpEcho.pem4f: package/cfg/tcpEcho_pem4f.xdl
	$(MAKE) -f C:\Users\Raphael\Downloads\tcpEcho_EK_TM4C1294XL_TI/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\Raphael\Downloads\tcpEcho_EK_TM4C1294XL_TI/src/makefile.libs clean

