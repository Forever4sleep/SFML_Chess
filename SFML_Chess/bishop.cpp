#include "bishop.h"
#include "board.h"

Bishop::Bishop(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite):Figure(board, TM.getBishopTexture("Bishop", isWhite), Type::Bishop, pos_x, pos_y, isWhite)
{
}

void Bishop::getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height)
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
}