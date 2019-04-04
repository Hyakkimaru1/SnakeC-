#include <iostream>
#include "_Common.h"
#include <windows.h>
#include "Snake.h"
using namespace std;




int main()
{

	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info); 
	_Common::fixConsoleWindow();
	
	Snake snake;
	snake.draw();
	snake.Move();
	cout << "\n";
	system("pause");

}