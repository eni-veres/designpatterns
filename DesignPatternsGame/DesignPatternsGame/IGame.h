#pragma once
#include"API.h"
#include<vector>

namespace Games
{
	struct TEST_API IGame
	{
		virtual ~IGame() = 0 {}

		//virtual methods
		virtual void init(std::vector<std::vector<int>>& board, bool gametype)=0;//, int stplayer)=0;
		virtual int move(std::vector<std::vector<int>>& board, int i, int j)=0;//, int& player)=0;
		virtual int getActivePlayer()=0;
		virtual int getScore(int player)=0;
		virtual int computerMove()=0;
	};

	TEST_API IGame* CreateGameClass();
	TEST_API void DestroyGameClass(IGame* gPtr);
}