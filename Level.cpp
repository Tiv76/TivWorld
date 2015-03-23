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
	myListHostiles["number"] = to_string(n);
	for (int i = 0; i < n; i++)
	{
		string type = "type" + to_string(i + 1), posX = "posX" + to_string(i + 1), posY = "posY" + to_string(i + 1);
		myListHostiles[type] = Read(file);
		myListHostiles[posX] = Read(file);
		myListHostiles[posY] = Read(file);
	}
	// Recovering the tileset file's path
	myTileset.loadFromFile(Read(file));

	// Recovering the number of tiles of both X and Y axis in the tileset
	myListLevelAttributs["NUMBER_TILE_X"] = Read(file);
	myListLevelAttributs["NUMBER_TILE_Y"] = Read(file);

	// Recovering the tiles size in pixels
	myListLevelAttributs["TILE_WIDTH"] =  Read(file);
	myListLevelAttributs["TILE_HEIGHT"] = Read(file);

	// Recovering tiles properties
	for (int i = 0; i < stoi(myListLevelAttributs["NUMBER_TILE_X"]) * stoi(myListLevelAttributs["NUMBER_TILE_Y"]); i++)
	{
		string a, b;
		a = Read(file);
		b = Read(file);
		myListLevelAttributs[a] = b;
	}

	// Recovering tiles number for both X and Y axis for the board
	myListLevelAttributs["numTilesX"] = Read(file);
	myListLevelAttributs["numTilesY"] = Read(file);

	for (int i = 0; i < stoi(myListLevelAttributs["numTilesX"]) * stoi(myListLevelAttributs["numTilesY"]); i++)
	{
		string a;
		a = Read(file);
		myListLevelAttributs[to_string(i)] = a;
	}
	file.close();

}

void Level::Show(RenderWindow &window)
{
	Sprite Rect;
	Rect.setTexture(myTileset);

	// Recovering values from 'myListLevelAttributs' in 'int' values
	int numTilesX = stoi(myListLevelAttributs["numTilesX"]), numTilesY = stoi(myListLevelAttributs["numTilesY"]), tile_width = stoi(myListLevelAttributs["TILE_WIDTH"]), tile_height = stoi(myListLevelAttributs["TILE_HEIGHT"]), number_tile_x = stoi(myListLevelAttributs["NUMBER_TILE_X"]);

	for (int i = 0; i < numTilesX * numTilesY; i++)
	{
		int tile = stoi(myListLevelAttributs[to_string(i)]); // Recovering the active tile value in an 'int' value

		Rect.setTextureRect(IntRect((tile - tile / number_tile_x * number_tile_x) * tile_width, (tile / number_tile_x) * tile_height, tile_width, tile_height));
		Rect.setPosition((i - i / numTilesX * numTilesX) * tile_width, i / numTilesX * tile_height);
		window.draw(Rect);
	}
}

//########### Attributs Access ###########

const map<string, string>& Level::GetList() const
{
	return  myListLevelAttributs;
}

const map<string, string>& Level::GetListHostiles() const
{
	return myListHostiles;
}

const int Level::GetNLevel() const
{
	return myNLevel;
}

//############ Private Functions ############

string Level::Read(ifstream &file)
{
	string word;
	file >> word;
	return word;
}

//############ Other Functions #############
