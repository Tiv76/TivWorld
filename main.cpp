#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Character.h"
#include "CollisionManager.h"
#include "ExitManager.h"
#include "Init.h"

using namespace sf;
using namespace std;



int main()
{

	Level level = Level(Init::LEVEL_N);

	Character tiv("Tiv", Vector2f(Init::POS_X, Init::POS_Y));
	CollisionManager tivCol(tiv, level);
	ExitManager tivExit(tiv, level);

	// Initialization of the main Window
	RenderWindow app(VideoMode(Init::TILE_WIDTH * Init::NUMBER_BLOCS_WIDTH, Init::TILE_HEIGHT * Init::NUMBER_BLOCS_HEIGHT, 32), "Tiv's World");
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

		if (Keyboard::isKeyPressed(Keyboard::Up) && tivCol.CollisionTest(Character::up))
			tiv.Move(Character::up);

		if (Keyboard::isKeyPressed(Keyboard::Down) && tivCol.CollisionTest(Character::down))
			tiv.Move(Character::down);

		if (Keyboard::isKeyPressed(Keyboard::Left) && tivCol.CollisionTest(Character::left))
			tiv.Move(Character::left);

		if (Keyboard::isKeyPressed(Keyboard::Right) && tivCol.CollisionTest(Character::right))
			tiv.Move(Character::right);

		tivExit.PositionTest();

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