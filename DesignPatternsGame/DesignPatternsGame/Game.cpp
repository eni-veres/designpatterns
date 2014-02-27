#include "Game.h"

namespace Games
{
	Game::Game(void)
	{
	}

	IGame* CreateGameClass()
	{
		return static_cast<IGame*>(new Game);
	}

	void DestroyGameClass(IGame* testPtr)
	{
		delete testPtr;
	}
}