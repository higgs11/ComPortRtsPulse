// SerialPortWin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DirectSerialPort.h"


int _tmain(int argc, _TCHAR* argv[])
{
	DirectSerialPort* port = new DirectSerialPort();
	port->Open(L"COM3");
	for(int i = 0; i < 10; i++)
	{
		//port->Write('a');
		port->PulseRTS();
	}
	port->Close();
	return 0;
}

