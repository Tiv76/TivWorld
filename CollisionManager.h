#ifndef COLLISIONMANAGER_H_INCLUDED
#define COLLISIONMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Level.h"
#include "Init.h"

class CollisionManager
{
public:
	CollisionManager();
	CollisionManager(Character &character, Level &level);
	bool CollisionTest(Character::Direction direction);

private:
	Character &myCharacter;
	Level &myLevel;

	bool TileTest(std::string tileValue);
};

#endif // COLLISIONMANAGER_H_INCLUDED