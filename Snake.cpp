#include "Snake.h"

void TakeColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void Snake::TakeFood()
{
	srand(time(0));
	int x =  rand() % 65;
	int y = rand() % 23 + 3;

	if (x == Head->getX() && y == Head->getY())
		return TakeFood();
	for (int i = 0 ;i <size;i++)
		if (x == Duoi[i]->getX() && y == Duoi[i]->getY())
			return TakeFood();
	Food->SetXY(x, y);
	TakeColor(3);
	_Common::gotoXY(Food->getX(), Food->getY());
	cout << Food->GetC();
}

Snake::Snake()
{
	Head = new Point(32, 12);
	Head->SetC('@');
	score[0] = '0';
	score[1] = '0';
	score[2] = '0';
	Duoi = new Point*[4];
	*Duoi = new Point(32, 12);
	Duoi[1] = new Point(31, 12);
	Duoi[2] = new Point(30, 12);
	Duoi[3] = new Point(29, 12);
	Food = new Point;
	TakeFood();
}


void Point::Right()
{
	if (x == MaxX)
		x = 0;
	else x++;	
	_Common::gotoXY(x,y);
	cout << c;
}

void Point::Left()
{
		if (x == 0)
			x=MaxX;
		else x--;
		_Common::gotoXY(x,y);
		cout << c;
}

void Point::Up()
{
		if (y == 3)
			y= MaxY;
		else y--;
		_Common::gotoXY(x, y);
		cout << c;
}


void Point::Down()
{
		if (y == MaxY)
			y = 3;
		else y++;
		_Common::gotoXY(x,y);
		cout << c;
}

char Snake::waitKeyBoard() {

	_command = toupper(_getch());
	return _command;
}

void Point::Go()
{
	if (TheMove == 1)
		Right();
	else if (TheMove == 2)
		Left();
	else if (TheMove == 3)
		Up();
	else Down();
}

bool Character(char c)
{
	if (c > '9')
		return true;
	return false;
}

void Snake::Move()
{
	//draw();
	/*_Common::gotoXY(Head->getX(), Head->getY());
	cout << Head->GetC();
	for (int i = 0; i < size; i++)
	{
		_Common::gotoXY(Duoi[i]->getX(), Duoi[i]->getY());
		cout << Duoi[i]->GetC();
	}*/
	TakeColor(4);
	int MaxHead = Head->getX();
	int tempX, tempY;
	Point* p = new Point;
	bool test = true;
	while (test)
	{
		
		Sleep(100);
		tempX = Duoi[size - 1]->getX();
		tempY = Duoi[size - 1]->getY();
		
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'D' || c == 'd')
			{
				if (Head->GetMove() != 2)
				{
					Head->SetMove(1);
					
				}
			}
			if (c == 'A' || c == 'a')
			{

				if (Head->GetMove() != 1)
				{
					Head->SetMove(2);
					
				}

			}
			if (c == 'W' || c == 'w')
			{
				if (Head->GetMove() != 4)
				{
					Head->SetMove(3);
				}

			}
			if (c == 'S' || c == 's')
			{
				if (Head->GetMove() != 3)
				{
					Head->SetMove(4);
				}

			}
		}
		

		p->SetXY(Head->getX(),Head->getY());
		Head->Go();

		if (Head->getX() == Food->getX() && Head->getY() == Food->getY())
		{
			_Common::gotoXY(34, 1);
			TakeColor(6);
			score[2]++;
			for (int i = 1; i < 3; i++)
			{
				if (Character(score[i]))
				{
					score[i - 1]++;
					score[i] = '0';
				}
			}
			
			for (int i = 0; i < 3; i++)
				cout << score[i];

			Point** Duoi1 = new Point*[size];
			for (int i = 0; i < size; i++)
			{
				Duoi1[i] = new Point;
				Duoi1[i]->SetXY(Duoi[i]->getX(), Duoi[i]->getY());
			}
			for (int i = 0; i < size; i++)
			{
				delete Duoi[i];
			}
			delete Duoi;
			Duoi = new Point*[size + 1];
			Duoi[size] = new Point;
			for (int i = 0; i < size; i++)
			{
				Duoi[i] = new Point;
				Duoi[i]->SetXY(Duoi1[i]->getX(), Duoi1[i]->getY());
			}
			for (int i = 0; i < size; i++)
			{
				delete Duoi1[i];
			}
			delete Duoi1;
			size = size + 1;
			Duoi[size - 1]->SetXY(Duoi[size-2]->getX()+1,Duoi[size-2]->getY());
			_Common::gotoXY(Duoi[size-1]->getX(), Duoi[size - 1]->getY());
			cout << Duoi[size - 1]->GetC();
			TakeFood();
			TakeColor(4);
			tempX = Duoi[size - 1]->getX();
			tempY = Duoi[size - 1]->getY();
		}

		for (int i = size - 1 ;i>0; i--)
		{
			Duoi[i]->SetXY(Duoi[i-1]->getX(),Duoi[i-1]->getY());
			_Common::gotoXY(Duoi[i]->getX(), Duoi[i]->getY());
			cout << Duoi[i]->GetC();
		}
		Duoi[0]->SetXY(p->getX(), p->getY());
		_Common::gotoXY(p->getX(), p->getY());
		cout << Duoi[0]->GetC();
		
	
		_Common::gotoXY(tempX, tempY);
		cout << " ";
		if (size > 2)
		{
			for (int i = 3; i < size; i++)
				if (Head->getX() == Duoi[i]->getX() && Head->getY() == Duoi[i]->getY())
				{
					
					test = false;
					delete Head;
					delete Food;
					for (int i = 0; i < size; i++)
					{
						delete Duoi[i];
					}
					delete Duoi;
					
					break;
					

				}
		}
	}
	delete p;
	Dead();
}

void Snake::Dead()
{
	system("cls");
	TakeColor(2);
	_Common::gotoXY(31, 11);

	cout << "DEAD";

	TakeColor(4);
	_Common::gotoXY(31, 12);
	cout << "RESTART";

	TakeColor(3);
	_Common::gotoXY(31, 13);
	cout << "EXIT";


	_Common::gotoXY(30, 12);
	TakeColor(4);
	cout << ">";


	char c;
	bool test = true; bool a=true;
	while (test)
	{
		switch (c = _getch())
		{
		case 's':

			TakeColor(3);
			_Common::gotoXY(31, 12);
			cout << "RESTART";

			_Common::gotoXY(30, 12);
			cout << " ";

			TakeColor(4);
			_Common::gotoXY(31, 13);
			cout << "EXIT";
			_Common::gotoXY(30, 13);
			cout << ">";

			a = false;

			break;


		case 'w':
			TakeColor(4);
			_Common::gotoXY(31, 12);
			cout << "RESTART";

			_Common::gotoXY(30, 12);
			cout << ">";
			TakeColor(3);
			_Common::gotoXY(31, 13);
			cout << "EXIT";
			_Common::gotoXY(30, 13);
			cout << " ";
			a = true;
			break;

		case 13:
			system("cls");
			test = false;
			if (a)
			{
				Head = new Point(32, 12);
				Head->SetC('@');
				score[0] = '0';
				score[1] = '0';
				score[2] = '0';
				Duoi = new Point*[4];
				*Duoi = new Point(32, 12);
				Duoi[1] = new Point(31, 12);
				Duoi[2] = new Point(30, 12);
				Duoi[3] = new Point(29, 12);
				Food = new Point;
				TakeFood();
				size = 4;
			}
			else exit(1);
			break;
		}
	}
	TakeColor(4);
	draw();
	Move();
}