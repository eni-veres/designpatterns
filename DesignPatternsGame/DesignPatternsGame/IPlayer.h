#pragma once
#include"ReversiBoard.h"
#include"ReversiState.h" 

class IPlayer
{
public:
	virtual bool move(int x, int y)=0;
};
