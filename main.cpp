#include <SFML/Graphics.hpp>

#include "Init.h"
#include "Game.h"

using namespace sf;
using namespace std;



int main()
{
	// Initialization of the main Window
	RenderWindow app(VideoMode(800, 525, 32), "Tiv's World");
	app.setFramerateLimit(60);

	Game game(app);
	game.Run();

	return EXIT_SUCCESS;
}