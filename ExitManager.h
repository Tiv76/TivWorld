#ifndef EXITMANAGER_H_INCLUDED
#define EXITMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Level.h"

class ExitManager
{
public:
	ExitManager(Character &character, Level &level);
	void PositionTest();

private:
	Character &myCharacter;
	Level &myLevel;
};

#endif // EXITMANAGER_H_INCLUDED