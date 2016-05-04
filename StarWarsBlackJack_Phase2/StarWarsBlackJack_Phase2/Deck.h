#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Card.h"

using namespace std;

class Deck
{
public:
	explicit Deck();
	void printDeck() const;
	void getCard();
	int getCardValue();
	string getFaceValue();
	void removeCard();
	void shuffle();

private:
	vector<Card> theDeck;
};
