#pragma once
#include"IGame.h"
namespace Games
{
	class Game : public IGame
	{
	public:
		Game(void);
		virtual ~Game(){};

		//methods
		virtual void init(int a[8][8], bool gametype);
		virtual bool move(int a[8][8], int i, int j, int player);
	};
}

