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

}
	
int GamePC::move(std::vector<std::vector<int>>& board, int i, int j, int player)
{
	return -1;
}

GamePC::~GamePC(void)
{
}
