#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"



void main()
{

	Game g;
	bool gameContinue = true;

	while (gameContinue == true)
	{
		cout << "Welcome to Black Jack!" << endl;
		cout << "You have $" << g.getChips() << " in chips." << endl;

		srand(time(NULL));
		cout << "How much would you like to bet?" << endl;

		float Bet;
		Player P;
		Dealer D;

		cin >> Bet;
		P.playerBet(Bet);
		g.setChips(-Bet);
		cout << "You Bet $" << Bet << endl;
		cout << "Your Chips: $" << g.getChips() << endl;



		Deck _deck;
		_deck.shuffle();

		cout << "The cards have been dealt, you got..." << endl;

		_deck.getCard();

		int playerCard1 = _deck.getCardValue();
		string playerFace1 = _deck.getFaceValue();

		_deck.removeCard();

		cout << "AND" << endl;

		_deck.getCard();

		int playerCard2 = _deck.getCardValue();
		string playerFace2 = _deck.getFaceValue();

		_deck.removeCard();


		cout << '\n';

		cout << "The Dealer has..." << endl;

		_deck.getCard();

		int dealerCard1 = _deck.getCardValue();
		string dealerFace1 = _deck.getFaceValue();

		_deck.removeCard();

		cout << "AND" << endl;

		cout << "????" << endl;

		int totalDealerPoints = dealerCard1;
		int totalPlayerPoints = playerCard1 + playerCard2;

		D.setDealerPoints(totalDealerPoints);
		P.setPointTotal(totalPlayerPoints);

		bool insurance = false;
		D.insuranceCheck(dealerFace1);
		insurance = D.getInsurance();

		if (insurance == true)
		{
			g.setChips(-(Bet / 2));
			cout << "You now have $" << g.getChips() << endl;
		}

		bool playerTurn = true;
		bool playerBust = false;
		char playerDecision;
		cout << "You have " << totalPlayerPoints << " Points. What is your move?" << endl;
		cout << "Hit (h) Stand (s) Double Down (d) Surrender (u)" << endl;
		cin >> playerDecision;
		while (playerTurn == true)
		{
			if (playerDecision == 'h')
			{
				P.playerHit(_deck);
				totalPlayerPoints = P.getPointTotal();
				if (totalPlayerPoints > 21)
				{
					playerTurn = false;
					playerBust = true;
				}
				else
				{
					cout << "You have " << totalPlayerPoints << " Points. What is your move?" << endl;
					cout << "Hit (h) Stand (s)" << endl;
					cin >> playerDecision;
				}
			}
			else if (playerDecision == 's')
			{
				P.playerStand();
				totalPlayerPoints = P.getPointTotal();
				playerTurn = false;
			}
			else if (playerDecision == 'd')
			{
				P.playerDD(_deck);
				totalPlayerPoints = P.getPointTotal();
				cout << "You have " << totalPlayerPoints << " Points." << endl;
				playerTurn = false;
			}
			else if (playerDecision == 'u')
			{
				P.playerSurrender();
				playerTurn = false;
			}
			else
			{
				cout << "invalid Key" << endl;
				cout << "Hit (h) Stand (s) Double Down (d) Surrender (u)" << endl;
				cin >> playerDecision;

			}

		}

		bool dealerBlackJack = false;
		bool dealerBust = false;
		D.dealerTurn(_deck);
		totalDealerPoints = D.getDealerPoints();
		dealerBlackJack = D.getBlackJack();
		if (totalDealerPoints > 21)
		{
			dealerBust = true;
		}

		g.determineOutcome(totalPlayerPoints, totalDealerPoints, playerBust, dealerBust, dealerBlackJack, insurance, Bet);

		cout << "You are now at $" << g.getChips() << endl;

		char gameContinueDecision;
		cout << "Would you like to continue to play? or cashout?" << endl;
		cout << "'y' to continue, 'n' to cashout" << endl;
		cin >> gameContinueDecision;


		if (gameContinueDecision == 'n')
		{
			gameContinue = false;
		}

		system("CLS");
	}

	cout << "Cashed out, you have $" << g.getChips() << endl;

	system("pause");
};