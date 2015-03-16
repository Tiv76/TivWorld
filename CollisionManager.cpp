#include "CollisionManager.h"

using namespace std;
using namespace sf;

CollisionManager::CollisionManager(Character &character, Level &level) : myCharacter(character), myLevel(level)
{}

//############ Private Functions ############

bool CollisionManager::CollisionTest(Character::Direction direction)
{
	Sprite sprite = myCharacter.GetSprite();
	int posX = sprite.getPosition().x, posY = sprite.getPosition().y, nTile, width = sprite.getGlobalBounds().width, height = sprite.getGlobalBounds().height;
	string tile;
	map<string, string> levelList = myLevel.GetList();

	if (direction == Character::up)
	{
		nTile = (posX + width - 3) / 25 + (posY / 25) * 32;
		tile = "tile" + levelList[to_string(nTile)];
		if (TileTest(levelList[tile]))
		{
			nTile = (posX + 3) / 25 + (posY / 25) * 32;
			tile = "tile" + levelList[to_string(nTile)];
			return TileTest(levelList[tile]);
		}
	}
	if (direction == Character::down)
	{
		nTile = (posX + width - 3) / 25 + ((posY + height) / 25) * 32;
		tile = "tile" + levelList[to_string(nTile)];
		if (TileTest(levelList[tile]))
		{
			nTile = (posX + 3) / 25 + ((posY + height) / 25) * 32;
			tile = "tile" + levelList[to_string(nTile)];
			return TileTest(levelList[tile]);
		}
	}
	if (direction == Character::left)
	{
		nTile = posX / 25 + ((posY + height - 3) / 25) * 32;
		tile = "tile" + levelList[to_string(nTile)];
		if (TileTest(levelList[tile]))
		{
			nTile = posX / 25 + ((posY + 3) / 25) * 32;
			tile = "tile" + levelList[to_string(nTile)];
			return TileTest(levelList[tile]);
		}
	}
	if (direction == Character::right)
	{
		nTile = (posX + width) / 25 + ((posY + height - 3) / 25) * 32;
		tile = "tile" + levelList[to_string(nTile)];
		if (TileTest(levelList[tile]))
		{
			nTile = (posX + width) / 25 + ((posY + 3) / 25) * 32;
			tile = "tile" + levelList[to_string(nTile)];
			return TileTest(levelList[tile]);
		}
	}
	return false;
}

bool CollisionManager::TileTest(std::string tileValue)
{
	return (tileValue == "grass" || tileValue == "threshold" || tileValue == "up" || tileValue == "down" || tileValue == "left" || tileValue == "right" || tileValue == "door");
}