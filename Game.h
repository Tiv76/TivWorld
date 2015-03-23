#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Init.h"
#include "Level.h"
#include "Character.h"
#include "CollisionManager.h"
#include "KeyboardManager.h"
#include "ExitManager.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	void Run();

private:
	sf::RenderWindow &myWindow;
	Level &myLevel = Level(Init::LEVEL_N);
	Character &myTiv = Character("Tiv", sf::Vector2f(Init::POS_X, Init::POS_Y));
	CollisionManager &myColManager = CollisionManager(myTiv, myLevel);
	KeyboardManager &myKeyboard = KeyboardManager(myTiv, myColManager);
	ExitManager &myExitManager = ExitManager(myTiv, myLevel);

	void Render();
	void Update();
};

#endif // GAME_H_INCLUDED