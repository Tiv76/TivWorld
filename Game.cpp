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
void Game::InitHostiles()
{
	myNHostiles = myLevel.GetNHostiles();
	map<string, string> myListHostiles = myLevel.GetListHostiles();

	if (myNHostiles >= 1)
	{
		myHostile1.SetType(myListHostiles["type1"]);
		myHostile1.SetPosition(Vector2f(stoi(myListHostiles["posX1"]), stoi(myListHostiles["posY1"])));
	}
	if (myNHostiles >= 2)
	{
		myHostile2.SetType(myListHostiles["type2"]);
		myHostile2.SetPosition(Vector2f(stoi(myListHostiles["posX2"]), stoi(myListHostiles["posY2"])));
	}
	if (myNHostiles >= 3)
	{
		myHostile3.SetType(myListHostiles["type3"]);
		myHostile3.SetPosition(Vector2f(stoi(myListHostiles["posX3"]), stoi(myListHostiles["posY3"])));
	}
	if (myNHostiles >= 4)
	{
		myHostile4.SetType(myListHostiles["type4"]);
		myHostile4.SetPosition(Vector2f(stoi(myListHostiles["posX4"]), stoi(myListHostiles["posY4"])));
	}
	myLevel.ChangeStatus();
}

void Game::Render()
{
	// Clear screen
	myWindow.clear();

	// Draw the sprites
	myLevel.Show(myWindow);
	myWindow.draw(myTiv.GetSprite());
	
	// Showing enemies according to their number on the map
	if (myNHostiles >= 1)
		myWindow.draw(myHostile1.GetSprite());
	if (myNHostiles >= 2)
		myWindow.draw(myHostile2.GetSprite());
	if (myNHostiles >= 3)
		myWindow.draw(myHostile3.GetSprite());
	if (myNHostiles >= 4)
		myWindow.draw(myHostile4.GetSprite());

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
		if (myLevel.GetNewStatus())
			InitHostiles();
		MoveHostiles();
		Render();
	}
}

void Game::MoveHostiles()
{
	if (myNHostiles >= 1)
		myHostile1.MoveAuto();
	if (myNHostiles >= 2)
		myHostile2.MoveAuto();
	if (myNHostiles >= 3)
		myHostile3.MoveAuto();
	if (myNHostiles >= 4)
		myHostile4.MoveAuto();
}