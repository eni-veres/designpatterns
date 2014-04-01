#include "GamePC.h"

GamePC* GamePC::instance=NULL;

GamePC::GamePC(void)
{
}

GamePC* GamePC::getInstance()
{
	if(instance==NULL)
		instance=new GamePC();
	return instance;
}

void GamePC::init(std::vector<std::vector<int>>& board, int stplayer)
{
	board.resize(8,std::vector<int>(8,0));
	board[3][3]=board[4][4]=1;
	board[3][4]=board[4][3]=2;
	if(stplayer==2)
		computermove(board,stplayer);
}

int GamePC::move(std::vector<std::vector<int>>& board, int i, int j, int& player)
{
	if(player==2)
	{
		computermove(board,player); 
	}
	else
	{
		if(augment(i,j,player,board) )
		{
			player=3-player;
		}
	}

	return checkWin(board);
}

int GamePC::checkWin(std::vector<std::vector<int>>& board)
{
	int count1=0;
	int count2=0;
	int count0=0;

	for(size_t i=0;i<8;i++)
	{
		for(size_t j=0;j<8;j++)
			if(board[i][j]==1)
				count1++;
			else
			{
				if(board[i][j]==2)
					count2++;
				else
					//count0++;
					return -1;
			}
	}

	//if(count0!=0)
	//	return -1;
	if(count1>count2)
		return 1;
	else
		return 2;
}

void GamePC::computermove(std::vector<std::vector<int>>& board, int& player)
{
	int x = negamax(board, player, 3);
	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves=get_moves(board, player);
	for(auto it=moves.begin(); it != moves.end(); it++) 
	{
		if(x==((*it).first)) 
		{
			make_move(board, x/8, x%8, player, (*it).second);
			player = 3-player;
			break;
		}
	}
}

int GamePC::score(std::vector<std::vector<int>>& board, int player) 
{
	int sum = 0;
	for(int i=0; i < 8; i++) 
	{
		for(int j=0; j < 8; j++) 
		{
			sum += board[i][j];
		}
	}
	return sum * player;
}

int GamePC::negamax_aux(std::vector<std::vector<int>>& board, int player, int depth, int alpha, int beta) 
{
	if(depth == 0) 
	{
		return score(board, player);
	}
	std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves = get_moves(board, player);
	if(moves.size() == 0) 
	{
		if(get_moves(board, 3-player).size() == 0) 
		{
			return score(board, player);
		}
		int val = -negamax_aux(board, 3-player, depth-1, -beta, -alpha);
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
			make_move(board, (*it).first/8, (*it).first&7, player, (*it).second);
			int val = -negamax_aux(board, 3-player, depth-1, -beta, -alpha);
			undo_move(board, (*it).first/8, (*it).first&7, player, (*it).second);
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

int GamePC::negamax(std::vector<std::vector<int>>& board, int player, int depth) 
{
	int alpha = -65;
	int beta = 65;
	std::vector< std::pair<int, std::vector< std::pair<int, int> > > > moves = get_moves(board, player);
	int move = moves[0].first;
	for(auto it=moves.begin(); it != moves.end(); it++) 
	{
		make_move(board, (*it).first/8, (*it).first&7, player, (*it).second);
		int val = -negamax_aux(board, 3-player, depth-1, -beta, -alpha);
		undo_move(board, (*it).first/8, (*it).first&7, player, (*it).second);
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

void GamePC::make_move(std::vector<std::vector<int>>& board, int x, int y, int player, std::vector<std::pair<int, int>> directions) 
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

void GamePC::undo_move(std::vector<std::vector<int>>& board, int x, int y, int player, std::vector< std::pair<int, int> > directions)
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

std::vector<std::pair<int, std::vector<std::pair<int, int>>>> GamePC::get_moves(std::vector<std::vector<int>>& board, int player)
{
	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> moves;
	for(int i=0; i < 8; i++) 
	{
		for(int j=0; j < 8; j++) 
		{
			moves.push_back(std::make_pair<int, std::vector< std::pair<int, int> > >(i*8+j, get_directions(board, i, j, player)));
			if(!moves.back().second.size()) 
			{
				moves.pop_back();
			}
		}
	}
	return moves;
}

std::vector<std::pair<int, int>> GamePC::get_directions(std::vector<std::vector<int>>& board, int x, int y, int player) 
{
	std::vector<std::pair<int, int>> directions;
	if(board[x][y]) 
	{
		return directions;
	}
	//north
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
				directions.push_back(std::make_pair<int, int>(0, x*8+i));
				break;
			}
		}
	}
	//northeast
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
				directions.push_back(std::make_pair<int, int>(1, (x+i+2)*8+(y+i+2)));
				break;
			}
		}
	}
	//east
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
				directions.push_back(std::make_pair<int, int>(2, i*8+y));
				break;
			}
		}
	}
	//southeast
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
				directions.push_back(std::make_pair<int, int>(3, (x+i+2)*8+(y-i-2)));
				break;
			}
		}
	}
	//south
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
				directions.push_back(std::make_pair<int, int>(4, x*8+i));
				break;
			}
		}
	}
	//southwest
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
				directions.push_back(std::make_pair<int, int>(5, (x-i-2)*8+(y-i-2)));
				break;
			}
		}
	}
	//west
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
				directions.push_back(std::make_pair<int, int>(6, i*8+y));
				break;
			}
		}
	}
	//northwest
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
				directions.push_back(std::make_pair<int, int>(7, (x-i-2)*8+(y+i+2)));
				break;
			}
		}
	}
	return directions;
}

