#pragma once
#include"Game.h"
#include "Deck.h"
class Player : public Deck
{
	float betTotal = 0;
	int playerPointTotal;

public:
	Player();
	~Player();
	void playerBet(float Bet);
	float getPlayerBet();
	void setPointTotal(int points);
	int getPointTotal();
	void playerHit(Deck &d);
	void playerStand();
	void playerDD(Deck &d);
	void playerSurrender();
};