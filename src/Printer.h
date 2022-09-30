#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

void PrintErrorText(const char* msg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	cout << endl << msg << endl;
	SetConsoleTextAttribute(hConsole, 14);
}

void PrintHeader(const char* msg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << endl << msg << endl;
	SetConsoleTextAttribute(hConsole, 14);
}
