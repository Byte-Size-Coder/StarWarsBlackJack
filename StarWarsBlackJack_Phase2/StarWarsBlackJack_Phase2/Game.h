#pragma once
class Game
{
	float playerChips = 500;

public:
	Game();
	~Game();
	float setChips(float Chips);
	float getChips();
	void determineOutcome(int playerPoints, int dealerPoints, bool playerBust, bool dealerBust, bool dealerBlackJack, bool insurance, float bet);
};