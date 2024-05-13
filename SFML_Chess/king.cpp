#include "king.h"
#include "board.h"

King::King(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite) :Figure(board, manager, Type::King, pos_x, pos_y, isWhite)
{
}

void King::getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height)
{
	if (board->findFigureByPos(getX(), getY() - square_height, getIsWhite()) == nullptr)
		array[0] = board->findNearestSquare(getX(), getY() - square_height);
	if (board->findFigureByPos(getX(), getY() + square_height, getIsWhite()) == nullptr)
		array[1] = board->findNearestSquare(getX(), getY() + square_height);
	if (board->findFigureByPos(getX() + square_width, getY(), getIsWhite()) == nullptr)
		array[2] = board->findNearestSquare(getX() + square_width, getY());
	if (board->findFigureByPos(getX() - square_width, getY(), getIsWhite()) == nullptr)
		array[3] = board->findNearestSquare(getX() - square_width, getY());
	if (board->findFigureByPos(getX() + square_width, getY() - square_height, getIsWhite()) == nullptr)
		array[4] = board->findNearestSquare(getX() + square_width, getY() - square_height);
	if (board->findFigureByPos(getX() + square_width, getY() + square_height, getIsWhite()) == nullptr)
		array[5] = board->findNearestSquare(getX() + square_width, getY() + square_height);
	if (board->findFigureByPos(getX() - square_width, getY() + square_height, getIsWhite()) == nullptr)
		array[6] = board->findNearestSquare(getX() - square_width, getY() + square_height);
	if (board->findFigureByPos(getX() - square_width, getY() - square_height, getIsWhite()) == nullptr)
		array[7] = board->findNearestSquare(getX() - square_width, getY() - square_height);
	return;
}
