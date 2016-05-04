#include "Card.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

string suit[suitMax] = { "Hearts", "Diamonds", "Clubs", "Spades" };
string faceValue[faceValueMax] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
int cardValue[cardValueMax] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
int cardRow[rowMax] = { 0, 1, 2, 3};
int cardFrame[frameMax] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };


Card::Card()
{
	c_suit = setSuit();
	c_faceValue = setFaceValue();
	c_cardValue = setCardValue();
	c_row = setRow();
	c_frame = setFrame();	
}


Card::Card(const int &suit, const int &faceValue, const int &cardValue, const int &rowValue, const int &frameValue) : c_suit(suit), c_faceValue(faceValue), c_cardValue(cardValue), c_row(rowValue), c_frame(frameValue)
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

int Card::setRow()
{
	return rand() % (rowMax - 1) + 0;
}

int Card::setFrame()
{
	return rand() % (frameMax - 1) + 0;
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

int Card::cardToRow() const
{
	return cardRow[getRow()];
}

int Card::cardToFrame() const
{
	return cardFrame[getFrame()];
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

int Card::getRow() const
{
	return c_row;
}

int Card::getFrame() const
{
	return c_frame;
}