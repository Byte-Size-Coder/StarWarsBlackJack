#include "Sprite.h"


Sprite::Sprite(const char* filename, int xpos, int ypos, int width, int height, SDL_Renderer *renderer, bool visable)
{
	rect.h = height;
	rect.w = width;
	rect.x = 0;
	rect.y = 0;
	this->xpos = xpos;
	this->ypos = ypos;
	visible = visable;

	this->load(filename, renderer);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
}

void Sprite::load(const char* filename, SDL_Renderer *renderer)
{
	this->image = IMG_LoadTexture(renderer, filename);

	if (this->image == NULL)
	{
		
		cerr << "IMG_LoadTexture: " << IMG_GetError() << endl;
		exit(0);
	}
}

void Sprite::draw(SDL_Renderer *renderer)
{
	if (this->visible)
	{
		
		SDL_Rect dest = { xpos, ypos, rect.w, rect.h };

		SDL_RenderCopy(renderer, image, &rect, &dest);

	}
}

void Sprite::animate(Uint16 start_frame, Uint16 end_frame)
{
	Uint16 current_frame = getCurrentFrame();
	if (current_frame < start_frame || current_frame > end_frame)
	{
		current_frame = start_frame;
	}
	else
	{
		++current_frame;

		if (current_frame > end_frame)
		{
			current_frame = start_frame;
		}
	}

	setCurrentFrame(current_frame);
}

void Sprite::move(int deltaX, int deltaY)
{
	xpos += deltaX;
	ypos += deltaY;

}

void Sprite::setCurrentFrame(Uint16 frame)
{
	if (!rect.w)
	{
		return;
	}

	rect.x = rect.w * frame;
}

void Sprite::setRow(Uint16 row)
{
	if (!rect.h)
	{
		return;
	}

	rect.y = rect.h * row;
}

Uint16 Sprite::getRow()
{
	if (!rect.h)
	{
		return 0;
	}

	return rect.y / rect.h;
}

Uint16 Sprite::getCurrentFrame()
{
	if (!rect.w)
	{
		return 0;
	}

	return rect.x / rect.w;
}

SDL_Texture *Sprite::getImage()
{
	return this->image;
}

int Sprite::getWidth()
{
	return this->rect.w;
}

int Sprite::getHeight()
{
	return this->rect.h;
}

int Sprite::getXPos()
{
	return this->xpos;
}

int Sprite::getYPos()
{
	return this->ypos;
}

bool Sprite::isVisible()
{
	return this->visible;
}

void Sprite::setWidth(int width)
{
	this->rect.w = width;
}

void Sprite::setHeight(int height)
{
	this->rect.h = height;
}

void Sprite::setXPos(int x)
{
	this->xpos = x;
}

void Sprite::setYPos(int y)
{
	this->ypos = y;
}

void Sprite::setVisible(bool visible)
{
	this->visible = visible;
}
