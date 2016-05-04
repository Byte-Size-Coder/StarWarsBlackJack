#include "Deck.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



Deck::Deck()
{
	for (unsigned int i = 0; i < suitMax; ++i)
	{
		for (unsigned int j = 0; j < faceValueMax; ++j)
		{
			Card card(i, j, j, i, j);
			theDeck.push_back(card);
		}
	}
}

void Deck::printDeck() const
{
	unsigned int count = 1;

	for (unsigned int i = 0; i < theDeck.size(); ++i)
	{
		cout << theDeck[i].cardToString() << endl;
		cout << theDeck[i].cardToValue() << endl;

		if (count == 13)
		{
			cout << endl;
			count = 0;
		}
		++count;
	}
}

void Deck::getCard()
{
	Card cd(theDeck.back().getSuit(), theDeck.back().getFaceValue(), theDeck.back().getCardValue(), theDeck.back().getRow(), theDeck.back().getFrame());
	cout << cd.cardToString() << endl;

}

int Deck::getCardValue()
{
	Card cd(theDeck.back().getSuit(), theDeck.back().getFaceValue(), theDeck.back().getCardValue(), theDeck.back().getRow(), theDeck.back().getFrame());
	return cd.cardToValue();
}

int Deck::getRowValue()
{
	Card cd(theDeck.back().getSuit(), theDeck.back().getFaceValue(), theDeck.back().getCardValue(), theDeck.back().getRow(), theDeck.back().getFrame());
	return cd.cardToRow();
}

int Deck::getFrameValue()
{
	Card cd(theDeck.back().getSuit(), theDeck.back().getFaceValue(), theDeck.back().getCardValue(), theDeck.back().getRow(), theDeck.back().getFrame());
	return cd.cardToFrame();
}

string Deck::getFaceValue()
{
	Card cd(theDeck.back().getSuit(), theDeck.back().getFaceValue(), theDeck.back().getCardValue(), theDeck.back().getRow(), theDeck.back().getFrame());
	return cd.cardToFace();
}

void Deck::removeCard()
{
	theDeck.pop_back();
}


void Deck::shuffle()
{
	random_shuffle(theDeck.begin(), theDeck.end());
}
