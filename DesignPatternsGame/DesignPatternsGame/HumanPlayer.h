#pragma once
#include"IPlayer.h"

class HumanPlayer : public IPlayer
{
public:
	HumanPlayer(void);
	bool move(int x, int y);
	~HumanPlayer(void);
};
