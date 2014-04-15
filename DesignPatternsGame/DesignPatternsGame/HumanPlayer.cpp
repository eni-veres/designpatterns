#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(void)
{
}

bool HumanPlayer::move(int x, int y)
{
	ReversiBoard* board=ReversiBoard::getBoardInstance();

	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves=board->GetMoves(WHITE);

	for(auto it=moves.begin(); it != moves.end(); it++) 
	{
		if(x*8+y==(*it).first)
		{
			board->MakeMove(x,y,WHITE,(*it).second);
			return true;
		}
	}

	return false;
}

HumanPlayer::~HumanPlayer(void)
{
}
