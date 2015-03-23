#ifndef KEYBOARDMANAGER_H_INCLUDED
#define KEYBOARDMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Character.h"
#include "CollisionManager.h"

class KeyboardManager
{
public:
	KeyboardManager(Character &character, CollisionManager &colManager);
	void Action();

private:
	Character &myCharacter;
	CollisionManager &myColManager;
};

#endif // KEYBOARDMANAGER_H_INCLUDED