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

	void Game::init(int a[8][8], bool gametype) //gametype if player-player or player-computer
	{

	}

	bool Game::move(int a[8][8], int i, int j, int player)
	{

	}
}