#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Character.h"

using namespace sf;
using namespace std;



int main()
{
	const int TILE_WIDTH = 25; // height and width of each tiles in pixels
	const int TILE_HEIGHT = 25;

	const int NUMBER_BLOCS_WIDTH = 32; // number of tiles to display on both x and y axis
	const int NUMBER_BLOCS_HEIGHT = 20;

	Level level = Level(2);

	Character tiv("Tiv", Vector2f(400, 300));

	// Initialization of the main Window
	RenderWindow app(VideoMode(TILE_WIDTH * NUMBER_BLOCS_WIDTH, TILE_HEIGHT * NUMBER_BLOCS_HEIGHT, 32), "Tiv's World");
	app.setFramerateLimit(60);

	Event event;

	// Main loop
	while (app.isOpen())
	{
		// Event Manager
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

		// Clear screen
		app.clear();

		// Draw the sprites
		level.Show(app);
		app.draw(tiv.GetSprite());
		
		// Update the window
		app.display();
	}

	return EXIT_SUCCESS;
}