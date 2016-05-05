#include "Game.h"
#include "Definitions.h"
#include "Sprite.h"
#include "Deck.h"
#include "Player.h"
#include <Windows.h>
#include <SDL.h>
#include <iostream>
#include <time.h>


using namespace std;

Game::Game()
{
}


Game::~Game()
{
}

int Game::GameStart()
{
	bool end = false;
	bool gameContinue = true;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool playStart = true;
	int playerChips = 500;

	SDL_Event event;

	int deltaTime = 75;
	int updatedTime = 0;

	Sprite *startTitle = NULL;
	Sprite *startButton = NULL;

	Sprite *Background = NULL;
	Sprite *Table = NULL;
	Sprite *StarWars = NULL;
	Sprite *Empire = NULL;
	Sprite *Rebels = NULL;
	Sprite *Avatar = NULL;

	Sprite *Deal = NULL;

	Sprite *Bet1 = NULL;
	Sprite *Bet5 = NULL;
	Sprite *Bet10 = NULL;
	Sprite *Bet25 = NULL;
	Sprite *Bet50 = NULL;
	Sprite *Bet100 = NULL;
	Sprite *cashOutB = NULL;

	Sprite *Chips = NULL;

	Sprite *Hit = NULL;
	Sprite *Stand = NULL;
	Sprite *DoubleDown = NULL;
	Sprite *Surrender = NULL;



	Sprite *Card1 = NULL;
	Sprite *Card2 = NULL;
	Sprite *hitCard1 = NULL;
	Sprite *hitCard2 = NULL;
	Sprite *hitCard3 = NULL;
	Sprite *hitCard4 = NULL;
	Sprite *dCard = NULL;
	Sprite *dCard2Back = NULL;
	Sprite *dCard2 = NULL;
	Sprite *dHitCard1 = NULL;
	Sprite *dHitCard2 = NULL;
	Sprite *dHitCard3 = NULL;
	Sprite *dHitCard4 = NULL;

	Sprite *contin = NULL;
	Sprite *win = NULL;
	Sprite *lose = NULL;
	

	Sprite*cashOut = NULL;
	Sprite*exitBut = NULL;

	Sprite *Deck1 = NULL;
	

	SDL_Color color = { 255, 255, 18 };
	SDL_Rect dest = { 1262, 800 };
	SDL_Rect dest1 = { 690, 700 };
	SDL_Rect dest2 = { 690, 250 };
	SDL_Rect dest3 = { 950, 0 };
	SDL_Rect dest4 = { 690, 600 };
	SDL_Surface *text = NULL;
	SDL_Texture *playerCredits = NULL;
	SDL_Texture *playerPoints = NULL;
	SDL_Texture *dealerPoints = NULL;
	SDL_Texture *cashoutCredits = NULL;
	SDL_Texture *betText = NULL;
	
	TTF_Font *font = NULL;
	TTF_Font *font1 = NULL;


	Mix_Music *ThemeSong = NULL;
	Mix_Music *CantinaSong = NULL;
	

	Mix_Chunk *DealSnd = NULL;
	Mix_Chunk *BetSnd = NULL;
	Mix_Chunk *HitSnd = NULL;
	Mix_Chunk *PWin = NULL;
	Mix_Chunk *PLose = NULL;
	
	

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		cout << "SDL_Init error: " << SDL_GetError() << endl;
		return 1;
	}
	atexit(SDL_Quit);

	window = SDL_CreateWindow("BlackJack", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		return 1;
	}

	if (TTF_Init() < 0)
	{
		cerr << "TTF_Init Error: " << TTF_GetError() << endl;
		return 1;
	}
	atexit(TTF_Quit);

	if (Mix_OpenAudio(AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS))
	{
		cerr << "Mix_OpenAudio Error: " << Mix_GetError() << endl;
		return 1;
	}
	atexit(Mix_CloseAudio);

	startTitle = new Sprite("Images/StartTitle.png", 0, 0, 1400, 960, renderer, true);
	startButton = new Sprite("Images/StartGame.png", 600, 700, 235, 235, renderer, true);
	
	while (gameContinue == true)
	{

	


	Background = new Sprite("Images/Background.jpg", 0, 0, 1920, 1080, renderer, true);
	Table = new Sprite("Images/BlackJack_Table.png", 65, 0, 1312, 901, renderer, true);
	StarWars = new Sprite("Images/StarWars.png", 600, 300, 208, 100, renderer, true);
	Empire = new Sprite("Images/StarWars_Empire.png", 900, 200, 150, 150, renderer, true);
	Rebels = new Sprite("Images/StarWars_Rebels.png", 350, 200, 150, 150, renderer, true);
	Avatar = new Sprite("Images/Avatar.png", 1200, 650, 200, 300, renderer, true);

	Deal = new Sprite("Images/StarWars_ER.png",605, 650, 200, 200, renderer, true);

	Bet1 = new Sprite("Images/Bet_1.png", 240, 50, 100, 100, renderer, true);
	Bet5 = new Sprite("Images/Bet_5.png", 390, 50, 100, 100, renderer, true);
	Bet10 = new Sprite("Images/Bet_10.png", 540, 50, 100, 100, renderer, true);
	Bet25 = new Sprite("Images/Bet_25.png", 740, 50, 100, 100, renderer, true);
	Bet50 = new Sprite("Images/Bet_50.png",  890, 50, 100, 100, renderer, true);
	Bet100 = new Sprite("Images/Bet_100.png", 1040, 50, 100, 100, renderer, true);
	cashOutB = new Sprite("Images/CashOut.png", 1250, 50, 150, 150, renderer, true);

	Chips = new Sprite("Images/Chips.png", 695, 550, 25, 32, renderer, false);

	Hit = new Sprite("Images/Hit.png", 525, 800, 150, 150, renderer, false);
	Stand = new Sprite("Images/Stand.png", 725, 800, 150, 150, renderer, false);
	DoubleDown = new Sprite("Images/DoubleDown.png", 325, 800, 150, 150, renderer, false);
	Surrender = new Sprite("Images/Surrender.png", 925, 800, 150, 150, renderer, false);

	Card1 = new Sprite("Images/Card.png", 660, 650, 44, 63, renderer, false);
	Card2 = new Sprite("Images/Card.png", 710, 650, 44, 63, renderer, false);
	hitCard1 = new Sprite("Images/Card.png", 770, 650, 44, 63, renderer, false);
	hitCard2 = new Sprite("Images/Card.png", 820, 650, 44, 63, renderer, false);
	hitCard3 = new Sprite("Images/Card.png", 870, 650, 44, 63, renderer, false);
	hitCard4 = new Sprite("Images/Card.png", 920, 650, 44, 63, renderer, false);
	dCard = new Sprite("Images/Card.png", 660, 200, 44, 63, renderer, false);
	dCard2Back = new Sprite("Images/Card.png", 710, 200, 44, 63, renderer, false);
	dCard2 = new Sprite("Images/Card.png", 710, 200, 44, 63, renderer, false);
	dHitCard1 = new Sprite("Images/Card.png", 770, 200, 44, 63, renderer, false);
	dHitCard2 = new Sprite("Images/Card.png", 820, 200, 44, 63, renderer, false);
	dHitCard3 = new Sprite("Images/Card.png", 870, 200, 44, 63, renderer, false);
	dHitCard4 = new Sprite("Images/Card.png", 920, 200, 44, 63, renderer, false);

	contin = new Sprite("Images/continue.png", 550, 500, 300, 75, renderer, false);
	win = new Sprite("Images/Win.png", 500, 300, 400, 300, renderer, false);
	lose = new Sprite("Images/Lose.png", 500, 300, 400, 300, renderer, false);

	cashOut = new Sprite("Images/Gameover.jpg", 0, 0, 1400, 960, renderer, false);
	exitBut = new Sprite("Images/exit.png", 650, 800, 128, 128 , renderer, false);

	Deck1 = new Sprite("Images/Card.png", 500, 175, 44, 63, renderer, true);


	font = TTF_OpenFont("Fonts/Starjout.ttf", 36);
	font1 = TTF_OpenFont("Fonts/Starjout.ttf", 72);

	if (!font)
	{
		cerr << "TTF_OpenFont Error: " << TTF_GetError() << endl;
		return 1;
	}

	if (!font1)
	{
		cerr << "TTF_OpenFont Error: " << TTF_GetError() << endl;
		return 1;
	}


	ThemeSong = Mix_LoadMUS("Sounds/ThemeSong.mp3");
	if (!ThemeSong)
	{
			cerr << "Mix_LoadMUS Error: " << Mix_GetError() << endl;
	}

	CantinaSong = Mix_LoadMUS("Sounds/CantinaSong.mp3");
	if (!CantinaSong)
	{
		cerr << "Mix_LoadMUS Error: " << Mix_GetError() << endl;
	}

	
	
	DealSnd = Mix_LoadWAV("Sounds/VaderYes.wav");
	if (!DealSnd)
	{
		cerr << "Mix_LoadWAV Error: " << Mix_GetError() << endl;
	}

	BetSnd = Mix_LoadWAV("Sounds/R2D2.wav");
	if (!DealSnd)
	{
		cerr << "Mix_LoadWAV Error: " << Mix_GetError() << endl;
	}

	HitSnd = Mix_LoadWAV("Sounds/Blaster.wav");
	if (!DealSnd)
	{
		cerr << "Mix_LoadWAV Error: " << Mix_GetError() << endl;
	}

	PWin = Mix_LoadWAV("Sounds/Roar.wav");
	if (!PWin)
	{
		cerr << "Mix_LoadWAV Error: " << Mix_GetError() << endl;
	}

	PLose = Mix_LoadWAV("Sounds/VaderLose.wav");
	if (!PLose)
	{
		cerr << "Mix_LoadWAV Error: " << Mix_GetError() << endl;
	}

	if (playStart == true)
	{
		Mix_PlayMusic(ThemeSong, -1);
	}

	

	
		end = false;
		srand(time(NULL));

		Deck _deck;

		_deck.shuffle();

		_deck.getCard();
		int cardOneRow = _deck.getRowValue();
		int cardOneFrame = _deck.getFrameValue();
		int cardOnePoint = _deck.getCardValue();
		_deck.removeCard();
		_deck.getCard();
		int cardTwoRow = _deck.getRowValue();
		int cardTwoFrame = _deck.getFrameValue();
		int cardTwoPoint = _deck.getCardValue();
		_deck.removeCard();
		_deck.getCard();
		int dCardOneRow = _deck.getRowValue();
		int dCardOneFrame = _deck.getFrameValue();
		int dCardOnePoint = _deck.getCardValue();
		_deck.removeCard();
		_deck.getCard();
		int dCardTwoRow = _deck.getRowValue();
		int dCardTwoFrame = _deck.getFrameValue();
		int dCardTwoPoint = _deck.getCardValue();
		_deck.removeCard();

		bool playerAceRule = false;
		int playerAceCount = 0;

		bool dealerAceRule = false;
		int dealerAceCount = 0;
		

		if (cardOnePoint == 11)
		{
			playerAceRule = true;
			playerAceCount++;
		}

		if (cardTwoPoint == 11)
		{
			playerAceRule = true;
			playerAceCount++;
		}

		if (dCardOnePoint == 11)
		{
			dealerAceRule = true;
			dealerAceCount++;
		}

		if (dCardTwoPoint == 11)
		{
			dealerAceRule = true;
			dealerAceCount++;
		}

		int playerPointTotal = cardOnePoint + cardTwoPoint;
		if (playerPointTotal > 21 && playerAceCount > 0)
		{
			playerPointTotal = (playerPointTotal - 11) + 1;
			playerAceCount--;
		}
		cout << playerPointTotal << endl;
		int dealerPointTotal = dCardOnePoint + dCardTwoPoint;
		if (dealerPointTotal > 21 && dealerAceCount > 0)
		{
			dealerPointTotal = (dealerPointTotal - 11) + 1;
			dealerAceCount--;
		}

		int hitCard = 1;
		int dHitCard = 0;

		int hitCard1Row = 0;
		int hitCard1Frame = 0;
		int hitCard2Row = 0;
		int hitCard2Frame = 0;
		int hitCard3Row = 0;
		int hitCard3Frame = 0;
		int hitCard4Row = 0;
		int hitCard4Frame = 0;

		int dHitCard1Row = 0;
		int dHitCard1Frame = 0;
		int dHitCard2Row = 0;
		int dHitCard2Frame = 0;
		int dHitCard3Row = 0;
		int dHitCard3Frame = 0;
		int dHitCard4Row = 0;
		int dHitCard4Frame = 0;

		int Bet = 0;

		bool playerBust = false;
		bool playerSurrender = false;
		bool dealerBust = false;
		bool dealerTurn = false;
		bool dealerBlackJack = false;
		bool reset = false;
		bool soundPlayed = false;

		int won = 0;
		
		


		while (!end)
		{
			
			if (reset == true)
			{
				if (playerChips <= 0)
				{
					cashOut->setVisible(true);
				}
				end = true;

				text = TTF_RenderText_Blended(font, 0, color);
				betText = SDL_CreateTextureFromSurface(renderer, text);
			

				text = TTF_RenderText_Blended(font, 0, color);
				playerPoints = SDL_CreateTextureFromSurface(renderer, text);
				

				text = TTF_RenderText_Blended(font, 0, color);
				dealerPoints = SDL_CreateTextureFromSurface(renderer, text);	
			}
			if (SDL_GetTicks() - updatedTime >= deltaTime)
			{
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{

					case SDL_QUIT:
						end = true;
						gameContinue = false;
						break;

					case SDL_KEYDOWN:
						if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							end = true;
							gameContinue = false;
						}
						break;
					case SDL_MOUSEBUTTONDOWN:
						if (Player::Input(event.button.x, event.button.y, startButton) && startButton->isVisible())
						{
							startTitle->setVisible(false);
							startButton->setVisible(false);

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							

							Mix_HaltMusic();
						}

						if (Player::Input(event.button.x, event.button.y, Bet1) && Bet1->isVisible() && playerChips >= 1)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 1;
							playerChips -= 1;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, Bet5) && Bet5->isVisible() && playerChips >= 5)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 5;
							playerChips -= 5;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, Bet10) && Bet10->isVisible() && playerChips >= 10)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 10;
							playerChips -= 10;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, Bet25) && Bet25->isVisible() && playerChips >= 25)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 25;
							playerChips -= 25;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, Bet50) && Bet50->isVisible() && playerChips >= 50)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 50;
							playerChips -= 50;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, Bet100) && Bet100->isVisible() && playerChips >= 100)
						{
							Chips->setVisible(true);
							cashOutB->setVisible(false);
							Bet += 100;
							playerChips -= 100;
							cout << Bet << endl;
							cout << playerChips << endl;

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayChannel(-1, BetSnd, 0);
						}

						if (Player::Input(event.button.x, event.button.y, cashOutB) && cashOutB->isVisible())
						{
							cashOut->setVisible(true);
							exitBut->setVisible(true);
							
							text = TTF_RenderText_Blended(font1, to_string(playerChips).c_str(), color);
							cashoutCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest3.h = text->h;
							dest3.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
							playerCredits = SDL_CreateTextureFromSurface(renderer, text);
							dest.h = text->h;
							dest.w = text->w;

							Mix_PlayMusic(CantinaSong,-1);

						}

						if (Player::Input(event.button.x, event.button.y, exitBut) && exitBut->isVisible())
						{
							return 0;
						}


						if (Player::Input(event.button.x, event.button.y, Deal) && Deal->isVisible())
						{
							if (Bet > 0)
							{
								Deal->setVisible(false);

								Bet1->setVisible(false);
								Bet5->setVisible(false);
								Bet10->setVisible(false);
								Bet25->setVisible(false);
								Bet50->setVisible(false);
								Bet100->setVisible(false);

								Card1->setVisible(true);
								Card2->setVisible(true);
								dCard->setVisible(true);
								dCard2Back->setVisible(true);

								Hit->setVisible(true);
								Stand->setVisible(true);
								DoubleDown->setVisible(true);
								Surrender->setVisible(true);

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								Mix_PlayChannel(-1, DealSnd, 0);

							}
							else
							{
								cout << "No bet, must place a bet" << endl;
							}
						}


						if (Player::Input(event.button.x, event.button.y, Hit) && Hit->isVisible())
						{
							DoubleDown->setVisible(false);
							Surrender->setVisible(false);

							if (hitCard == 1)
							{
								_deck.getCard();
								int hitCardPoint = _deck.getCardValue();
								if (hitCardPoint == 11)
								{
									playerAceRule = true;
									playerAceCount++;
								}
								playerPointTotal = playerPointTotal + hitCardPoint;
								cout << playerPointTotal << endl;
								hitCard1Row = _deck.getRowValue();
								hitCard1Frame = _deck.getFrameValue();
								_deck.removeCard();
								hitCard1->setVisible(true);
								hitCard++;

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								Mix_PlayChannel(-1, HitSnd, 0);

								while (playerPointTotal > 21 && playerAceCount > 0)
								{
									playerPointTotal = (playerPointTotal - 11) + 1;

									text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
									playerPoints = SDL_CreateTextureFromSurface(renderer, text);
									dest1.h = text->h;
									dest1.w = text->w;

									playerAceCount--;
								}


								if (playerPointTotal > 21)
								{
											cout << "Player Bust" << endl;

											Hit->setVisible(false);
											Stand->setVisible(false);
											DoubleDown->setVisible(false);
											Surrender->setVisible(false);
											playerBust = true;
											dealerTurn = true;
								}
								else
								{
									cout << "You are at " << playerPointTotal << " Points" << endl;
								}
							}
							else if (hitCard == 2)
							{
								_deck.getCard();
								int hitCardPoint = _deck.getCardValue();
								if (hitCardPoint == 11)
								{
									playerAceRule = true;
									playerAceCount++;
								}
								playerPointTotal = playerPointTotal + hitCardPoint;
								cout << playerPointTotal << endl;
								hitCard2Row = _deck.getRowValue();
								hitCard2Frame = _deck.getFrameValue();
								_deck.removeCard();
								hitCard2->setVisible(true);
								hitCard++;

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								Mix_PlayChannel(-1, HitSnd, 0);

								while (playerPointTotal > 21 && playerAceCount > 0)
								{
									playerPointTotal = (playerPointTotal - 11) + 1;

									text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
									playerPoints = SDL_CreateTextureFromSurface(renderer, text);
									dest1.h = text->h;
									dest1.w = text->w;

									playerAceCount--;
								}


								if (playerPointTotal > 21)
								{
									cout << "Player Bust" << endl;

									Hit->setVisible(false);
									Stand->setVisible(false);
									DoubleDown->setVisible(false);
									Surrender->setVisible(false);
									playerBust = true;
									dealerTurn = true;		
								}
								else
								{
									cout << "You are at " << playerPointTotal << " Points" << endl;
								}
							}
							else if (hitCard == 3)
							{
								_deck.getCard();
								int hitCardPoint = _deck.getCardValue();
								if (hitCardPoint == 11)
								{
									playerAceRule = true;
									playerAceCount++;
								}
								playerPointTotal = playerPointTotal + hitCardPoint;
								cout << playerPointTotal << endl;
								hitCard3Row = _deck.getRowValue();
								hitCard3Frame = _deck.getFrameValue();
								_deck.removeCard();
								hitCard3->setVisible(true);
								hitCard++;

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								Mix_PlayChannel(-1, HitSnd, 0);

								while (playerPointTotal > 21 && playerAceCount > 0)
								{
									playerPointTotal = (playerPointTotal - 11) + 1;

									text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
									playerPoints = SDL_CreateTextureFromSurface(renderer, text);
									dest1.h = text->h;
									dest1.w = text->w;

									playerAceCount--;
								}


								if (playerPointTotal > 21)
								{
									
									cout << "Player Bust" << endl;

									Hit->setVisible(false);
									Stand->setVisible(false);
									DoubleDown->setVisible(false);
									Surrender->setVisible(false);
									playerBust = true;
									dealerTurn = true;
									
								}
								else
								{
									cout << "You are at " << playerPointTotal << " Points" << endl;
								}
							}
							else if (hitCard == 4)
							{
								_deck.getCard();
								int hitCardPoint = _deck.getCardValue();
								if (hitCardPoint == 11)
								{
									playerAceRule = true;
									playerAceCount++;
								}
								playerPointTotal = playerPointTotal + hitCardPoint;
								cout << playerPointTotal << endl;
								hitCard4Row = _deck.getRowValue();
								hitCard4Frame = _deck.getFrameValue();
								_deck.removeCard();
								hitCard4->setVisible(true);
								hitCard++;

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								Mix_PlayChannel(-1, HitSnd, 0);

								while (playerPointTotal > 21 && playerAceCount > 0)
								{
									playerPointTotal = (playerPointTotal - 11) + 1;

									text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
									playerPoints = SDL_CreateTextureFromSurface(renderer, text);
									dest1.h = text->h;
									dest1.w = text->w;

									playerAceCount--;
								}


								if (playerPointTotal > 21)
								{
									cout << "Player Bust" << endl;

									Hit->setVisible(false);
									Stand->setVisible(false);
									DoubleDown->setVisible(false);
									Surrender->setVisible(false);
									playerBust = true;
									dealerTurn = true;		
								}
								else
								{
									cout << "You are at " << playerPointTotal << " Points" << endl;
								}
							}
						}

						if (Player::Input(event.button.x, event.button.y, Stand) && Stand->isVisible())
						{
							cout << "You Stand at " << playerPointTotal << " Points" << endl;
							dealerTurn = true;

							
						}

						if (Player::Input(event.button.x, event.button.y, DoubleDown) && DoubleDown->isVisible())
						{
							Bet *= 2;
							playerChips -= Bet;
							cout << "Double Down, bet is now at " << Bet << endl;
							_deck.getCard();
							int hitCardPoint = _deck.getCardValue();
							if (hitCardPoint == 11)
							{
								playerAceRule = true;
							}
							playerPointTotal = playerPointTotal + hitCardPoint;
							cout << playerPointTotal << endl;
							hitCard1Row = _deck.getRowValue();
							hitCard1Frame = _deck.getFrameValue();
							_deck.removeCard();
							hitCard1->setVisible(true);

							text = TTF_RenderText_Blended(font, to_string(Bet).c_str(), color);
							betText = SDL_CreateTextureFromSurface(renderer, text);
							dest4.h = text->h;
							dest4.w = text->w;

							text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
							playerPoints = SDL_CreateTextureFromSurface(renderer, text);
							dest1.h = text->h;
							dest1.w = text->w;

							Mix_PlayChannel(-1, HitSnd, 0);

							while (playerPointTotal > 21 && playerAceCount > 0)
							{
								playerPointTotal = (playerPointTotal - 11) + 1;

								text = TTF_RenderText_Blended(font, to_string(playerPointTotal).c_str(), color);
								playerPoints = SDL_CreateTextureFromSurface(renderer, text);
								dest1.h = text->h;
								dest1.w = text->w;

								playerAceCount--;
							}

							if (playerPointTotal > 21)
							{
								cout << "Player Bust" << endl;

								Hit->setVisible(false);
								Stand->setVisible(false);
								DoubleDown->setVisible(false);
								Surrender->setVisible(false);
								playerBust = true;
								dealerTurn = true;
							}
							else
							{
								cout << "You are at " << playerPointTotal << " Points" << endl;
								dealerTurn = true;
							}
						}

						if (Player::Input(event.button.x, event.button.y, Surrender) && Surrender->isVisible())
						{
							
							cout << "You Surrendered and recieved half your chips back" << endl;
							dealerTurn = true;
							playerSurrender = true;

							
						}

						if (Player::Input(event.button.x, event.button.y, contin) && contin->isVisible())
						{
							reset = true;
							playStart = false;

							Mix_HaltMusic();
						}


						break;


					}
				}

				while (dealerTurn == true)
				{


					if (dHitCard == 0)
					{
						dCard2Back->setVisible(false);
						dCard2->setVisible(true);

						Hit->setVisible(false);
						Stand->setVisible(false);
						DoubleDown->setVisible(false);
						Surrender->setVisible(false);

						text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
						dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
						dest2.h = text->h;
						dest2.w = text->w;
					
						if (dealerPointTotal < 17)
						{
							dHitCard++;
						}
						else if (dealerPointTotal == 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer has BLACKJACK!" << endl;
							dealerBlackJack = true;
							dealerTurn = false;

							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else if (dealerPointTotal > 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer BUST" << endl;
							dealerBust = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else
						{
							cout << "Dealer Stands at " << dealerPointTotal << " Points." << endl;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
							
						}
					}

					else if (dHitCard == 1)
					{
						_deck.getCard();
						if (_deck.getCardValue() == 11)
						{
							dealerAceCount++;
						}
						dealerPointTotal = dealerPointTotal + _deck.getCardValue();
						dHitCard1Row = _deck.getRowValue();
						dHitCard1Frame = _deck.getFrameValue();
						dHitCard1->setVisible(true);
						_deck.removeCard();

						text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
						dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
						dest2.h = text->h;
						dest2.w = text->w;

						while (dealerPointTotal > 21 && dealerAceCount > 0)
						{
							dealerPointTotal = (dealerPointTotal - 11) + 1;

							text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
							dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
							dest2.h = text->h;
							dest2.w = text->w;

							dealerAceCount--;
						}

					    if (dealerPointTotal < 17)
						{
							dHitCard++;
						}
						else if (dealerPointTotal == 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer has BLACKJACK!" << endl;
							dealerBlackJack = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
							
						}
						else if (dealerPointTotal > 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer BUST" << endl;
							dealerBust = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else
						{
							cout << "Dealer Stands at " << dealerPointTotal << " Points." << endl;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}

					}
					else if (dHitCard == 2)
					{
						_deck.getCard();
						if (_deck.getCardValue() == 11)
						{
							dealerAceCount++;
						}
						dealerPointTotal = dealerPointTotal + _deck.getCardValue();
						dHitCard2Row = _deck.getRowValue();
						dHitCard2Frame = _deck.getFrameValue();
						dHitCard2->setVisible(true);
						_deck.removeCard();

						text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
						dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
						dest2.h = text->h;
						dest2.w = text->w;

						while (dealerPointTotal > 21 && dealerAceCount > 0)
						{
							dealerPointTotal = (dealerPointTotal - 11) + 1;

							text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
							dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
							dest2.h = text->h;
							dest2.w = text->w;

							dealerAceCount--;
						}

						if (dealerPointTotal < 17)
						{
							dHitCard++;
						}
						else if (dealerPointTotal == 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer has BLACKJACK!" << endl;
							dealerBlackJack = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);

						}
						else if (dealerPointTotal > 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer BUST" << endl;
							dealerBust = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else
						{
							cout << "Dealer Stands at " << dealerPointTotal << " Points." << endl;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}

					}
					else if (dHitCard == 3)
					{
						_deck.getCard();
						if (_deck.getCardValue() == 11)
						{
							dealerAceCount++;
						}
						dealerPointTotal = dealerPointTotal + _deck.getCardValue();
						dHitCard3Row = _deck.getRowValue();
						dHitCard3Frame = _deck.getFrameValue();
						dHitCard3->setVisible(true);
						_deck.removeCard();

						text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
						dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
						dest2.h = text->h;
						dest2.w = text->w;

						while (dealerPointTotal > 21 && dealerAceCount > 0)
						{
							dealerPointTotal = (dealerPointTotal - 11) + 1;

							text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
							dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
							dest2.h = text->h;
							dest2.w = text->w;

							dealerAceCount--;
						}

						if (dealerPointTotal < 17)
						{
							dHitCard++;
						}
						else if (dealerPointTotal == 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer has BLACKJACK!" << endl;
							dealerBlackJack = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);

						}
						else if (dealerPointTotal > 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer BUST" << endl;
							dealerBust = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else
						{
							cout << "Dealer Stands at " << dealerPointTotal << " Points." << endl;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}

					}
					else if (dHitCard == 4)
					{
						_deck.getCard();
						if (_deck.getCardValue() == 11)
						{
							dealerAceCount++;
						}
						dealerPointTotal = dealerPointTotal + _deck.getCardValue();
						dHitCard4Row = _deck.getRowValue();
						dHitCard4Frame = _deck.getFrameValue();
						dHitCard4->setVisible(true);
						_deck.removeCard();

						text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
						dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
						dest2.h = text->h;
						dest2.w = text->w;

						while (dealerPointTotal > 21 && dealerAceCount > 0)
						{
							dealerPointTotal = (dealerPointTotal - 11) + 1;

							text = TTF_RenderText_Blended(font, to_string(dealerPointTotal).c_str(), color);
							dealerPoints = SDL_CreateTextureFromSurface(renderer, text);
							dest2.h = text->h;
							dest2.w = text->w;

							dealerAceCount--;
						}

						if (dealerPointTotal < 17)
						{
							dHitCard++;
						}
						else if (dealerPointTotal == 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer has BLACKJACK!" << endl;
							dealerBlackJack = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);

						}
						else if (dealerPointTotal > 21)
						{
							cout << "Dealer is at " << dealerPointTotal << " Points." << endl;
							cout << "Dealer BUST" << endl;
							dealerBust = true;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}
						else
						{
							cout << "Dealer Stands at " << dealerPointTotal << " Points." << endl;
							dealerTurn = false;
							determineOutcome(playerPointTotal, dealerPointTotal, playerBust, dealerBust, dealerBlackJack, Bet, playerChips, playerSurrender, won);
						}

					}
				}

				if (won == 1)
				{
					win->setVisible(true);
					contin->setVisible(true);

					text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
					playerCredits = SDL_CreateTextureFromSurface(renderer, text);
					dest.h = text->h;
					dest.w = text->w;
					

					if (soundPlayed == false)
					{
						Mix_PlayChannel(-1, PWin, 0);
						soundPlayed = true;
					}
				}
				else if (won == 2)
				{
					lose->setVisible(true);
					contin->setVisible(true);

					text = TTF_RenderText_Blended(font, to_string(playerChips).c_str(), color);
					playerCredits = SDL_CreateTextureFromSurface(renderer, text);
					dest.h = text->h;
					dest.w = text->w;

					if (soundPlayed == false)
					{
						Mix_PlayChannel(-1, PLose, 0);
						soundPlayed = true;
					}
				}




				Background->draw(renderer);
				Table->draw(renderer);
				StarWars->draw(renderer);
				Empire->draw(renderer);
				Rebels->draw(renderer);
				Avatar->draw(renderer);

				Deal->draw(renderer);


				Bet1->draw(renderer);
				Bet5->draw(renderer);
				Bet10->draw(renderer);
				Bet25->draw(renderer);
				Bet50->draw(renderer);
				Bet100->draw(renderer);
				cashOutB->draw(renderer);
				

				Chips->draw(renderer);

				Hit->draw(renderer);
				Stand->draw(renderer);
				DoubleDown->draw(renderer);
				Surrender->draw(renderer);


				Card1->draw(renderer);
				Card1->setRow(cardOneRow);
				Card1->setCurrentFrame(cardOneFrame);

				Card2->draw(renderer);
				Card2->setRow(cardTwoRow);
				Card2->setCurrentFrame(cardTwoFrame);

				hitCard1->draw(renderer);
				hitCard1->setRow(hitCard1Row);
				hitCard1->setCurrentFrame(hitCard1Frame);

				hitCard2->draw(renderer);
				hitCard2->setRow(hitCard2Row);
				hitCard2->setCurrentFrame(hitCard2Frame);

				hitCard3->draw(renderer);
				hitCard3->setRow(hitCard3Row);
				hitCard3->setCurrentFrame(hitCard3Frame);

				hitCard4->draw(renderer);
				hitCard4->setRow(hitCard4Row);
				hitCard4->setCurrentFrame(hitCard4Frame);

				dHitCard1->draw(renderer);
				dHitCard1->setRow(dHitCard1Row);
				dHitCard1->setCurrentFrame(dHitCard1Frame);

				dHitCard2->draw(renderer);
				dHitCard2->setRow(dHitCard2Row);
				dHitCard2->setCurrentFrame(dHitCard2Frame);

				dHitCard3->draw(renderer);
				dHitCard3->setRow(dHitCard3Row);
				dHitCard3->setCurrentFrame(dHitCard3Frame);

				dHitCard4->draw(renderer);
				dHitCard4->setRow(dHitCard4Row);
				dHitCard4->setCurrentFrame(dHitCard4Frame);




				dCard->draw(renderer);
				dCard->setRow(dCardOneRow);
				dCard->setCurrentFrame(dCardOneFrame);

				dCard2Back->draw(renderer);
				dCard2Back->setRow(4);

				dCard2->draw(renderer);
				dCard2->setRow(dCardTwoRow);
				dCard2->setCurrentFrame(dCardTwoFrame);


				Deck1->draw(renderer);
				Deck1->setRow(4);

				
				win->draw(renderer);
				lose->draw(renderer);
				contin->draw(renderer);

				
				startTitle->draw(renderer);
				startButton->draw(renderer);

				
				SDL_RenderCopy(renderer, playerCredits, NULL, &dest);
				SDL_RenderCopy(renderer, playerPoints, NULL, &dest1);
				SDL_RenderCopy(renderer, dealerPoints, NULL, &dest2);
				SDL_RenderCopy(renderer, betText, NULL, &dest4);


				cashOut->draw(renderer);
				SDL_RenderCopy(renderer, cashoutCredits, NULL, &dest3);
				exitBut->draw(renderer);
			
				SDL_RenderPresent(renderer);

				updatedTime = SDL_GetTicks();


			}
		}

		

		delete Background;
		delete Table;
		delete StarWars;
		delete Empire;
		delete Rebels;
		delete Avatar;

		delete Deal;

		delete Bet1;
		delete Bet5;
		delete Bet10;
		delete Bet25;
		delete Bet50;
		delete Bet100;

		delete Chips;

		delete Hit;
		delete Stand;
		delete DoubleDown;
		delete Surrender;

		delete Card1;
		delete Card2;
		delete hitCard1;
		delete hitCard2;
		delete hitCard3;
		delete hitCard4;
		delete dCard;
		delete dCard2;
		delete dHitCard1;
		delete dHitCard2;
		delete dHitCard3;
		delete dHitCard4;

		delete contin;
		delete win;
		delete lose;

		

		delete Deck1;


	}
	delete cashOut;
	delete exitBut;
	delete startTitle;
	delete startButton;

	SDL_FreeSurface(text);
	SDL_DestroyTexture(playerCredits);
	SDL_DestroyTexture(playerPoints);
	SDL_DestroyTexture(dealerPoints);
	SDL_DestroyTexture(cashoutCredits);

	TTF_CloseFont(font);
	TTF_CloseFont(font1);

	Mix_HaltMusic();
	Mix_FreeMusic(ThemeSong);
	Mix_FreeMusic(CantinaSong);
	

	Mix_FreeChunk(HitSnd);
	Mix_FreeChunk(DealSnd);
	Mix_FreeChunk(BetSnd);
	Mix_FreeChunk(PWin);
	Mix_FreeChunk(PLose);

	return 0;
}


void Game::determineOutcome(int playerPoints, int dealerPoints, bool playerBust, bool dealerBust, bool dealerBlackJack, int bet, int &playerChips, bool playerSurrender,int &won)
{
	if (playerSurrender == true)
	{
		cout << "You surrendered and recieved half your bet." << endl;
		playerChips = playerChips + (bet / 2);
		won = 2;
	}
	else if (dealerBlackJack == true)
	{
		cout << "YOU LOSE" << endl;
		won = 2;
		
	}
	else if (playerBust == true)
	{
		cout << "YOU LOSE" << endl;
		won = 2;
	}
	else if (dealerBust == true)
	{
		cout << "YOU WIN" << endl;
		playerChips = playerChips + bet * 2;
		won = 1;
	}
	else if (playerPoints > dealerPoints)
	{
		cout << "YOU WIN" << endl;
		playerChips = playerChips + bet * 2;
		won = 1;
	}
	else if (playerPoints < dealerPoints)
	{
		cout << "YOU LOSE" << endl;
		won = 2;
	}
	else if (playerPoints == dealerPoints)
	{
		cout << "YOU LOSE" << endl;
		won = 2;
	}
}