#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
}


Game::~Game()
{
}


float Game::getChips()
{
	return playerChips;
}

float Game::setChips(float Chips)
{
	playerChips = playerChips + Chips;
	return playerChips;
}

void Game::determineOutcome(int playerPoints, int dealerPoints, bool playerBust, bool dealerBust, bool dealerBlackjack, bool insurance, float bet)
{
	if (dealerBlackjack == true)
	{
		cout << "YOU LOSE" << endl;
		if (insurance = true)
		{
			cout << "However, You receive your insurance bet!" << endl;
			playerChips = playerChips + bet / 2;
		}
	}
	else if (playerBust == true)
	{
		cout << "YOU LOSE" << endl;
	}
	else if (dealerBust == true)
	{
		cout << "YOU WIN" << endl;
		playerChips = playerChips + bet * 2;
	}
	else if (playerPoints > dealerPoints)
	{
		cout << "YOU WIN" << endl;
		playerChips = playerChips + bet * 2;
	}
	else if (playerPoints < dealerPoints)
	{
		cout << "YOU LOSE" << endl;
	}
	else if (playerPoints == dealerPoints)
	{
		cout << "YOU LOSE" << endl;
	}
}