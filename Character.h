#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SFML/Graphics.hpp>

class Character
{
public:
	Character();
	Character(std::string type, sf::Vector2f position);

	enum Direction { up, down, left, right };

	void Move(Direction direction);
	void MoveAuto();
	void SetPosition(sf::Vector2f position);

	const sf::Sprite & GetSprite() const;
	const std::string & GetType() const;
	const int & GetLife() const;

	void SetType(std::string &type);

private:
	// Character's attributs
	int myTilesetPosX;
	int myTilesetPosY;
	int myWidth;
	int myHeight;
	int mySpeed;
	int myLife;
	std::string myType;

	std::string myFilePath;
	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::IntRect mySubRect;

	// Attributs for the animation of the character
	int myStep = 0;
	int myStepMax;

	void SetCharacter(std::string &type);
	void Initialization(std::string filePath, int tilesetPosX, int tilesetPosY, int width, int height, int speed, int life, int stepMax);
	void Step0();
};

#endif // CHARACTER_H_INCLUDED