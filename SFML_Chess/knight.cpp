#include "knight.h"
#include "board.h"

Knight::Knight(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite):Figure(board, manager, Type::Knight, pos_x, pos_y, isWhite)
{
}

void Knight::getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height)
{
	if (getIsWhite())
	{
		if (board->findFigureByPos(getX() + square_width, getY() + 2 * square_height, true) == nullptr)
			array[0] = board->findNearestSquare(getX() + square_width, getY() + 2 * square_height );
		if (board->findFigureByPos(getX() - square_width, getY() + 2 * square_height, true) == nullptr)
			array[1] = board->findNearestSquare(getX() - square_width, getY() + 2 * square_height);
		if (board->findFigureByPos(getX() + square_width, getY() - 2 * square_height, true) == nullptr)
			array[2] = board->findNearestSquare(getX() + square_width, getY() - 2 * square_height);
		if (board->findFigureByPos(getX() - square_width, getY() - 2 * square_height, true) == nullptr)
			array[3] = board->findNearestSquare(getX() - square_width, getY() - 2 * square_height);
		if (board->findFigureByPos(getX() + 2 * square_width, getY() + square_height, true) == nullptr)
			array[4] = board->findNearestSquare(getX() + 2 * square_width, getY() + square_height);
		if (board->findFigureByPos(getX() + 2 * square_width, getY() - square_height, true) == nullptr)
			array[5] = board->findNearestSquare(getX() + 2 * square_width, getY() - square_height);
		if (board->findFigureByPos(getX() - 2 * square_width, getY() - square_height, true) == nullptr)
			array[6] = board->findNearestSquare(getX() - 2 * square_width, getY() - square_height);
		if (board->findFigureByPos(getX() - 2 * square_width, getY() + square_height, true) == nullptr)
			array[7] = board->findNearestSquare(getX() - 2 * square_width, getY() + square_height);
	}
	else
	{
		if (board->findFigureByPos(getX() + square_width, getY() + 2 * square_height, false) == nullptr)
			array[0] = board->findNearestSquare(getX() + square_width, getY() + 2 * square_height);
		if (board->findFigureByPos(getX() - square_width, getY() + 2 * square_height, false) == nullptr)
			array[1] = board->findNearestSquare(getX() - square_width, getY() + 2 * square_height);
		if (board->findFigureByPos(getX() + 2 * square_width, getY() - square_height, false) == nullptr)
			array[2] = board->findNearestSquare(getX() + 2 * square_width, getY() - square_height);
		if (board->findFigureByPos(getX() - square_width, getY() -  2 * square_height, false) == nullptr)
			array[3] = board->findNearestSquare(getX() - square_width, getY() - 2 * square_height);
		if (board->findFigureByPos(getX() + 2 * square_width, getY() + square_height, false) == nullptr)
			array[4] = board->findNearestSquare(getX() + 2 * square_width, getY() + square_height);
		if (board->findFigureByPos(getX() - 2 * square_width, getY() + square_height, false) == nullptr)
			array[5] = board->findNearestSquare(getX() - 2 * square_width, getY() + square_height);
		if (board->findFigureByPos(getX() - 2 * square_width, getY() - square_height, false) == nullptr)
			array[6] = board->findNearestSquare(getX() - 2 * square_width, getY() - square_height);
		if (board->findFigureByPos(getX() + square_width, getY() - 2 * square_height, false) == nullptr)
			array[7] = board->findNearestSquare(getX() + square_width, getY() - 2 * square_height);
	}
}