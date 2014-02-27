#pragma once
#include"API.h"

namespace Games
{
	struct TEST_API IGame
	{
		virtual ~IGame() = 0 {}

		//virtual methods
	};

	TEST_API IGame* CreateGameClass();
	TEST_API void DestroyGameClass(IGame* gPtr);
}