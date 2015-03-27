#include "Character.h"

using namespace std;
using namespace sf;

Character::Character()
{}

Character::Character(string type, Vector2f position) : myType(type)
{
	SetCharacter(type);
	mySubRect = IntRect(0, myHeight, myWidth, myHeight);
	myTexture.loadFromFile(myFilePath);
	mySprite.setTexture(myTexture);
	mySprite.setTextureRect(mySubRect);
	mySprite.setPosition(position);
}

void Character::Move(Direction direction)
{
	if (direction == up && mySprite.getPosition().y > 0)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth, 0, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(0, -mySpeed);
		myStep += 2;
	}

	if (direction == down && mySprite.getPosition().y < 500 - myHeight)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth, myHeight, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(0, mySpeed);
		myStep += 2;
	}

	if (direction == left && mySprite.getPosition().x > 0)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth, myHeight * 2, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(-mySpeed, 0);
		myStep += 2;
	}

	if (direction == right && mySprite.getPosition().x < 800 - 18)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth, myHeight * 3, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(mySpeed, 0);
		myStep += 2;
	}
}

void Character::SetPosition(sf::Vector2f position)
{
	mySprite.setPosition(position);
}

//########### Attribut access ###########

const Sprite & Character::GetSprite() const
{
	return mySprite;
}

const string & Character::GetType() const
{
	return myType;
}

//########### Attribut setting ###########
void Character::SetType(std::string &type)
{
	SetCharacter(type);
	mySubRect = IntRect(0, myHeight, myWidth, myHeight);
	myTexture.loadFromFile(myFilePath);
	mySprite.setTexture(myTexture);
	mySprite.setTextureRect(mySubRect);
}

//############ Private functions ############

void Character::SetCharacter(string &type)
{
	if (type == "Tiv")
	{
		myFilePath = "pictures/tiv.png";
		myWidth = 18;
		myHeight = 25;
		mySpeed = 3;
		myStepMax = 80;
	}
	if (type == "Robot1")
	{
		myFilePath = "pictures/robot1.png";
		myWidth = 25;
		myHeight = 25;
		mySpeed = 2;
		myStepMax = 30;
	}
	if (type == "Robot2")
	{
		myFilePath = "pictures/robot2.png";
		myWidth = 25;
		myHeight = 25;
		mySpeed = 2;
		myStepMax = 30;
	}
}

void Character::Step0()
{
	if (myStep == myStepMax)
	{
		myStep = 0;
	}
}
