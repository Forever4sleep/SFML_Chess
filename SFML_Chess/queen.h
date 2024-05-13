#pragma once
#include "figure.h"

class Queen :public Figure
{
public:
	Queen(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite);
	void getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height);
};