#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <string>

class Niveau
{
public:
	Niveau(int nNiveau);
	void Affiche(sf::RenderWindow &fenetre);

	const std::map<std::string, std::string>& GetTable() const;
	const std::map<std::string, std::string>& GetTableMechants() const;
	const int GetNNiveau() const;

private:
	int myNNiveau;
	sf::Texture myTileset;
	std::map<std::string, std::string> myTable;
	std::map<std::string, std::string> myTableMechants;

	std::string Lecture(std::ifstream &fichier);

};

#endif // NIVEAU_H_INCLUDED