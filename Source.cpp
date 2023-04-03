#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int AskForReplay();

int main()
{
	int bet, random, cards, ocards, money, replay;

	money = 1000;

	replay = 1;

	while (replay) {
		cout << "Money: " << money << '\n';

		cout << "Bet: ";
		cin >> bet;

		srand(time(NULL));

		cards = rand() % 10 + 1;

		cout << "You have: " << cards << '\n';

		ocards = rand() % 10 + 1;
		cout << "Opponent has: " << ocards << '\n';

		char move;

		while (cards < 21 && ocards < 21) {
			cout << "Press 'h' to hit or 's' to stand\n";
			cin >> move;
			if (move == 'h')
			{
				random = rand() % 10 + 1;

				cards += random;
			}
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
			cout << "You lose!";
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
			cout << "You win!";
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