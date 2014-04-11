#pragma once
#include"ReversiBoard.h"
#include"IMoveStrategy.h"
#include"Levels.h"
#include"Easy.h"
#include"Medium.h"
#include"Difficult.h"

namespace Games
{
	class ComputerPlayer
	{
		IMoveStrategy* strategy;
		int negamax(int player, int depth);
		int negamax_aux(int player, int depth, int alpha, int beta);
	public:
		ComputerPlayer(void);
		void setLevel(int s);
		bool move();
		~ComputerPlayer(void);
	};
}