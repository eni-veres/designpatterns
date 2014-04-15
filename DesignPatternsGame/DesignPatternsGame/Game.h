#pragma once
#include"IGame.h"
#include"GamePP.h"
#include"GamePC.h"

namespace Games
{
	class Game : public IGame
	{
	private:
		bool type;
	public:
		Game(void);
		virtual ~Game(){};

		virtual void init(std::vector<std::vector<int>>& board, bool gametype);
		virtual int move(std::vector<std::vector<int>>& board, int i, int j);
		virtual int getActivePlayer();
		virtual int getScore(int player);
		virtual int computerMove(std::vector<std::vector<int>>& board);
		virtual void setComputerLevel(int t);
	};
}

