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
	void MoveAuto();

private:
	Character &myCharacter;
	CollisionManager &myColManager;

	// Attributs for random movements of hostiles
	int myTime = 0;
	int myT;
	Character::Direction myRandomDirection;

	void RandomDir();
};

#endif // KEYBOARDMANAGER_H_INCLUDED