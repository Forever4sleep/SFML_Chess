#include <SFML/Graphics.hpp>
#include <iostream>
#include "texture_manager.h"
#pragma once

class Board;

class Figure
{
public:
    enum Type
	{
		Pawn,
		Knight,
		Bishop,
		King,
		Queen,
		Rook
	};

	Figure(Board& board, TextureManager& manager, Type type, int pos_x, int pos_y, bool isWhite);
	Figure();

	sf::Sprite& getSprite();

	virtual bool move(int x, int y, int square_width, int square_height, Figure* figureAtPosition);
	virtual void getAllAvailabePositions(sf::Vector2u* array, int square_width, int square_height) = 0;
	int getX();
	int getY();
	bool getIsWhite();
	bool getIsDead();
	bool setX(int value);
	bool setY(int value);
	bool setPosition(int x, int y);
	void setDead();
	Type getType();
protected:
	Board* board;
private: 
	sf::Sprite sprite;
	Type type;
	int pos_x, pos_y;
	bool isWhite;
	bool isDead;
};