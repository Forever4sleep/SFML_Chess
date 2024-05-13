#include "board.h"
#include "bishop.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include <iostream>

sf::Sprite Board::getBoardSprite() { return this->sprite; }

Board::Board(sf::RenderWindow& window, TextureManager& manager, int square_width, int square_height)
{
	this->currentFigure = nullptr;
	createFiguresSet(manager, square_width, square_height);

	for (int i = 0; i < 32; i++) window.draw(figures[i]->getSprite());
	this->sprite = sf::Sprite(manager.getBoardTexture());
	this->markers = new sf::Vector2u[100];

	sf::Vector2u nonexistent = sf::Vector2u(-1, -1);
	for (int i = 0; i < 100; i++) this->markers[i] = nonexistent;
}

void Board::drawFigures(sf::RenderWindow& window)
{
	for (int i = 0; i < 32; i++)
	{
		if (!this->figures[i]->getIsDead())
			window.draw(this->figures[i]->getSprite());
	}
}

Figure* Board::findFigureByPos(int x, int y, bool shouldBeWhite = true)
{
	sf::Vector2u u = findNearestSquare(x, y);
	x = u.x;
	y = u.y;


	for (int i = 0; i < 32; i++)
		if (figures[i]->getIsWhite() == shouldBeWhite && !figures[i]->getIsDead() && x == figures[i]->getX()
			&& y == figures[i]->getY()) return this->figures[i];

	return nullptr;
}

Figure* Board::findFigureByPos(int x, int y)
{
	sf::Vector2u u = findNearestSquare(x, y);
	x = u.x;
	y = u.y;

	for (int i = 0; i < 32; i++)
		if (!this->figures[i]->getIsDead() && figures[i]->getX() == x && figures[i]->getY() == y) 
			return figures[i];
	
	return nullptr;
}



sf::Vector2u Board::findNearestSquare(int x, int y)
{
	for (int current_y = 0; current_y < 700; current_y += 87)
	{
		for (int current_x = 0; current_x < 700; current_x += 87)
		{
			if (x >= current_x && x <= current_x + 87 && y >= current_y && y <= current_y + 87)
			{
				return sf::Vector2u(current_x + 87/4, current_y + 87/4); 
			}
		}
	}

	return sf::Vector2u(-1, -1);
}

void Board::createFiguresSet(TextureManager& manager, int square_width, int square_height)
{
	figures[0] = new Rook(*this, manager, 0, 0, false);
	figures[1] = new Knight(*this, manager, square_width * 1.2, 0, false);
	figures[2] = new Bishop(*this, manager, square_width * 2.2, 0, false);
	figures[3] = new Queen(*this, manager, square_width * 3.2, 0, false);
	figures[4] = new King(*this, manager, square_width * 4.2, 0, false);
	figures[5] = new Bishop(*this, manager, square_width * 5.2, 0, false);
	figures[6] = new Knight(*this, manager, square_width * 6.2, 0, false);
	figures[7] = new Rook(*this, manager, square_width * 7.2, 0, false);

	for (int i = 0; i < 8; i++)
		figures[8 + i] = new Pawn(*this, manager, (4 + square_width) * i, 5 + square_height, false);

	for (int i = 0; i < 8; i++)
		figures[16 + i] = new Pawn(*this, manager, (4 + square_width)* i, (5 + square_height) * 6, true);

	int h = square_height * 7.2;
	figures[24] = new Rook(*this, manager,0, h, true);
	figures[25] = new Knight(*this, manager, square_width * 1.2, h, true);
	figures[26] = new Bishop(*this, manager, square_width * 2.2, h, true);
	figures[27] = new Queen(*this, manager, square_width * 3.2, h, true);
	figures[28] = new King(*this, manager, square_width * 4.2, h, true);
	figures[29] = new Bishop(*this, manager, square_width * 5.2, h, true);
	figures[30] = new Knight(*this, manager, square_width * 6.2, h, true);
	figures[31] = new Rook(*this, manager, square_width * 7.2, h, true);
}

void Board::doPositionReset(int square_width, int square_height)
{
	return;
	for (int i = 0; i < 8; i++) this->figures[i]->setPosition(square_width * i, 0);
	for (int i = 0; i < 8; i++) this->figures[i+8]->setPosition(square_width * i, square_height);
	for (int i = 0; i < 8; i++) this->figures[16+i]->setPosition(square_width * i, square_height * 6);
	for (int i = 0; i < 8; i++) this->figures[24+i]->setPosition(square_width * i, square_height * 7);
}


void Board::mark(sf::RenderWindow& window, int square_width, int square_height)
{
	for (int i = 0; i < 100; i++)
	{
		if (markers[i].x != -1 && markers[i].y != -1)
		{
			sf::CircleShape shape;
			shape.setRadius(25.f);
			shape.setFillColor(sf::Color(0, 0, 0, 100));
			shape.setPosition(markers[i].x, markers[i].y);
			window.draw(shape);
		}
	}
}

void Board::updateMarks(int square_width, int square_height)
{
	sf::Vector2u nonexistent = sf::Vector2u(-1, -1);
	if (this->currentFigure == nullptr) for (int i = 0; i < 100; i++) this->markers[i] = nonexistent;

	else
	{
		for (int i = 0; i < 100; i++) this->markers[i] = nonexistent;
		this->currentFigure->getAllAvailabePositions(this->markers, square_width, square_height);
	}
}