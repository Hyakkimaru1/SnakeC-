#ifndef  _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

class _Common {
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
};



#endif // ! _COMMON_H_
