#include <SFML/Graphics.hpp>

#include "Niveau.h"

using namespace sf;
using namespace std;



int main()
{
	const int LARGEUR_TILE = 25; // hauteur et largeur des tiles en pixels
	const int HAUTEUR_TILE = 25;

	const int NOMBRE_BLOCS_LARGEUR = 32; // nombre de tiles à afficher en x et y
	const int NOMBRE_BLOCS_HAUTEUR = 20;

	//srand(time(0));
	Niveau niv = Niveau(2);
	map<string, string> tableNiveau = niv.GetTable();


	// Création de la fenêtre principale
	RenderWindow app(VideoMode(LARGEUR_TILE * NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE * NOMBRE_BLOCS_HAUTEUR, 32), "Tiv's World");
	app.setFramerateLimit(60);

	// Boucle principale du jeu
	while (app.isOpen())
	{
		// Gestion des évènements
		Event event;
		while (app.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				app.close();
				break;
			}
			case Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:
				{
					app.close();
					break;
				}
				default:
					break;
				}
			}
			break;

			default:
				break;
			}
		}

		app.clear();

		// Affichage des éléments
		niv.Affiche(app);

		// Rafraichissement de la fenêtre
		app.display();
	}

	return EXIT_SUCCESS;
}