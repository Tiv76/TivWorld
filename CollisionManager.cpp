#include "CollisionManager.h"

using namespace std;
using namespace sf;

CollisionManager::CollisionManager() : myCharacter(Character()), myLevel(Level())
{}

CollisionManager::CollisionManager(Character &character, Level &level) : myCharacter(character), myLevel(level)
{}

//############ Private Functions ############

bool CollisionManager::CollisionTest(Character::Direction direction)
{
	Sprite sprite = myCharacter.GetSprite();
	int posX = sprite.getPosition().x, posY = sprite.getPosition().y, width = sprite.getLocalBounds().width, height = sprite.getLocalBounds().height, nTile;
	vector<int> tileMap = myLevel.GetTileMap();
	vector<string> mapAttributs = myLevel.GetMapAttributs();

	if (direction == Character::up)
	{
		nTile = (posX + width - 3) / Init::TILE_WIDTH + (posY / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
		if (TileTest(mapAttributs[tileMap[nTile]]))
		{
			nTile = (posX + 3) / Init::TILE_WIDTH + (posY / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
			return TileTest(mapAttributs[tileMap[nTile]]);
		}
	}
	if (direction == Character::down)
	{
		nTile = (posX + width - 3) / Init::TILE_WIDTH + ((posY + height) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
		if (TileTest(mapAttributs[tileMap[nTile]]))
		{
			nTile = (posX + 3) / Init::TILE_WIDTH + ((posY + height) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
			return TileTest(mapAttributs[tileMap[nTile]]);
		}
	}
	if (direction == Character::left)
	{
		nTile = posX / Init::TILE_WIDTH + ((posY + height - 3) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
		if (TileTest(mapAttributs[tileMap[nTile]]))
		{
			nTile = posX / Init::TILE_WIDTH + ((posY + 3) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
			return TileTest(mapAttributs[tileMap[nTile]]);
		}
	}
	if (direction == Character::right)
	{
		nTile = (posX + width) / Init::TILE_WIDTH + ((posY + height - 3) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
		if (TileTest(mapAttributs[tileMap[nTile]]))
		{
			nTile = (posX + width) / Init::TILE_WIDTH + ((posY + 3) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;
			return TileTest(mapAttributs[tileMap[nTile]]);
		}
	}
	return false;
}

bool CollisionManager::TileTest(string tileValue)
{
	return (tileValue == "grass" || tileValue == "threshold" || tileValue == "up" || tileValue == "down" || tileValue == "left" || tileValue == "right" || tileValue == "doorIn");
}