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

		virtual void init(std::vector<std::vector<int>>& board, bool gametype);//, int stplayer);
		virtual int move(std::vector<std::vector<int>>& board, int i, int j);//, int& player);
		virtual int getActivePlayer();
		virtual int getScore(int player);
		virtual int computerMove();
	};
}

