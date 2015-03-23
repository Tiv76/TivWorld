#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <string>

class Level
{
public:
	Level();
	Level(int nLevel);
	void Show(sf::RenderWindow &window);

	const std::map<std::string, std::string>& GetList() const;
	const std::map<std::string, std::string>& GetListHostiles() const;
	const int GetNLevel() const;

private:
	int myNLevel;
	sf::Texture myTileset;
	std::map<std::string, std::string> myListLevelAttributs;
	std::map<std::string, std::string> myListHostiles;

	std::string Read(std::ifstream &file);

};

#endif // LEVEL_H_INCLUDED