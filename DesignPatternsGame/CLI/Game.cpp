#include "Game.h"

namespace GameCLI
{
	Game::Game(void)
	{
		gPtr=Games::CreateGameClass();
	}

	Game::~Game(void)
	{
		if(gPtr != nullptr)
		{
			Games::DestroyGameClass(gPtr);
		}
	}

	Game::!Game(void)
	{
		if(gPtr != nullptr)
		{
			Games::DestroyGameClass(gPtr);
		}
	}

	//call methods
}
