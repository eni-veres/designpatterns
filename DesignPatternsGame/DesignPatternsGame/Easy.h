#pragma once
#include"IMoveStrategy.h"
#include"ReversiBoard.h"
#include<time.h>
#include<random>

namespace Games
{
	class Easy : public IMoveStrategy
	{
	public:
		virtual bool move();
	};
}