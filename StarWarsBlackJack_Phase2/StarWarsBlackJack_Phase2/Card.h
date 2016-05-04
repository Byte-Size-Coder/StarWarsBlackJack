#pragma once
#include <iostream>

using namespace std;

const int suitMax(4);
const int faceValueMax(13);
const int cardValueMax(13);

class Card
{
	friend class Deck;
public:
	explicit Card();
	explicit Card(const int &suit, const int &rank, const int &card);

	string cardToString() const;
	int cardToValue() const;
	string cardToFace() const;

private:
	int setSuit();
	int setFaceValue();
	int setCardValue();
	int getSuit() const;
	int getFaceValue() const;
	int getCardValue() const;
	int c_suit;
	int c_faceValue;
	int c_cardValue;
};