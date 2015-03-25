#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <string>

#include "Init.h"

class Level
{
public:
	Level();
	Level(int nLevel);
	void Show(sf::RenderWindow &window);
	void ChangeStatus();

	const std::vector<int> & GetTileMap() const;
	const std::vector<std::string> & GetMapAttributs() const;
	const std::map<std::string, std::string> & GetListHostiles() const;
	const int & GetNLevel() const;
	const int & GetNHostiles() const;
	const bool GetNewStatus() const;

private:
	int myNLevel;
	int myNHostiles;
	bool myNewStatus = true;
	sf::Texture myTileset;
	std::map<std::string, std::string> myListHostiles;
	std::vector<int> myTileMap;
	std::vector<std::string> myMapAttributs;

	std::string Read(std::ifstream &file);

};

#endif // LEVEL_H_INCLUDED