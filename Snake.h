#ifndef _SNAKE_H_ 
#define _SNAKE_H_

#define MaxX 64
#define MaxY 25
#include <iostream>
#include "_Common.h"
#include <time.h>

using namespace std;
void Dead();
void TakeColor(int x);

class Point
{
	int x, y;
	char c = 'o';
	int TheMove = 1;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int GetMove() { return TheMove; }
	void SetMove(int Move) { TheMove = Move; }
	Point() { x = 0; y = 0; }
	int getX() { return x; }
	int getY() { return y; }
	void SetXY(int x, int y) { this->x = x; this->y = y; }
	char GetC() { return c; }
	void SetC(char c) { this->c = c; }
	void Right();
	void Left();
	void Up();
	void Down();
	void Go();
};



class Snake
{
	Point *Head, **Duoi;
	Point *Food;
	int size = 4;
	char score[3];
	int _command;

public:
	Snake();
	~Snake()
	{
		delete Head;
		delete Food;
		for (int i = 0; i < size; i++)
		{
			delete Duoi[i];
		}
		delete Duoi;
		delete Food;
	}
	void TakeFood();
	char waitKeyBoard();
	void SetSize(int size) { size = size; }
	int GetSize() { return size; }
	
	void draw()
	{
		_Common::gotoXY(28, 1);
		TakeColor(6);
		cout << "POINT 000";
		



		
		_Common::gotoXY(0, 2);
		TakeColor(1);

		cout << "................................................................";
		if (Head)
		{
			_Common::gotoXY(Head->getX(), Head->getY());
			cout << Head->GetC();
			for (int i = 0; i < size; i++)
			{
				_Common::gotoXY(Duoi[i]->getX(), Duoi[i]->getY());
				cout << Duoi[i]->GetC();
			}

		}

	}
	void Move();
	void Right();
	void Left();
	void Up();
	void Down();

	void Dead();
};






#endif
