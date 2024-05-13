#pragma once
#include "figure.h"
#include "texture_manager.h"


class Board
{
private:
	sf::Sprite sprite;
	sf::Vector2u* markers;
	sf::CircleShape* markers_shapes;
	int markerks_count;
	void createFiguresSet(TextureManager& manager, int square_width, int square_height);
public:
	Board(sf::RenderWindow& window, TextureManager& manager, int square_width, int square_height);
	Figure* figures[32];
	Figure* currentFigure;
	Figure* findFigureByPos(int x, int y, bool shouldBeWhite);
	Figure* findFigureByPos(int x, int y);
	sf::Sprite getBoardSprite();
	sf::Vector2u findNearestSquare(int x, int y);
	void doPositionReset(int square_width, int square_height);
	void drawFigures(sf::RenderWindow& window);
	void mark(sf::RenderWindow& window, int square_width, int square_height);
	void updateMarks(int square_width, int square_height);
};