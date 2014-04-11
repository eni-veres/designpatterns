#include "Easy.h"

namespace Games
{
	bool Easy::move()
	{
		ReversiBoard* b=ReversiBoard::getBoardInstance();
		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves=b->GetMoves(BLACK);

		if(moves.empty())
			return false;

		srand((unsigned)time(0));
		int rnd=(int)((moves.size()*rand())/(RAND_MAX+1.0));

		b->MakeMove(moves[rnd].first/8,moves[rnd].first%8,BLACK,moves[rnd].second);

		return true;
	}
}