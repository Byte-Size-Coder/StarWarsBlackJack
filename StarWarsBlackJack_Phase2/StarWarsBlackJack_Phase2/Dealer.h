#pragma once
#include "Deck.h"
class Dealer : public Deck
{
	int dealerTotalPoints = 0;
	bool insurance = false;
	bool blackJack = false;

public:
	Dealer();
	~Dealer();
	void dealerTurn(Deck &d);
	void setDealerPoints(int point);
	int getDealerPoints();
	bool getInsurance();
	void setInsurance();
	void insuranceCheck(string dealCard);
	void setBlackJack();
	bool getBlackJack();
};