#include "ReversiBoard.h"

ReversiBoard* ReversiBoard::boardinstance=NULL;

ReversiBoard::ReversiBoard(void)
{
	board.resize(8,std::vector<int>(8,0));
	board[3][3]=board[4][4]=WHITE;
	board[3][4]=board[4][3]=BLACK;
}

//instance of board
ReversiBoard* ReversiBoard::getBoardInstance()
{
	if(boardinstance==NULL)
		boardinstance=new ReversiBoard();

	return boardinstance;
}

//returns score for player
int ReversiBoard::GetScore(int player)
{
	int rez=0;

	for(size_t i=0;i<8;i++)
		for(size_t j=0;j<8;j++)
			if(player==board[i][j])
				rez++;

	return rez;
}

//check if board is completely filled
bool ReversiBoard::IsBoardFilled()
{
	for(size_t i=0;i<8;i++)
		for(size_t j=0;j<8;j++)
			if(board[i][j]==NONE)
				return false;
	return true;
}

//gets available moves
std::vector<std::pair<int, std::vector<std::pair<int, int>>>> ReversiBoard::GetMoves(int player)
{
	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves;
	for(int i=0; i < 8; i++) 
	{
		for(int j=0; j < 8; j++) 
		{
			moves.push_back(std::make_pair<int, std::vector< std::pair<int, int> > >(i*8+j, GetDirections(i, j, player)));
			if(!moves.back().second.size()) 
			{
				moves.pop_back();
			}
		}
	}

	return moves;
}

std::vector<std::pair<int, int>> ReversiBoard::GetDirections(int x, int y, int player)
{
	std::vector<std::pair<int, int>> directions;
	
	if(board[x][y]) 
	{
		return directions;
	}

	checkNorth(x,y,player, directions);
	checkNorthEast(x,y,player,directions);
	checkEast(x,y,player,directions);
	checkSouthEast(x,y,player,directions);
	checkSouth(x,y,player,directions);
	checkSouthWest(x,y,player,directions);
	checkWest(x,y,player,directions);
	checkNorthWest(x,y,player,directions);
	
	return directions;
}

//check moves up
void ReversiBoard::checkNorth(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y < 6) && (board[x][y+1] == 3-player)) 
	{
		for(int i=y+2; i < 8; i++) 
		{
			if(!board[x][i]) 
			{
				break;
			}
			else if(board[x][i] == player) 
			{
				d.push_back(std::make_pair<int, int>(0, x*8+i));
				break;
			}
		}
	}
}

//check move up-right
void ReversiBoard::checkNorthEast(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y < 6) && (x < 6) && (board[x+1][y+1] == 3-player)) 
	{
		for(int i=0; (x+i+2 < 8) && (y+i+2 < 8); i++) 
		{
			if(!board[x+i+2][y+i+2]) 
			{
				break;
			}
			else if(board[x+i+2][y+i+2] == player) 
			{
				d.push_back(std::make_pair<int, int>(1, (x+i+2)*8+(y+i+2)));
				break;
			}
		}
	}
}

//check move right
void ReversiBoard::checkEast(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((x < 6) && (board[x+1][y] == 3-player)) 
	{
		for(int i=x+2; i < 8; i++)
		{
			if(!board[i][y]) 
			{
				break;
			}
			else if(board[i][y] == player) 
			{
				d.push_back(std::make_pair<int, int>(2, i*8+y));
				break;
			}
		}
	}
}

//check move right-down
void ReversiBoard::checkSouthEast(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y > 1) && (x < 6) && (board[x+1][y-1] == 3-player)) 
	{
		for(int i=0; (x+i+2 < 8) && (y-i-2 >= 0); i++) 
		{
			if(!board[x+i+2][y-i-2]) 
			{
				break;
			}
			else if(board[x+i+2][y-i-2] == player) 
			{
				d.push_back(std::make_pair<int, int>(3, (x+i+2)*8+(y-i-2)));
				break;
			}
		}
	}
}

//check move down
void ReversiBoard::checkSouth(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y > 1) && (board[x][y-1] == 3-player)) 
	{
		for(int i=y-2; i >= 0; i--) 
		{
			if(!board[x][i]) 
			{
				break;
			}
			else if(board[x][i] == player) 
			{
				d.push_back(std::make_pair<int, int>(4, x*8+i));
				break;
			}
		}
	}
}

//check move down-left
void ReversiBoard::checkSouthWest(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y > 1) && (x > 1) && (board[x-1][y-1] == 3-player)) 
	{
		for(int i=0; (x-i-2 >= 0) && (y-i-2 >= 0); i++) 
		{
			if(!board[x-i-2][y-i-2]) 
			{
				break;
			}
			else if(board[x-i-2][y-i-2] == player) 
			{
				d.push_back(std::make_pair<int, int>(5, (x-i-2)*8+(y-i-2)));
				break;
			}
		}
	}
}

//check move west
void ReversiBoard::checkWest(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((x > 1) && (board[x-1][y] == 3-player)) 
	{
		for(int i=x-2; i >= 0; i--) 
		{
			if(!board[i][y]) 
			{
				break;
			}
			else if(board[i][y] == player) 
			{
				d.push_back(std::make_pair<int, int>(6, i*8+y));
				break;
			}
		}
	}
}

//check move west-up
void ReversiBoard::checkNorthWest(int x, int y, int player, std::vector<std::pair<int, int>>& d)
{
	if((y < 6) && (x > 1) && (board[x-1][y+1] == 3-player)) 
	{
		for(int i=0; (x-i-2 >= 0) && (y+i+2 < 8); i++) 
		{
			if(!board[x-i-2][y+i+2]) 
			{
				break;
			}
			else if(board[x-i-2][y+i+2] == player) 
			{
				d.push_back(std::make_pair<int, int>(7, (x-i-2)*8+(y+i+2)));
				break;
			}
		}
	}
}

//return the board
std::vector<std::vector<int>> ReversiBoard::GetBoardState()
{
	return board;
}

//make move on board
void ReversiBoard::MakeMove(int x, int y, int player, std::vector<std::pair<int, int>> directions)
{
	for(auto it=directions.begin(); it != directions.end(); it++) 
	{
		int i = x;
		int j = y;
		while((i != ((*it).second/8)) || (j != ((*it).second&7))) 
		{
			board[i][j] = player;
			if(i < ((*it).second/8)) 
			{
				i++;
			}
			else if((i > (*it).second/8)) 
			{
				i--;
			}
			if(j < ((*it).second&7)) 
			{
				j++;
			}
			else if(j > ((*it).second&7)) 
			{
				j--;
			}
		}
	}
}

//undo move made on board
void ReversiBoard::UndoMove(int x, int y, int player, std::vector<std::pair<int, int>> directions)
{
	for(auto it=directions.begin(); it != directions.end(); it++) 
	{
		int i = x;
		int j = y;
		while((i != ((*it).second/8)) || (j != ((*it).second&7))) 
		{
			board[i][j] = 3-player;
			if(i < ((*it).second/8)) 
			{
				i++;
			}
			else if((i > (*it).second/8)) 
			{
				i--;
			}
			if(j < ((*it).second&7)) 
			{
				j++;
			}
			else if(j > ((*it).second&7)) 
			{
				j--;
			}
		}
		board[i][j] = player;
	}
	board[x][y] = 0;
}

//board score for AI algorithm
int ReversiBoard::SumBoard(int player)
{
	int sum=0;
	for(int i=0;i<8;i++) 
	  for(int j=0;j<8;j++) 
			sum+=board[i][j];
	
	return sum * player;
}

ReversiBoard::~ReversiBoard(void)
{
	//? delete board instance
}
