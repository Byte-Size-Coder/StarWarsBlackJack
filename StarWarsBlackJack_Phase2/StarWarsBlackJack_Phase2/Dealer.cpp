#include "Dealer.h"


Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

void Dealer::dealerTurn(Deck &d)
{
	cout << "The Dealer's second card is a.." << endl;
	d.getCard();
	int dealer2Card = d.getCardValue();
	d.removeCard();
	dealerTotalPoints = dealerTotalPoints + dealer2Card;
	cout << "The Dealer is at " << dealerTotalPoints << " Points." << endl;

	if (dealerTotalPoints == 21)
	{
		cout << "Dealer Has BlackJack!" << endl;
		setBlackJack();
	}

	while (dealerTotalPoints < 17)
	{
		cout << "The Dealer Hits, It is a.." << endl;
		d.getCard();
		int dealerHitCard = d.getCardValue();
		d.removeCard();
		dealerTotalPoints = dealerTotalPoints + dealerHitCard;
		cout << "The Dealer is at " << dealerTotalPoints << " Points." << endl;
	}
	if (dealerTotalPoints > 21)
	{
		cout << "Dealer Bust!" << endl;
	}
	else
	{
		cout << "Dealer Stands at " << dealerTotalPoints << " Points." << endl;
	}

}

void Dealer::setDealerPoints(int point)
{
	dealerTotalPoints = dealerTotalPoints + point;

}

int Dealer::getDealerPoints()
{
	return dealerTotalPoints;
}

void Dealer::setInsurance()
{
	insurance = true;
}


bool Dealer::getInsurance()
{
	return insurance;
}

void Dealer::insuranceCheck(string dealCard)
{
	if (dealCard == "Ace")
	{
		char insDec;
		cout << "Dealer has Ace, would you like to place insurance? (y/n)" << endl;
		cin >> insDec;
		if (insDec == 'y')
		{
			setInsurance();
			cout << "You have placed insurance." << endl;
		}
		else
		{
			cout << "You did not place insurance." << endl;
		}
	}
	else
		cout << "No insurance available." << endl;
}

void Dealer::setBlackJack()
{
	blackJack = true;
}

bool Dealer::getBlackJack()
{
	return blackJack;
}