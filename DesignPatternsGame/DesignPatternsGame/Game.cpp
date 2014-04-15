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

	void Game::init(std::vector<std::vector<int>>& board, bool gametype)//, int stplayer) 
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
			g->init(board);//,stplayer);
		}
	}

	int Game::move(std::vector<std::vector<int>>& board, int i, int j)
	{
		int rez=-1;
		if(type)
		{
			//call move from GamePP
		}
		else
		{
			///call move from GamePC
			rez=GamePC::getInstance()->move(board,i,j);
		}
		return rez;
	}

	int Game::getActivePlayer()
	{
		if(type)
		{
			//from GamePP
		}
		else
		{
			GamePC* g=GamePC::getInstance();
			return g->getPlayer();
		}
	}

	int Game::getScore(int player)
	{
		if(type)
		{
			//from GamePP
		}
		else
		{
			return GamePC::getInstance()->getScore(player);
		}
	}
	
	int Game::computerMove(std::vector<std::vector<int>>& board)
	{
		if(!type)
		{
			return GamePC::getInstance()->computerMove(board);
		}
		else
			throw std::exception("Single player mode!");
	}

	void Game::setComputerLevel(int t)
	{
		if(!type)
		{
			GamePC::getInstance()->setComputerLevel(t);
		}
		else
			throw std::exception("Single player mode!");
	}
}