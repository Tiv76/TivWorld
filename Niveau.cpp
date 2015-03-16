#include "Niveau.h"

using namespace std;
using namespace sf;

Niveau::Niveau(int nNiveau) : myNNiveau(nNiveau)
{
	string nomFichier = "niveaux/level" + to_string(myNNiveau) + ".txt";
	ifstream fichier(nomFichier);

	// Création de la liste des attributs des méchants
	int n = stoi(Lecture(fichier));
	myTableMechants["nombre"] = to_string(n);
	for (int i = 0; i < n; i++)
	{
		string type = "type" + to_string(i + 1), posX = "posX" + to_string(i + 1), posY = "posY" + to_string(i + 1);
		myTableMechants[type] = Lecture(fichier);
		myTableMechants[posX] = Lecture(fichier);
		myTableMechants[posY] = Lecture(fichier);
	}
	// Récupération du chemin du fichier tileset
	myTileset.loadFromFile(Lecture(fichier));

	// Récupération des nomvres de tiles en X et Y dans le tileset
	myTable["NOMBRE_TILE_X"] = Lecture(fichier);
	myTable["NOMBRE_TILE_Y"] = Lecture(fichier);

	// Récupération des dimensions en pixels des tiles
	myTable["LARGEUR_TILE"] = Lecture(fichier);
	myTable["HAUTEUR_TILE"] = Lecture(fichier);

	// Récupération des propriétés des tiles
	for (int i = 0; i < stoi(myTable["NOMBRE_TILE_X"]) * stoi(myTable["NOMBRE_TILE_Y"]); i++)
	{
		string a, b;
		a = Lecture(fichier);
		b = Lecture(fichier);
		myTable[a] = b;
	}

	// Récupération des nombres de tiles en X et Y pour le tableau
	myTable["nbTilesX"] = Lecture(fichier);
	myTable["nbTilesY"] = Lecture(fichier);

	for (int i = 0; i < stoi(myTable["nbTilesX"]) * stoi(myTable["nbTilesY"]); i++)
	{
		string a;
		a = Lecture(fichier);
		myTable[to_string(i)] = a;
	}
	fichier.close();

}

void Niveau::Affiche(RenderWindow &fenetre)
{
	Sprite Rect;
	Rect.setTexture(myTileset);

	// Récupération de valeurs depuis 'myTable' dans des 'int' pour simplifier le contenu de la boucle 'for'
	int nbTilesX = stoi(myTable["nbTilesX"]), nbTilesY = stoi(myTable["nbTilesY"]), largeur_tile = stoi(myTable["LARGEUR_TILE"]), hauteur_tile = stoi(myTable["HAUTEUR_TILE"]), nombre_tile_x = stoi(myTable["NOMBRE_TILE_X"]);

	for (int i = 0; i < nbTilesX * nbTilesY; i++)
	{
		int tile = stoi(myTable[to_string(i)]); // Récupération de la valeur du Tile en cours dans un 'int' pour simplifier le contenu de la boucle 'for'

		Rect.setTextureRect(IntRect((tile - tile / nombre_tile_x * nombre_tile_x) * largeur_tile, (tile / nombre_tile_x) * hauteur_tile, largeur_tile, hauteur_tile));
		Rect.setPosition((i - i / nbTilesX * nbTilesX) * largeur_tile, i / nbTilesX * hauteur_tile);
		fenetre.draw(Rect);
	}
}

//########### Accès aux attributs ###########

const map<string, string>& Niveau::GetTable() const
{
	return  myTable;
}

const map<string, string>& Niveau::GetTableMechants() const
{
	return myTableMechants;
}

const int Niveau::GetNNiveau() const
{
	return myNNiveau;
}

//############ Fonctions Privées ############

string Niveau::Lecture(ifstream &fichier)
{
	string mot;
	fichier >> mot;
	return mot;
}

//############ Autres Fonctions #############
