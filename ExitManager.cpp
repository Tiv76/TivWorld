#include "ExitManager.h"

using namespace std;
using namespace sf;


ExitManager::ExitManager(Character &character, Level &level) : myCharacter(character), myLevel(level)
{}

void ExitManager::PositionTest()
{
	Sprite sprite = myCharacter.GetSprite();
	map<string, string> levelList = myLevel.GetList();
	int width = sprite.getGlobalBounds().width, height = sprite.getGlobalBounds().height;
	int posX = sprite.getPosition().x, posY = sprite.getPosition().y, nTile = (posX + width / 2) / 25 + ((posY + height / 2) / 25) * 32;
	string tile = "tile" + levelList[to_string(nTile)];

	if (levelList[tile] == "right" && myCharacter.GetType() == "Tiv")
	{
		myLevel = Level(myLevel.GetNLevel() + 1);
		myCharacter.SetPosition(Vector2f(25, posY));
	}
	if (levelList[tile] == "left" && myCharacter.GetType() == "Tiv")
	{
		myLevel = Level(myLevel.GetNLevel() - 1);
		myCharacter.SetPosition(Vector2f(750, posY));
	}
	if (levelList[tile] == "up" && myCharacter.GetType() == "Tiv")
	{
		myLevel = Level(myLevel.GetNLevel() - 10);
		myCharacter.SetPosition(Vector2f(posX, 450));
	}
	if (levelList[tile] == "down" && myCharacter.GetType() == "Tiv")
	{
		myLevel = Level(myLevel.GetNLevel() + 10);
		myCharacter.SetPosition(Vector2f(posX, 25));
	}
}