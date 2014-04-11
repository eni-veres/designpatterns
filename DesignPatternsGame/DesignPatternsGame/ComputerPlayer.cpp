#include "ComputerPlayer.h"

namespace Player
{
	ComputerPlayer::ComputerPlayer(void)
	{
	}

	bool ComputerPlayer::move()
	{
		ReversiBoard* board=ReversiBoard::getBoardInstance();
		int x = negamax(BLACK, 3);
		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves=board->GetMoves(BLACK);
		for(auto it=moves.begin(); it != moves.end(); it++) 
		{
			if(x==((*it).first)) 
			{
				board->MakeMove(x/8, x%8, BLACK, (*it).second);
				return true;
			}
		}

		return false;
	}

	int ComputerPlayer::negamax(int player, int depth) 
	{
		ReversiBoard* board=ReversiBoard::getBoardInstance();
		int alpha = -65;
		int beta = 65;
		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves=board->GetMoves(player);
		int move = moves[0].first;
		
		for(auto it=moves.begin(); it != moves.end(); it++) 
		{
			board->MakeMove((*it).first/8, (*it).first&7,player, (*it).second);
			int val = -negamax_aux(3-player, depth-1, -beta, -alpha);
			board->UndoMove((*it).first/8, (*it).first&7, player, (*it).second);
			if(val >= beta) 
			{
				return (*it).first;
			}
			if(val > alpha) 
			{
				alpha = val;
				move = (*it).first;
			}
		}

	return move;

	}

	int ComputerPlayer::negamax_aux(int player, int depth, int alpha, int beta)
	{
		ReversiBoard* board=ReversiBoard::getBoardInstance();
		if(depth == 0) 
		{
			return board->SumBoard(player);
		}

		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves = board->GetMoves(player);
		
		if(moves.size() == 0) 
		{
			if(board->GetMoves(3-player).size() == 0) 
			{
				board->SumBoard(player);
			}
			
			int val = -negamax_aux(3-player, depth-1, -beta, -alpha);
		
			if(val >= beta) 
			{
				return val;
			}
			
			if(val > alpha) 
			{
				alpha = val;
			}
		}	 
		else 
		{
			for(auto it=moves.begin(); it != moves.end(); it++) 
			{
				board->MakeMove((*it).first/8, (*it).first&7, player, (*it).second);
				int val = -negamax_aux(3-player, depth-1, -beta, -alpha);
				board->UndoMove((*it).first/8, (*it).first&7, player, (*it).second);
				
				if(val >= beta) 
				{
					return val;
				}
				
				if(val > alpha) 
				{
					alpha = val;
				}
			}
		}
	
		return alpha;
	}

	ComputerPlayer::~ComputerPlayer(void)
	{
	}
}