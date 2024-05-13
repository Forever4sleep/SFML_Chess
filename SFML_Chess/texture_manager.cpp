#include "texture_manager.h"
#include <iostream>

TextureManager TM;

void TextureManager::InitializeTextures()
{
	this->boardTexture = *(new sf::Texture());
	this->boardTexture.create(700, 700);
	this->boardTexture.loadFromFile("board.png");
	
	this->rookTexture = *(new sf::Texture());
	this->rookTexture.create(1, 1);
	this->rookTexture.loadFromFile("rook.png");

	this->rookTextureWhite = *(new sf::Texture());
	this->rookTextureWhite.create(50, 50);
	this->rookTextureWhite.loadFromFile("rook_white.png");

	this->knightTexture = *(new sf::Texture());
	this->knightTexture.create(87, 30);
	this->knightTexture.loadFromFile("knight.png");

	this->knightTextureWhite = *(new sf::Texture());
	this->knightTextureWhite.create(87, 30);
	this->knightTextureWhite.loadFromFile("knight_white.png");

	this->kingTexture = *(new sf::Texture());
	this->kingTexture.create(87, 30);
	this->kingTexture.loadFromFile("king.png");

	this->kingTextureWhite = *(new sf::Texture());
	this->kingTextureWhite.create(87, 30);
	this->kingTextureWhite.loadFromFile("king_white.png");

	this->pawnTexture = *(new sf::Texture());
	this->pawnTexture.create(87, 30);
	this->pawnTexture.loadFromFile("pawn.png");

	this->pawnTextureWhite = *(new sf::Texture());
	this->pawnTextureWhite.create(87, 30);
	this->pawnTextureWhite.loadFromFile("pawn_white.png");

	this->bishopTexture = *(new sf::Texture());
	this->bishopTexture.create(87, 30);
	this->bishopTexture.loadFromFile("bishop.png");

	this->bishopTextureWhite = *(new sf::Texture());
	this->bishopTextureWhite.create(87, 30);
	this->bishopTextureWhite.loadFromFile("bishop_white.png");

	this->queenTexture = *(new sf::Texture());
	this->queenTexture.create(87, 30);
	this->queenTexture.loadFromFile("queen.png");

	this->queenTextureWhite = *(new sf::Texture());
	this->queenTextureWhite.create(87, 30);
	this->queenTextureWhite.loadFromFile("queen_white.png");
}
TextureManager::TextureManager()
{
	this->InitializeTextures();
}

sf::Texture& TextureManager::getBoardTexture() { return this->boardTexture; }
sf::Texture& TextureManager::getPawnTexture() { return this->pawnTexture; }
sf::Texture& TextureManager::getPawnTextureWhite() { return this->pawnTextureWhite; }
sf::Texture& TextureManager::getBishopTexture() { return this->bishopTexture; }
sf::Texture& TextureManager::getBishopTextureWhite() { return this->bishopTextureWhite; }
sf::Texture& TextureManager::getRookTexture() { return this->rookTexture; }
sf::Texture& TextureManager::getRookTextureWhite() { return this->rookTextureWhite; }
sf::Texture& TextureManager::getKingTexture() { return this->kingTexture; }
sf::Texture& TextureManager::getKingTextureWhite() { return this->kingTextureWhite; }
sf::Texture& TextureManager::getQueenTexture() { return this->queenTexture; }
sf::Texture& TextureManager::getQueenTextureWhite() { return this->queenTextureWhite; }
sf::Texture& TextureManager::getKnightTexture() { return this->knightTexture; }
sf::Texture& TextureManager::getKnightTextureWhite() { return this->knightTextureWhite; }