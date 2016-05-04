#pragma once
#include <iostream>
#include "Sprite.h"

using namespace std;

const int suitMax(4);
const int faceValueMax(13);
const int cardValueMax(13);
const int rowMax(4);
const int frameMax(13);

class Card 
{
	friend class Deck;
public:
	explicit Card();
	explicit Card(const int &suit, const int &rank, const int &card, const int &row, const int &frame);

	string cardToString() const;
	int cardToValue() const;
	int cardToRow() const;
	int cardToFrame() const; 
	string cardToFace() const;

private:
	int setSuit();
	int setFaceValue();
	int setCardValue();
	int setRow();
	int setFrame();
	int getSuit() const;
	int getFaceValue() const;
	int getCardValue() const;
	int getRow() const;
	int getFrame() const;
	int c_suit;
	int c_faceValue;
	int c_cardValue;
	int c_row;
	int c_frame;
};

