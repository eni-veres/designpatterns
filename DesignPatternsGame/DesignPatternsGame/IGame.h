#pragma once
#include"API.h"

namespace Games
{
	struct TEST_API IGame
	{
		virtual ~IGame() = 0 {}

		//virtual methods
		virtual void init(int a[8][8], bool gametype)=0;
		virtual bool move(int a[8][8], int i, int j, int player)=0;
	};

	TEST_API IGame* CreateGameClass();
	TEST_API void DestroyGameClass(IGame* gPtr);
}