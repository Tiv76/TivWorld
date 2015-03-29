#include "Level.h"

using namespace std;
using namespace sf;

Level::Level()
{}

Level::Level(int nLevel) : myNLevel(nLevel)
{
	string fileName = "levels/level" + to_string(myNLevel) + ".txt";
	ifstream file(fileName);

	// Initialization of the Hostile's attributs list
	int n = stoi(Read(file));
	myNHostiles = n;
	for (int i = 0; i < myNHostiles; i++)
	{
		string type = "type" + to_string(i + 1), posX = "posX" + to_string(i + 1), posY = "posY" + to_string(i + 1);
		myListHostiles[type] = Read(file);
		myListHostiles[posX] = Read(file);
		myListHostiles[posY] = Read(file);
	}
	// Recovering the tileset file's path
	myTileset.loadFromFile(Read(file));

	// Recovering tiles properties
	for (int i = 0; i < Init::NUMBER_TILES_WIDTH * Init::NUMBER_TILES_HEIGHT; i++)
	{
		string a, b;
		a = Read(file);
		b = Read(file);
		myMapAttributs.push_back(b);
	}

	// Recovoring the position to place the main character when exit/enter a house
	int x = stoi(Read(file));
	int y = stoi(Read(file));
	myDoorPos = Vector2f(x, y);

	// Recovering the tilemap
	for (int i = 0; i < Init::NUMBER_BLOCS_WIDTH * Init::NUMBER_BLOCS_HEIGHT; i++)
	{
		string a;
		a = Read(file);
		myTileMap.push_back(stoi(a));
	}
	file.close();

}

void Level::Show(RenderWindow &window)
{
	Sprite Rect;
	Rect.setTexture(myTileset);

	for (int i = 0; i < Init::NUMBER_BLOCS_WIDTH * Init::NUMBER_BLOCS_HEIGHT; i++)
	{

		Rect.setTextureRect(IntRect((myTileMap[i] - myTileMap[i] / Init::NUMBER_TILES_WIDTH * Init::NUMBER_TILES_WIDTH) * Init::TILE_WIDTH, (myTileMap[i] / Init::NUMBER_TILES_WIDTH) * Init::TILE_HEIGHT, Init::TILE_WIDTH, Init::TILE_HEIGHT));
		Rect.setPosition((i - i / Init::NUMBER_BLOCS_WIDTH * Init::NUMBER_BLOCS_WIDTH) * Init::TILE_WIDTH, i / Init::NUMBER_BLOCS_WIDTH * Init::TILE_HEIGHT);
		window.draw(Rect);
	}
}

void Level::ChangeStatus()
{
	if (myNewStatus)
		myNewStatus = false;
}

//########### Attributs Access ###########
const vector<int> & Level::GetTileMap() const
{
	return myTileMap;
}

const vector<string> & Level::GetMapAttributs() const
{
	return myMapAttributs;
}

const map<string, string> & Level::GetListHostiles() const
{
	return myListHostiles;
}

const int & Level::GetNLevel() const
{
	return myNLevel;
}

const int & Level::GetNHostiles() const
{
	return myNHostiles;
}

const bool Level::GetNewStatus() const
{
	return myNewStatus;
}

const Vector2f & Level::GetDoorPos() const
{
	return myDoorPos;
}

//############ Private Functions ############
string Level::Read(ifstream &file)
{
	string word;
	file >> word;
	return word;
}