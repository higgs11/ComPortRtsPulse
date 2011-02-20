#pragma once

#include <windows.h>

class DirectSerialPort
{
	/*
	typedef wchar_t WCHAR ;

	typedef CONST WCHAR *LPCWSTR;

	wchar_t port[]=L"COM4";
	*/

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
