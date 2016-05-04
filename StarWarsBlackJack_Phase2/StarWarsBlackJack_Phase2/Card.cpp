#include "Card.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

string suit[suitMax] = { "Diamonds", "Spades", "Hearts", "Clubs" };
string faceValue[faceValueMax] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
int cardValue[cardValueMax] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

Card::Card()
{
	c_suit = setSuit();
	c_faceValue = setFaceValue();
	c_cardValue = setCardValue();
}


Card::Card(const int &suit, const int &faceValue, const int &cardValue) : c_suit(suit), c_faceValue(faceValue), c_cardValue(cardValue)
{


}

int Card::setSuit()
{
	return rand() % (suitMax - 1) + 0;
}

int Card::setFaceValue()
{
	return rand() % (faceValueMax - 1) + 0;
}

int Card::setCardValue()
{
	return rand() % (cardValueMax - 1) + 0;
}

string Card::cardToString() const
{
	return faceValue[getFaceValue()] + " of " + suit[getSuit()];
}

string Card::cardToFace() const
{
	return faceValue[getFaceValue()];
}

int Card::cardToValue() const
{
	return cardValue[getCardValue()];
}

int Card::getSuit() const
{
	return c_suit;
}

int Card::getFaceValue() const
{
	return c_faceValue;
}

int Card::getCardValue() const
{
	return c_cardValue;
}