#include "GamePC.h"


GamePC::GamePC(void)
{
}

GamePC* GamePC::instance=NULL;

GamePC* GamePC::getInstance()
{
	if(instance==NULL)
		instance=new GamePC();
	return instance;
}

void GamePC::init(std::vector<std::vector<int>>& board, int stplayer)
{
	board.resize(8,std::vector<int>(8,0));
	board[3][3]=1;
	board[4][4]=1;
	board[3][4]=2;
	board[4][3]=2;
	pl=stplayer;
}
	
int GamePC::move(std::vector<std::vector<int>>& board, int i, int j, int player)
{
	return -1;
}

GamePC::~GamePC(void)
{
}
