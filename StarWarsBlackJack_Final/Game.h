#pragma once
class Game
{
public:
	Game();
	~Game();

	int GameStart();
	void determineOutcome(int playerPoints, int dealerPoints, bool playerBust, bool dealerBust, bool dealerBlackJack, int bet, int &playerChips, bool playerSurrender, int &won);
};

