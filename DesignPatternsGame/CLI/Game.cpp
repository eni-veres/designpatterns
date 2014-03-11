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

	void Game::CallInit(array<int,2>^% board)
	{
		
	}

	bool CallMove(array<int,2>^% board, int i, int j, int player)
	{

	}
}
