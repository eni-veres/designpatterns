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

	void DestroyGameClass(IGame* gPtr)
	{
		delete gPtr;
	}

	void Game::init(std::vector<std::vector<int>>& board, bool gametype, int stplayer) 
	{
		type=gametype;
		if(type)
		{
			//call init method from GamePP
		}
		else
		{
			//call init method from GamePC
			GamePC* g=GamePC::getInstance();
			g->init(board,stplayer);
		}
	}

	int Game::move(std::vector<std::vector<int>>& board, int i, int j, int player)
	{
		int rez=-1;
		if(type)
		{
			//call move from GamePP
		}
		else
		{
			///call move from GamePC
			GamePC* g=GamePC::getInstance();
			rez=g->move(board,i,j,player);
		}
		return rez;
	}
}