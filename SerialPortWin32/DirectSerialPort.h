#pragma once

#include <windows.h>

class DirectSerialPort
{
	
private:
	HANDLE hSerial;

public:
	DirectSerialPort(void);
	~DirectSerialPort(void);
	void Open(LPCWSTR Port);
	void Close(void);
	void Write(char ch);
	void PulseRTS(void);
};
