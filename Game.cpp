#include "Game.h"

using namespace std;
using namespace sf;

Game::Game(sf::RenderWindow &window) : myWindow(window)
{}

void Game::Run()
{
	Update();
}

//############ Private Functions ############
void Game::Render()
{
	// Clear screen
	myWindow.clear();

	// Draw the sprites
	myLevel.Show(myWindow);
	myWindow.draw(myTiv.GetSprite());

	// Update the myWindow
	myWindow.display();
}

void Game::Update()
{
	Event event;

	// Main loop
	while (myWindow.isOpen())
	{
		// Event Manager
		while (myWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				myWindow.close();
				break;
			}
			case Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case Keyboard::Escape:
				{
					myWindow.close();
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
		myKeyboard.Action();
		myExitManager.PositionTest();
		Render();
	}
}