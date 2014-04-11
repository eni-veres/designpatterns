#pragma once
#include<vector>
#include"ReversiBoard.h"
#include"ReversiState.h"
#include"HumanPlayer.h"
#include"ComputerPlayer.h"

#include"windows.h"
//clasa Singleton
class GamePC
{
	static GamePC* instance;
	ReversiBoard* b;
	int currentplayer;
	int win;
	Player::ComputerPlayer cplayer;
	Player::HumanPlayer hplayer;
	//int pl;
	GamePC(void);
	bool IsGameOver();
	void SwitchTurn();
public:
	static GamePC* getInstance();
	void init(std::vector<std::vector<int>>& board, int stplayer);
	int move(std::vector<std::vector<int>>& board, int i, int j, int& player);
	int getPlayer();
	int GetWinner();
	~GamePC(void);
};

