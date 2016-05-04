#include "Player.h"

bool Player::Input(int xpos, int ypos, Sprite * s)
{
	if ((xpos > s->getXPos()) && (xpos < (s->getXPos() + s->getWidth())))
		if ((ypos > s->getYPos()) && (ypos < (s->getYPos() + s->getHeight())))
			return true;

	return false;
}
