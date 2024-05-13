#include "queen.h"
#include "board.h"

Queen::Queen(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite):Figure(board, manager, Type::Queen, pos_x, pos_y, isWhite)
{
}

void Queen::getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height)
{
	int coeff = 1;
	int i = 0;
	while (board->findFigureByPos(getX() + coeff * square_width, getY() + coeff * square_height, getIsWhite()) == nullptr && coeff < 8)
	{
		array[i++] = board->findNearestSquare(getX() + coeff * square_width, getY() + coeff * square_height);
		if (board->findFigureByPos(getX() + coeff * square_width, getY() + coeff * square_height, !getIsWhite()) != nullptr)
			break;
		coeff++;
	}
	coeff = 1;
	while (board->findFigureByPos(getX() + coeff * square_width, getY() - coeff * square_height, getIsWhite()) == nullptr && coeff < 8)
	{
		array[i++] = board->findNearestSquare(getX() + coeff * square_width, getY() - coeff * square_height);
		if (board->findFigureByPos(getX() + coeff * square_width, getY() - coeff * square_height, !getIsWhite()) != nullptr)
			break;
		coeff++;
	}
	coeff = 1;
	while (board->findFigureByPos(getX() - coeff * square_width, getY() - coeff * square_height, getIsWhite()) == nullptr && coeff < 8)
	{
		array[i++] = board->findNearestSquare(getX() - coeff * square_width, getY() - coeff * square_height);
		if (board->findFigureByPos(getX() - coeff * square_width, getY() - coeff * square_height, !getIsWhite()) != nullptr)
			break;
		coeff++;
	}
	coeff = 1;
	while (board->findFigureByPos(getX() - coeff * square_width, getY() + coeff * square_height, getIsWhite()) == nullptr && coeff < 8)
	{
		array[i++] = board->findNearestSquare(getX() - coeff * square_width, getY() + coeff * square_height);
		if (board->findFigureByPos(getX() - coeff * square_width, getY() + coeff * square_height, !getIsWhite()) != nullptr)
			break;
		coeff++;
	}
	int coeff_y = 1, coeff_x = 1;
	while (board->findFigureByPos(getX(), getY() - coeff_y * square_height, getIsWhite()) == nullptr && coeff_y < 8)
	{
		array[i++] = board->findNearestSquare(getX(), getY() - coeff_y * square_height);
		if (board->findFigureByPos(getX(), getY() - coeff_y * square_height, !getIsWhite()) != nullptr) break;
		coeff_y += 1;
	}
	coeff_y = 1;
	while (board->findFigureByPos(getX(), getY() + coeff_y * square_height, getIsWhite()) == nullptr && coeff_y < 8)
	{
		array[i++] = board->findNearestSquare(getX(), getY() + coeff_y * square_height);
		if (board->findFigureByPos(getX(), getY() + coeff_y * square_height, !getIsWhite()) != nullptr) break;
		coeff_y += 1;
	}
	while (board->findFigureByPos(getX() - coeff_x * square_width, getY(), getIsWhite()) == nullptr && coeff_x < 8)
	{
		array[i++] = board->findNearestSquare(getX() - coeff_x * square_width, getY());
		if (board->findFigureByPos(getX() - coeff_x * square_width, getY(), !getIsWhite()) != nullptr) break;
		coeff_x += 1;
	}
	coeff_x = 1;
	while (board->findFigureByPos(getX() + coeff_x * square_width, getY(), getIsWhite()) == nullptr && coeff_x < 8)
	{
		array[i++] = board->findNearestSquare(getX() + coeff_x * square_width, getY());
		if (board->findFigureByPos(getX() + coeff_x * square_width, getY(), !getIsWhite()) != nullptr) break;
		coeff_x += 1;
	}
}