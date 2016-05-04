
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct card
{
	int point;
	string suit;
	string faceValue;
};

int point[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
string suit[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
string faceValue[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

void swap(int *a, int *b);

void randomize(struct card c[], int n);

void setCards(struct card c[]);

void main()
{
	bool gameContinue = true;
	float playerChips = 500;
	float playerBet = 0;
	bool playerBust = false;
	bool playerSplit1Bust;
	bool playerSplit2Bust;
	bool dealerBust = false;
	bool dealerBlackJack = false;

	cout << "WELCOME TO BLACK JACK" << endl;
	cout << '\n';

	while (gameContinue == true)
	{
		float insuranceBet;
		bool surrender;
		bool insurance;
		bool playerTurn = true;

		cout << "You have $" << playerChips << endl;
		cout << '\n';
		cout << "How much you want to bet" << endl;
		cout << "(Enter your bet)" << endl;
		cin >> playerBet;

		if (playerBet > playerChips)
		{
			playerBet = 0;
			cout << "You bet more then what you have, bet again." << endl;
			cin >> playerBet;
		}

		playerChips = playerChips - playerBet;

		int cardCount = 5;
		int playerPoint1;
		int playerPoint2;
		int playerPoint1Ace = 0;
		int playerPoint2Ace = 0;
		int hitCardPointAce = 0;

		bool playerAceRule = false;
		bool playerSplit1AceRule = false;
		bool playerSplit2AceRule = false;
		bool dealerAceRule = false;
		bool doubleDown = false;

		int dealerPoint1;
		int dealerPoint2;
		int dealerPoint1Ace = 0;
		int dealerPoint2Ace = 0;
		int dealerHitPointAce = 0;

		card c[52];

		setCards(c);
		randomize(c, 52);

		playerPoint1 = c[0].point;
		playerPoint2 = c[2].point;

		dealerPoint1 = c[1].point;
		dealerPoint2 = c[3].point;

		cout << "Player has " << endl;
		cout << c[0].faceValue << " of " << c[0].suit << endl;
		cout << "AND" << endl;
		cout << c[2].faceValue << " of " << c[2].suit << endl;
		cout << "\n";
		cout << "Dealer has " << endl;
		cout << c[1].faceValue << " of " << c[1].suit << endl;
		cout << "AND" << endl;
		cout << "????" << endl;
		cout << "\n";

		if (playerPoint1 == 11)
		{
			playerPoint1Ace = 1;
			playerAceRule = true;
			playerSplit1AceRule = true;
		}

		if (playerPoint2 == 11)
		{
			playerPoint2Ace = 1;
			playerAceRule = true;
			playerSplit2AceRule = true;
		}

		if (dealerPoint1 == 11)
		{
			dealerPoint1Ace = 1;
			dealerAceRule = true;
		}

		if (dealerPoint2 == 11)
		{
			dealerPoint2Ace = 1;
			dealerAceRule = true;
		}

		if (dealerPoint1 == 11)
		{
			char insuranceDecision;
			cout << "Dealer offers insurance, Would you like Insurance?" << endl;
			cout << "Enter (y/n)" << endl;
			cin >> insuranceDecision;

			if (insuranceDecision == 'y')
			{
				insurance = true;
				insuranceBet = playerBet / 2;
			}
			else
			{
				insurance = false;
			}
		}

		

		int totalPlayerPoints = playerPoint1 + playerPoint2;
		int totalDealerPoints = dealerPoint1 + dealerPoint2;

		char playerMove;

		cout << "\n";

	
		cout << "You have " << totalPlayerPoints << " Points" << endl;
		cout << "what is your move? (Hit = h / Stand = s / Double Down = d / Surrender = u) " << endl;
		cin >> playerMove;
		

		while (playerTurn == true)
		{
			playerBust = false;
			playerSplit1Bust;
			playerSplit2Bust;
			dealerBust = false;
			dealerBlackJack = false;

			if (playerMove == 's')
			{
				cout << "You stand at " << totalPlayerPoints << " points" << endl;
				playerTurn = false;
			}
			else if (playerMove == 'h')
			{
				int hitCardPoint = c[cardCount].point;

				if (hitCardPoint == 11)
				{
					hitCardPointAce = 1;
					playerAceRule = true;
				}

				cout << "YOU HIT" << endl;
				cout << "It is a " << c[cardCount].faceValue << " of " << c[cardCount].suit << endl;

				totalPlayerPoints = totalPlayerPoints + hitCardPoint;

				cout << "You have " << totalPlayerPoints << endl;

				cardCount++;

				if (totalPlayerPoints > 21)
				{
					if (playerAceRule == true)
					{

						if (playerPoint1Ace == 1)
						{
							totalPlayerPoints = totalPlayerPoints - playerPoint1 + playerPoint1Ace;
							cout << "Your total is now " << totalPlayerPoints << " with ace = 1" << endl;
							cout << "what is your move? (Hit = h / Stand = s) " << endl;
							cin >> playerMove;
							playerAceRule = false;
						}

						if (playerPoint2Ace == 1)
						{
							totalPlayerPoints = totalPlayerPoints - playerPoint2 + playerPoint2Ace;
							cout << "Your total is now " << totalPlayerPoints << " with ace = 1" << endl;
							cout << "what is your move? (Hit = h / Stand = s) " << endl;
							cin >> playerMove;
							playerAceRule = false;
						}

						if (hitCardPointAce == 1)
						{
							totalPlayerPoints = totalPlayerPoints - hitCardPoint + hitCardPointAce;
							cout << "Your total is now " << totalPlayerPoints << " with ace = 1" << endl;
							cout << "what is your move? (Hit = h / Stand = s) " << endl;
							cin >> playerMove;
							playerAceRule = false;
						}

						if (totalPlayerPoints > 21)
						{
							cout << "IT IS A BUST!" << endl;
							playerTurn = false;
							playerBust = true;
						}
					}
					else
					{
						cout << "IT IS A BUST!" << endl;
						playerTurn = false;
						playerBust = true;
					}
				}
				else
				{
					cout << "what is your move? (Hit = h / Stand = s) " << endl;
					cin >> playerMove;
				}
			}
			else if (playerMove == 'd')
			{
				int doubleDownPoint = c[cardCount].point;

				cout << "DOUBLE DOWN" << endl;
				cout << "It is a " << c[cardCount].faceValue << " of " << c[cardCount].suit << endl;

				playerChips = playerChips - playerBet;

				totalPlayerPoints = totalPlayerPoints + doubleDownPoint;

				cout << "You double down with " << totalPlayerPoints << endl;

				doubleDown = true;

				if (totalPlayerPoints > 21)
				{
					cout << "IT IS A BUST!" << endl;
					playerTurn = false;
					playerBust = true;

				}
				else
				{
					playerTurn = false;
				}
			}
			else if (playerMove == 'u')
			{
				surrender = true;
				playerTurn = false;
			}
		}

		cout << "Dealer's second card is " << c[3].faceValue << " of " << c[3].suit << endl;


		if (totalDealerPoints == 21)
		{
			cout << "DEALER HAS BLACKJACK" << endl;
			dealerBlackJack = true;
		}
		else
		{
			cout << "Dealer is at " << totalDealerPoints << " point" << endl;
		}

		while (totalDealerPoints < 17)
		{
			int dealerHitPoint = c[cardCount].point;

			if (dealerHitPoint == 11)
			{
				dealerHitPointAce = 1;
				dealerAceRule = true;
			}

			cout << "DEALER HITS" << endl;
			cout << "It is a " << c[cardCount].faceValue << " of " << c[cardCount].suit << endl;

			totalDealerPoints = totalDealerPoints + dealerHitPoint;

			if (totalDealerPoints > 21)
			{
				if (dealerAceRule == true)
				{
					if (dealerPoint1Ace == 1)
					{
						totalDealerPoints = totalDealerPoints - dealerPoint1 + dealerPoint1Ace;
						cout << "Dealer has  " << totalDealerPoints << " with ace = 1" << endl;
					}

					if (dealerPoint2Ace == 1)
					{
						totalDealerPoints = totalDealerPoints - dealerPoint2 + dealerPoint2Ace;
						cout << "Dealer has  " << totalDealerPoints << " with ace = 1" << endl;
					}

					if (dealerHitPointAce == 1)
					{
						totalDealerPoints = totalDealerPoints - dealerHitPoint + dealerHitPointAce;
						cout << "Dealer has  " << totalDealerPoints << " with ace = 1" << endl;
					}
				}
				else
				{
					cout << "DEALER BUST" << endl;
					dealerBust = true;
				}
			}
			else
			{
				cout << "Dealer Has " << totalDealerPoints << endl;
			}
			cardCount++;
		}


		if (dealerBlackJack == true)
		{
			cout << "YOU LOSE" << endl;
			cout << '\n';

			if (insurance == true)
			{
				cout << "However, You won your Insurance!" << endl;
				playerChips = playerChips + insuranceBet;
			}

			cout << "You now have $" << playerChips << endl;
		}
		if (surrender == true)
		{
			cout << "You surrendered and recieve half your bet back" << endl;
			playerChips = playerChips + (playerBet / 2);
			cout << '\n';
			cout << "You now have $" << playerChips << endl;
			surrender = false;
		}
		else if (playerBust == true || totalDealerPoints == totalPlayerPoints)
		{
			cout << "YOU LOSE" << endl;
			cout << '\n';
			cout << "You now have $" << playerChips << endl;
		}
		else if (totalDealerPoints > totalPlayerPoints && dealerBust == false)
		{
			cout << "YOU LOSE" << endl;
			cout << '\n';
			cout << "You now have $" << playerChips << endl;
		}
		else if (totalPlayerPoints > totalDealerPoints && playerBust == false)
		{
			cout << "YOU WIN" << endl;

			if (doubleDown = true)
			{
				playerChips = playerChips + (playerBet * 4);
			}
			else
			{
				playerChips = playerChips + (playerBet * 2);
			}

			cout << '\n';
			cout << "You now have $" << playerChips << endl;
		}
		else if (playerBust == false && dealerBust == true)
		{
			cout << "YOU WIN" << endl;

			if (doubleDown = true)
			{
				playerChips = playerChips + (playerBet * 4);
			}
			else
			{
				playerChips = playerChips + (playerBet * 2);
			}

			cout << '\n';
			cout << "You now have $" << playerChips << endl;
		}
		

		if (playerChips <= 0)
		{
			cout << "YOU HAVE NO CHIPS TO PLAY" << endl;
			gameContinue = false;
		}


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

	cout << "Cashed out, you have $" << playerChips << endl;

	system("pause");
} // End of Main


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void randomize(struct card c[], int n)
{
	srand(time(NULL));

	for (int i = n - 1; i > 0; i--)
	{

		int j = rand() % (i + 1);


		swap(c[i], c[j]);
	}
}

void setCards(struct card c[])
{
	int s = 0;
	int v = 0;

	for (int i = 0; i <= 51; i++)
	{

		c[i].point = point[i % 13];
		c[i].faceValue = faceValue[i % 13];
		c[i].suit = suit[s];

		if (v >= 12 && s < 4)
		{
			v = 0;
			s++;
		}
		else
			v++;
	}
}