#include "ExitManager.h"

using namespace std;
using namespace sf;


ExitManager::ExitManager(Character &character, Level &level) : myCharacter(character), myLevel(level)
{}

void ExitManager::PositionTest()
{
	Sprite sprite = myCharacter.GetSprite();
	vector<int> tileMap = myLevel.GetTileMap();
	vector<string> mapAttributs = myLevel.GetMapAttributs();

	int posX = sprite.getPosition().x, posY = sprite.getPosition().y;
	int nTile = (posX + Init::TIV_WIDTH / 2) / Init::TILE_WIDTH + ((posY + Init::TIV_HEIGHT / 2) / Init::TILE_HEIGHT) * Init::NUMBER_BLOCS_WIDTH;

	if (mapAttributs[tileMap[nTile]] == "right")
	{
		myLevel = Level(myLevel.GetNLevel() + 1);
		myCharacter.SetPosition(Vector2f(25, posY));
	}
	if (mapAttributs[tileMap[nTile]] == "left")
	{
		myLevel = Level(myLevel.GetNLevel() - 1);
		myCharacter.SetPosition(Vector2f(750, posY));
	}
	if (mapAttributs[tileMap[nTile]] == "up")
	{
		myLevel = Level(myLevel.GetNLevel() - 10);
		myCharacter.SetPosition(Vector2f(posX, 450));
	}
	if (mapAttributs[tileMap[nTile]] == "down")
	{
		myLevel = Level(myLevel.GetNLevel() + 10);
		myCharacter.SetPosition(Vector2f(posX, 20));
	}
}