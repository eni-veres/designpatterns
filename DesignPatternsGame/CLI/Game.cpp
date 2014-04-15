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

	void Game::CallInit(array<int,2>^% board, bool gametype)
	{
		std::vector<std::vector<int>> a;
		gPtr->init(a, gametype);

		for(size_t i=0;i<8;i++)
		{
			for(size_t j=0;j<8;j++)
			{
				board[i,j]=a[i][j];
			}
		}
	}

	int Game::CallMove(array<int,2>^% board, int i, int j)
	{
		std::vector<std::vector<int>> a;	
		int rez=gPtr->move(a, i,j);
		
		for(size_t k=0;k<8;k++)
		{
			for(size_t l=0;l<8;l++)
			{
				board[k,l]=a[k][l];
			}
		}
		return rez;
	}

	int Game::CallActivePlayer()
	{
		return gPtr->getActivePlayer();
	}

	int Game::CallGetScore(int player)
	{
		return gPtr->getScore(player);
	}

	int Game::CallComputerMove(array<int,2>^% board)
	{
		std::vector<std::vector<int>> a;	
		int rez= gPtr->computerMove(a);

		for(size_t k=0;k<8;k++)
		{
			for(size_t l=0;l<8;l++)
			{
				board[k,l]=a[k][l];
			}
		}
		return rez;
	}

	void Game::CallSetComputerLevel(int t)
	{
		gPtr->setComputerLevel(t);
	}
}
