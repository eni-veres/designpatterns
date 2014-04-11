#pragma once
#include"IPlayer.h"

namespace Player
{
	class ComputerPlayer //: public IPlayer
	{
		int negamax(int player, int depth);
		int negamax_aux(int player, int depth, int alpha, int beta);
	public:
		ComputerPlayer(void);
		bool move();
		~ComputerPlayer(void);
	};

}