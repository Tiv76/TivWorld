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