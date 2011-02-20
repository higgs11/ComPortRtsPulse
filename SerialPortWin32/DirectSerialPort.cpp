#include "StdAfx.h"
#include "DirectSerialPort.h"

DirectSerialPort::DirectSerialPort(void)
{
}

DirectSerialPort::~DirectSerialPort(void)
{
}

void DirectSerialPort::Open(LPCWSTR Port)
{
	hSerial = CreateFile(Port, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if(hSerial == INVALID_HANDLE_VALUE)
	{
		return;
	}
	
	//Configure port
	DCB dcbSerialParams = {0};
	//dcbSerial.DCBlength=sizeof(dcbSerialParams);
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
	dcbSerialParams.BaudRate=CBR_115200;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.StopBits=ONESTOPBIT;
	dcbSerialParams.Parity=NOPARITY;
	SetCommState(hSerial, &dcbSerialParams);


	//Set timeouts
	COMMTIMEOUTS timeouts={0};
	timeouts.ReadIntervalTimeout=100;
	timeouts.ReadTotalTimeoutConstant=100;
	timeouts.ReadTotalTimeoutMultiplier=20;
	SetCommTimeouts(hSerial, &timeouts);



}

void DirectSerialPort::Close(void)
{
	CloseHandle(hSerial);
}

void DirectSerialPort::Write(char ch)
{
	DWORD bytesWritten;
	char buff[1] = {ch};

	WriteFile(hSerial, buff, 1, &bytesWritten, NULL);
}

void DirectSerialPort::PulseRTS(void)
{
	EscapeCommFunction(hSerial, SETRTS);
	EscapeCommFunction(hSerial, CLRRTS);

}


