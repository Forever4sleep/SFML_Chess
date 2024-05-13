#include "pawn.h"
#include "board.h"

Pawn::Pawn(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite) :Figure(board, manager, Type::Pawn, pos_x, pos_y, isWhite)
{
	this->is_starting = true;
}

void Pawn::getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height)
{
	sf::Vector2u nonexistent = sf::Vector2u(-1, -1);
	if (getIsWhite())
	{
		if (is_starting)
		{
			board->findFigureByPos(getX(), getY());
			if (board->findFigureByPos(getX(), getY() - square_height) == nullptr)
				array[0] = board->findNearestSquare(getX(), getY() - square_height);
			if (board->findFigureByPos(getX(), getY() - 2 * square_height) == nullptr && array[0].x != -1)
				array[1] = board->findNearestSquare(getX(), getY() - 2 * square_height);
			if (board->findFigureByPos(getX() - square_width, getY() - square_height, false) != nullptr)
				array[2] = board->findNearestSquare(getX() - square_width, getY() - square_height);
			if (board->findFigureByPos(getX() + square_width, getY() - square_height, false) != nullptr)
				array[3] = board->findNearestSquare(getX() + square_width, getY() - square_height);
		}
		else
		{
			if (board->findFigureByPos(getX(), getY() - square_height) == nullptr)
				array[0] = board->findNearestSquare(getX(), getY() - square_height);
			if (board->findFigureByPos(getX() - square_width, getY() - square_height, false) != nullptr)
				array[1] = board->findNearestSquare(getX() - square_width, getY() - square_height);
			if (board->findFigureByPos(getX() + square_width, getY() - square_height, false) != nullptr)
				array[2] = board->findNearestSquare(getX() + square_width, getY() - square_height);
		}
	}
	else
	{
		if (is_starting)
		{
			if (board->findFigureByPos(getX(), getY() + square_height) == nullptr)
				array[0] = board->findNearestSquare(getX(), getY() + square_height);
			if (board->findFigureByPos(getX(), getY() + 2 * square_height) == nullptr && array[0].x != -1)
				array[1] = board->findNearestSquare(getX(), getY() + 2 * square_height);
			if (board->findFigureByPos(getX() - square_width, getY() + square_height, true) != nullptr)
				array[2] = board->findNearestSquare(getX() - square_width, getY() + square_height);
			if (board->findFigureByPos(getX() + square_width, getY() + square_height, true) != nullptr)
				array[3] = board->findNearestSquare(getX() + square_width, getY() + square_height);
		}
		else
		{
			if (board->findFigureByPos(getX(), getY() + square_height) == nullptr)
				array[0] = board->findNearestSquare(getX(), getY() + square_height);
			if (board->findFigureByPos(getX() - square_width, getY() + square_height, true) != nullptr)
				array[1] = board->findNearestSquare(getX() - square_width, getY() + square_height);
			if (board->findFigureByPos(getX() + square_width, getY() + square_height, true) != nullptr)
				array[2] = board->findNearestSquare(getX() + square_width, getY() + square_height);
		}
	}
}

bool Pawn::move(int x, int y, int square_width, int square_height, Figure* figureAtPosition)
{
	sf::Vector2u pos[100];
	getAllAvailabePositions(pos, square_width, square_height);
	for (int i = 0; i < 100; i++)
	{
		sf::Vector2u square1;
		if (pos[i].x != -1 && pos[i].y != -1)
		{
			square1 = board->findNearestSquare(pos[i].x + square_width / 5, pos[i].y + square_height / 5);
			if (square1.x == x && square1.y == y)
			{
				if (figureAtPosition != nullptr) figureAtPosition->setDead();
				this->setPosition(square1.x, square1.y);
				this->is_starting = false;

				return true;
			}
		}
	}
	return false;
}
