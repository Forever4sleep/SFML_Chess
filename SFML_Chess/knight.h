#pragma once
#include "figure.h"

class Knight :public Figure
{
public:
	Knight(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite);
	void getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height);
};