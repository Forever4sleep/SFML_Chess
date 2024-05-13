#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.h"
#include "bishop.h"
#include "rook.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include "figures.h"
#include "window_consts.h"
#include "texture_manager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "My chess game", sf::Style::Close | sf::Style::Titlebar);
	TextureManager manager;
	Board board(window, manager, square_width, square_height);

	sf::Sprite sprite(board.getBoardSprite());
	bool whitesTurn = true;

	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				Figure* figure = board.findFigureByPos(event.mouseButton.x, event.mouseButton.y, whitesTurn);
				if (figure == nullptr)
				{
					if (board.currentFigure != nullptr)
					{
						sf::Vector2u square = board.findNearestSquare(event.mouseButton.x, event.mouseButton.y);
						if (board.currentFigure->move(square.x, square.y, square_width, square_height, board.findFigureByPos(square.x, square.y)))
						{
							board.currentFigure = nullptr;
							board.updateMarks(square_width, square_height);
							whitesTurn = !whitesTurn;
						}
					}
				}
				else
				{
				    board.currentFigure = figure;
					board.updateMarks(square_width, square_height);
				}
			}
		}
		window.draw(sprite);
		board.drawFigures(window);
		board.mark(window, square_width, square_height);
		window.display();
	}
}