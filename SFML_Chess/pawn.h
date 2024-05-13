#pragma once
#include "figure.h"

class Pawn : public Figure
{
public: 
	Pawn(Board& board, TextureManager& manager, int pos_x, int pos_y, bool isWhite);
	bool move(int x, int y, int square_width, int square_height, Figure* figureAtPosition);
	void getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height);
private:
	bool is_starting;
};
