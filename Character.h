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

	void SetType(std::string &type);

private:
	// Character's attributs
	int myWidth;
	int myHeight;
	int mySpeed;
	std::string myType;

	std::string myFilePath;
	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::IntRect mySubRect;

	// Attributs for the animation of the character
	int myStep = 0;
	int myStepMax;

	// Attributs for random movements of hostiles
	int myTime = 0;
	int myT;
	Direction myRandomDirection;

	void SetCharacter(std::string &type);
	void Step0();
};

#endif // CHARACTER_H_INCLUDED