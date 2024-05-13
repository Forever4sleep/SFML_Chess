#include <SFML/Graphics.hpp>
#pragma once

class TextureManager
{
private: 
	sf::Texture boardTexture;
	sf::Texture pawnTexture;
	sf::Texture pawnTextureWhite;
	sf::Texture bishopTexture;
	sf::Texture bishopTextureWhite;
	sf::Texture rookTexture;
	sf::Texture rookTextureWhite;
	sf::Texture kingTexture;
	sf::Texture kingTextureWhite;
	sf::Texture queenTexture;
	sf::Texture queenTextureWhite;
	sf::Texture knightTexture;
	sf::Texture knightTextureWhite;
	void InitializeTextures();

public:
	TextureManager();
	sf::Texture& getBoardTexture();
	sf::Texture& getPawnTexture();
	sf::Texture& getPawnTextureWhite();
	sf::Texture& getBishopTexture();
	sf::Texture& getBishopTextureWhite();
	sf::Texture& getRookTexture();
	sf::Texture& getRookTextureWhite();
	sf::Texture& getKingTexture();
	sf::Texture& getKingTextureWhite();
	sf::Texture& getQueenTexture();
	sf::Texture& getQueenTextureWhite();
	sf::Texture& getKnightTexture();
	sf::Texture& getKnightTextureWhite();
};

extern TextureManager TM;