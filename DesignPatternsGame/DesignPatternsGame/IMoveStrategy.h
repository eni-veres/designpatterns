#pragma once
#include"API.h"
#include<vector>

namespace Games
{
	class IMoveStrategy
	{
	public:
		virtual bool move()=0;
	};

}