#pragma once
#include"IMoveStrategy.h"
#include"ReversiBoard.h"

namespace Games
{
	class Difficult : public IMoveStrategy
	{
	private:
		int negamax(int player, int depth);
		int negamax_aux(int player, int depth, int alpha, int beta);
	public:
		virtual bool move();
	};
}