bool GamePC::checkempty(int x, int y, const std::vector<std::vector<int>>& board)
{
	return (board[x][y]==0);
}

bool GamePC::checkplace(int player, int xco, int yco, std::vector<std::vector<int>>& board)
{
	if (checkempty(xco, yco, board)  && checkcomp(xco, yco, player, board) )
		return true;
	else 
		return false;    
}

bool GamePC::inboard(int x, int y)
{
	return (x<8 && x>=0 && y<8 && y>=0);
}

bool GamePC::trace(int x, int y, int xdir, int ydir, std::vector<std::vector<int>>& board)
{
	if(!inboard(x,y)) 
		return false;
	if (inboard(x+xdir, y+ydir))
	{
		if (board[x+xdir][y+ydir]==board[x][y])
			return trace(x+xdir, y+ydir, xdir, ydir,board);
		else
		{
			if(board[x+xdir][y+ydir]==0)
				return false;
			else 
				return true;
		}
	}
	else 
		return false;
}

void GamePC::change(int x, int y, int xdir, int ydir, std::vector<std::vector<int>>& board)
{
	if(board[x+xdir][y+ydir]!=board[x][y])
	{
		board[x+xdir][y+ydir]=board[x][y];
		change(x+xdir,y+ydir,xdir,ydir, board);
	}                  
}

bool GamePC::checkcomp(int x, int y, int player, std::vector<std::vector<int>>& board)
{
	if(inboard(x+1,y))
		if (3-player==board[x+1][y] && trace(x+1, y,1,0,board))
			return true;  

	if(inboard(x+1,y+1))
		if (3-player==board[x+1][y+1] && trace(x+1, y+1,1,1,board)) 
			return true;

	if(inboard(x+1,y-1))
		if (3-player==board[x+1][y-1] && trace(x+1, y-1,1,-1,board)) 
			return true;

	if(inboard(x,y+1))
		if (3-player==board[x][y+1] && trace(x, y+1,0,1,board)) 
			return true;

	if(inboard(x,y-1))
		if (3-player==board[x][y-1] && trace(x, y-1,0,-1,board)) 
			return true;

	if(inboard(x-1,y+1))
		if (3-player==board[x-1][y+1] && trace(x-1, y+1,-1,1,board)) 
			return true;

	if(inboard(x-1,y-1))
		if (3-player==board[x-1][y-1] && trace(x-1, y-1,-1,-1,board)) 
			return true;

	if(inboard(x-1,y+1))
		if (3-player==board[x-1][y] && trace(x-1, y,-1,0,board)) 
			return true;

	return false;
}

bool GamePC::augment(int x, int y, int player, std::vector<std::vector<int>>& board)
{
	if(checkcomp(x,y,player,board) && checkempty(x,y,board))
	{
		board[x][y]=player;
		if (3-player==board[x+1][y] && trace(x+1, y,1,0,board)) 
			change(x, y,1,0,board);

		if (3-player==board[x+1][y+1] && trace(x+1, y+1,1,1,board)) 
			change(x, y,1,1,board);

		if (3-player==board[x+1][y-1] && trace(x+1, y-1,1,-1,board))
			change(x, y,1,-1,board);

		if (3-player==board[x][y+1] && trace(x, y+1,0,1,board)) 
			change(x, y,0,1,board);

		if (3-player==board[x][y-1] && trace(x, y-1,0,-1,board)) 
			change(x, y,0,-1,board);

		if (3-player==board[x-1][y+1] && trace(x-1, y+1,-1,1,board)) 
			change(x, y,-1,1,board);

		if (3-player==board[x-1][y-1] && trace(x-1, y-1,-1,-1,board))
			change(x, y,-1,-1,board);

		if (3-player==board[x-1][y] && trace(x-1, y,-1,0,board)) 
			change(x, y,-1,0,board);
		return true;
	}
	else
		MessageBox(0,"Not valid move. Try again.","Error",0);
	return false;
}

GamePC::~GamePC(void)
{
}
