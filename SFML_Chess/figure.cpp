#include "figure.h"
#include "texture_manager.h"
#include "board.h"
#include <iostream>

Figure::Figure(Board& board, sf::Sprite _sprite, int pos_x, int pos_y, bool isWhite)
{
	switch (type)
	{
	case Type::Pawn:
		if (isWhite) this->sprite = sf::Sprite(manager.getPawnTextureWhite());
		else this->sprite = sf::Sprite(manager.getPawnTexture());
		break;
	case Type::Bishop:
		if (isWhite) this->sprite = sf::Sprite(manager.getBishopTextureWhite());
		else this->sprite = sf::Sprite(manager.getBishopTexture());
		break;
	case Type::King:
		if (isWhite) this->sprite = sf::Sprite(manager.getKingTextureWhite());
		else this->sprite = sf::Sprite(manager.getKingTexture());
		break;
	case Type::Rook:
		if (isWhite) this->sprite = sf::Sprite(manager.getRookTextureWhite());
		else this->sprite = sf::Sprite(manager.getRookTexture());
		break;
	case Type::Queen:
		if (isWhite) this->sprite = sf::Sprite(manager.getQueenTextureWhite());
		else this->sprite = sf::Sprite(manager.getQueenTexture());
		break;
	case Type::Knight:
		if (isWhite) this->sprite = sf::Sprite(manager.getKnightTextureWhite());
		else this->sprite = sf::Sprite(manager.getKnightTexture());
		break;
	}

	sf::Vector2u u = board.findNearestSquare(pos_x, pos_y);
	this->pos_x = u.x;
	this->pos_y = u.y;
	this->isWhite = isWhite;
	this->isDead = false;
	this->sprite.setPosition(u.x, u.y);
	this->sprite.setScale(0.9f, 0.9f);
	this->type = type;
	this->board = &board;
}

Figure::Figure()
{
	this->pos_x = -1;
	this->pos_y = -1;
}

sf::Sprite& Figure::getSprite()
{
	return this->sprite;
}

bool Figure::move(int x, int y, int square_width, int square_height, Figure* figureAtPosition)
{
	sf::Vector2u pos[100];
	getAllAvailabePositions(pos, square_width, square_height);
	for (int i = 0; i < 100; i++)
	{
		sf::Vector2u square1;
		if (pos[i].x != -1 && pos[i].y != -1)
		{
			int p_x = pos[i].x, p_y = pos[i].y;
			square1 = board->findNearestSquare(p_x, p_y);
			if (square1.x == x && square1.y == y)
			{
				if (figureAtPosition != nullptr) figureAtPosition->setDead();
				this->setPosition(square1.x, square1.y);
				return true;
			}
		}
	}
	return false;
}

bool Figure::setX(int value)
{
	this->pos_x = value;
	return true;
}

bool Figure::setY(int value)
{
	this->pos_y = value;
	return true;
}

bool Figure::setPosition(int x, int y)
{
	bool s_x = setX(x);
	bool s_y = setY(y);
	if (s_x && s_y) this->sprite.setPosition(x, y);
	return s_x && s_y;
}

void Figure::setDead()
{
	this->isDead = true;
}

Figure::Type Figure::getType()
{
	return this->type;
}

int Figure::getX() { return this->pos_x; }
int Figure::getY() { return this->pos_y; }


bool Figure::getIsWhite() { return this->isWhite; }
bool Figure::getIsDead() { return this->isDead; }
