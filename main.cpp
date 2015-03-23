#include <SFML/Graphics.hpp>

#include "Init.h"
#include "Game.h"

using namespace sf;
using namespace std;



int main()
{
	//ExitManager tivExit(tiv, level);

	// Initialization of the main Window
	RenderWindow app(VideoMode(Init::TILE_WIDTH * Init::NUMBER_BLOCS_WIDTH, Init::TILE_HEIGHT * Init::NUMBER_BLOCS_HEIGHT, 32), "Tiv's World");
	app.setFramerateLimit(60);

	Game game(app);
	game.Run();

	return EXIT_SUCCESS;
}