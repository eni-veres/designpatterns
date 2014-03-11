#pragma once
#include"IGame.h"

namespace GameCLI
{
	public ref class Game
	{
		Games::IGame* gPtr;
	public:
		Game(void);
		~Game(void);
		!Game(void);

		void CallInit(array<int,2>^% board);
		bool CallMove(array<int,2>^% board, int i, int j, int player);
		//call methods
	};
}

