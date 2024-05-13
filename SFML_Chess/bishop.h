#pragma once
#include "figure.h"

class Bishop :public Figure
{
public:
	Bishop(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite);
	void getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height);
};