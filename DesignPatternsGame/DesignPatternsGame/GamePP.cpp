#include "GamePP.h"

GamePP* GamePP::instance=NULL;

GamePP::GamePP(void)
{
	b=ReversiBoard::getBoardInstance();
	win=NONE;
}

GamePP* GamePP::getInstance()
{
	if (instance==NULL) {
		instance=new GamePP();
	}
	return instance;
}


void GamePP::init(std::vector<std::vector<int>>& board)
{
	board=b->GetBoardState();
	currentplayer=WHITE;
}


int GamePP::move(std::vector<std::vector<int>>& board, int i, int j)
{
	//human player move
	if(currentplayer == WHITE){
		if(player1.move(i,j))
		{
			SwitchTurn();
		}
		else
		{
			MessageBox(0,"Not valid move. Try again.","Error",0);
		}
	}
	else {
		if(player2.move(i,j))
		{
			SwitchTurn();
		}
		else
		{
			MessageBox(0,"Not valid move. Try again.","Error",0);
		}
	}
	board=b->GetBoardState();

	return win;
}

int GamePP::getPlayer()
{
	return currentplayer;
}

//change player, if player has no moves change again
void GamePP::SwitchTurn()
{
	if(IsGameOver())
		win=GetWinner();
	else
	{
		currentplayer=3-currentplayer;
		if(b->GetMoves(currentplayer).empty())
			SwitchTurn();
	}
}

//check if game is over
bool GamePP::IsGameOver()
{
	return b->IsBoardFilled() || (b->GetMoves(WHITE).empty() && b->GetMoves(BLACK).empty());
}

//check who is the winner
int GamePP::GetWinner()
{
	if(b->GetScore(WHITE)<b->GetScore(BLACK))
		return BLACK;
	return WHITE;
}
int GamePP::getScore(int player)
{
	return b->GetScore(player);
}
GamePP::~GamePP(void)
{
}