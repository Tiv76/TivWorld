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
	int myNHostiles;

	Character &myTiv = Character("Tiv", sf::Vector2f(Init::POS_X, Init::POS_Y));
	CollisionManager &myColManager = CollisionManager(myTiv, myLevel);
	KeyboardManager &myKeyboard = KeyboardManager(myTiv, myColManager);
	ExitManager &myExitManager = ExitManager(myTiv, myLevel);

	Character &myHostile1 = Character();
	CollisionManager &myColManagerH1 = CollisionManager(myHostile1, myLevel);
	KeyboardManager &myKeyboardH1 = KeyboardManager(myHostile1, myColManagerH1);

	Character &myHostile2 = Character();
	CollisionManager &myColManagerH2 = CollisionManager(myHostile2, myLevel);
	KeyboardManager &myKeyboardH2 = KeyboardManager(myHostile2, myColManagerH2);

	Character &myHostile3 = Character();
	CollisionManager &myColManagerH3 = CollisionManager(myHostile3, myLevel);
	KeyboardManager &myKeyboardH3 = KeyboardManager(myHostile3, myColManagerH3);

	Character &myHostile4 = Character();
	CollisionManager &myColManagerH4 = CollisionManager(myHostile4, myLevel);
	KeyboardManager &myKeyboardH4 = KeyboardManager(myHostile4, myColManagerH4);

	void InitHostiles();
	void Render();
	void Update();
	void MoveHostiles();
	void Informations();
};

#endif // GAME_H_INCLUDED