#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace std;

Player::Player()
{
}


Player::~Player()
{
}

void Player::playerBet(float Bet)
{
	betTotal = Bet;
}

float Player::getPlayerBet()
{
	return betTotal;
}

void Player::setPointTotal(int points)
{
	playerPointTotal = points;

}

int Player::getPointTotal()
{
	return playerPointTotal;
}

void Player::playerHit(Deck &d)
{
	cout << "You Hit! It is a..." << endl;
	d.getCard();
	int hitCard = getCardValue();
	d.removeCard();
	playerPointTotal = playerPointTotal + hitCard;
	cout << "You are now at " << playerPointTotal << " Points." << endl;

	if (playerPointTotal > 21)
	{
		cout << "YOU BUST!" << endl;
	}


}

void Player::playerStand()
{
	cout << "You Stand at " << playerPointTotal << " Points." << endl;
}

void Player::playerDD(Deck &d)
{
	betTotal *= 2;
	cout << "You Double Down! It is a.." << endl;
	d.getCard();
	int DDcard = getCardValue();
	d.removeCard();
	playerPointTotal = playerPointTotal + DDcard;
	cout << "You are now at " << playerPointTotal << " Points." << endl;

	if (playerPointTotal > 21)
	{
		cout << "YOU BUST!" << endl;
	}
}

void Player::playerSurrender()
{
	betTotal /= 2;
	cout << "You surrendered you hand, and recieved half your bet." << endl;

}