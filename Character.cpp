#include "Character.h"

using namespace std;
using namespace sf;

Character::Character()
{}

Character::Character(string type, Vector2f position) : myType(type)
{
	SetCharacter(type);
	mySubRect = IntRect(myTilesetPosX, myTilesetPosY, myWidth, myHeight);
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
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth + myTilesetPosX, myHeight * 3 + myTilesetPosY, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(0, -mySpeed);
		myStep += 2;
	}

	if (direction == down && mySprite.getPosition().y + myHeight < 500)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth + myTilesetPosX, 0 + myTilesetPosY, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(0, mySpeed);
		myStep += 2;
	}

	if (direction == left && mySprite.getPosition().x > 0)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth + myTilesetPosX, myHeight + myTilesetPosY, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
		mySprite.move(-mySpeed, 0);
		myStep += 2;
	}

	if (direction == right && mySprite.getPosition().x < 800 - 30)
	{
		Step0();
		mySprite.setTextureRect(IntRect(myStep / 10 * myWidth + myTilesetPosX, myHeight * 2 + myTilesetPosY, myWidth, myHeight)); // Changing the sprite texture corresponding to the direction of the character
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

const int & Character::GetLife() const
{
	return myLife;
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
		Initialization("pictures/tiv.png", 192, 0, 32, 32, 3, 6, 30);
	else if (type == "Zombie1")
		Initialization("pictures/zombie.png", 0, 0, 32, 32, 2, 4, 30);
	else if (type == "Zombie2")
		Initialization("pictures/zombie.png", 96, 0, 32, 32, 2, 4, 30);
	else if (type == "Zombie3")
		Initialization("pictures/zombie.png", 192, 0, 32, 32, 2, 4, 30);
	else if (type == "Zombie4")
		Initialization("pictures/zombie.png", 288, 0, 32, 32, 2, 4, 30);
	else if (type == "Zombie5")
		Initialization("pictures/zombie.png", 0, 128, 32, 32, 2, 4, 30);
	else if (type == "Zombie6")
		Initialization("pictures/zombie.png", 96, 128, 32, 32, 2, 4, 30);
	else if (type == "Zombie7")
		Initialization("pictures/zombie.png", 192, 128, 32, 32, 2, 4, 30);
	else if (type == "Zombie8")
		Initialization("pictures/zombie.png", 288, 128, 32, 32, 2, 4, 30);
}

void Character::Initialization(string filePath, int tilesetPosX, int tilesetPosY, int width, int height, int speed, int life, int stepMax)
{
	myFilePath = filePath;
	myTilesetPosX = tilesetPosX;
	myTilesetPosY = tilesetPosY;
	myWidth = width;
	myHeight = height;
	mySpeed = speed;
	myLife = life;
	myStepMax = stepMax;
}

void Character::Step0()
{
	if (myStep == myStepMax)
	{
		myStep = 0;
	}
}
