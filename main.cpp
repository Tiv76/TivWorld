#include <SFML/Graphics.hpp>

#include "Niveau.h"

using namespace sf;
using namespace std;



int main()
{
	const int LARGEUR_TILE = 25; // hauteur et largeur des tiles en pixels
	const int HAUTEUR_TILE = 25;

	const int NOMBRE_BLOCS_LARGEUR = 32; // nombre de tiles � afficher en x et y
	const int NOMBRE_BLOCS_HAUTEUR = 20;

	//srand(time(0));
	Niveau niv = Niveau(2);
	map<string, string> tableNiveau = niv.GetTable();


	// Cr�ation de la fen�tre principale
	RenderWindow app(VideoMode(LARGEUR_TILE * NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE * NOMBRE_BLOCS_HAUTEUR, 32), "Tiv's World");
	app.setFramerateLimit(60);

	// Boucle principale du jeu
	while (app.isOpen())
	{
		// Gestion des �v�nements
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

		// Affichage des �l�ments
		niv.Affiche(app);

		// Rafraichissement de la fen�tre
		app.display();
	}

	return EXIT_SUCCESS;
}