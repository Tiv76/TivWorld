#include "KeyboardManager.h"

using namespace std;
using namespace sf;

KeyboardManager::KeyboardManager(Character &character, CollisionManager &colManager) : myCharacter(character), myColManager(colManager)
{}

void KeyboardManager::Action()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) && myColManager.CollisionTest(Character::up))
		myCharacter.Move(Character::up);

	if (Keyboard::isKeyPressed(Keyboard::Down) && myColManager.CollisionTest(Character::down))
		myCharacter.Move(Character::down);

	if (Keyboard::isKeyPressed(Keyboard::Left) && myColManager.CollisionTest(Character::left))
		myCharacter.Move(Character::left);

	if (Keyboard::isKeyPressed(Keyboard::Right) && myColManager.CollisionTest(Character::right))
		myCharacter.Move(Character::right);
}

void KeyboardManager::MoveAuto()
{
	if (myTime == myT)
		myTime = 0;
	if (myTime == 0)
	{
		RandomDir();
	}
	if (myColManager.CollisionTest(myRandomDirection))
		myCharacter.Move(myRandomDirection);

	myTime++;
}

void KeyboardManager::RandomDir()
{
	int dir = rand() % 4;
	myT = rand() % 30 + 10;
	if (dir == 0)
		myRandomDirection = Character::up;
	else if (dir == 1)
		myRandomDirection = Character::down;
	else if (dir == 2)
		myRandomDirection = Character::left;
	else if (dir == 3)
		myRandomDirection = Character::right;
}