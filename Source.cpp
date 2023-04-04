#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

int AskForReplay();
void clearscreen(char fill);

int main()
{
	int bet, random, cards, ocards, money, replay;

	money = 1000;

	replay = 1;

	while (replay) {
		cout << "Money: " << money << '\n';

		system("color 05");
		cout << "Bet: ";
		cin >> bet;

		srand(time(NULL));

		cards = rand() % 10 + 1;

		cout << "You have: " << cards << '\n';

		ocards = rand() % 10 + 1;
		cout << "Opponent has: " << ocards << '\n';

		char move;

		while (cards < 21 && ocards < 21) {
			system("color 06");
			cout << "Press 'h' to hit or 's' to stand\n";
			cin >> move;
			if (move == 'h')
			{
				random = rand() % 10 + 1;

				cards += random;
			}
			clearscreen(' ');
			cout << "You have: " << cards << '\n';
			random = rand() % 1;
			cout << "Opponent has chosen: ";
			if (random == 0)
			{
				cout << "Hit!" << '\n';
				random = rand() % 10 + 1;

				ocards += random;
			}
			else
			{
				cout << "Stand! " << '\n';
			}
			cout << "Opponent has: " << ocards << '\n';
		}

		if ((ocards == 21 && cards != 21 || cards > ocards && cards < 21 || cards > 21) && cards != ocards)
		{
			system("color 40");
			cout << "You lose!\n";
			money -= bet;
			if (money > 0)
				replay = AskForReplay();
			else {
				cout << "You are IN DEBT! Game Over!\n";
				return 0;
			}
		}
		else if ((cards == 21 && ocards != 21 || cards > ocards && cards < 21 || ocards > 21) && cards != ocards)
		{
			system("color 20");
			cout << "You win!\n";
			money += bet;
			replay = AskForReplay();
		}
		else
		{
			cout << "Tie!";
		}
	}
}

int AskForReplay()
{
	int r;
	char a;
	cout << "Do you want to replay? (y/n)\n";
	cin >> a;
	if (a == 'y')
	{
		r = 1;
	}
	else
	{
		r = 0;
	}
	return r;
}

void clearscreen(char fill)
{
	COORD tl = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}
