#pragma once
#include<vector>
#include"ReversiBoard.h"
#include"ReversiState.h"
#include"HumanPlayer.h"
#include"ComputerPlayer.h"

#include"windows.h"

class GamePC
{
	static GamePC* instance;
	ReversiBoard* b;
	int currentplayer;
	int win;
	Games::ComputerPlayer cplayer;
	HumanPlayer hplayer;
	GamePC(void);
	bool IsGameOver();
	void SwitchTurn();

public:
	static GamePC* getInstance();
	void init(std::vector<std::vector<int>>& board);
	int move(std::vector<std::vector<int>>& board, int i, int j);
	int getPlayer();
	int GetWinner();
	int computerMove(std::vector<std::vector<int>>& board);
	int getScore(int player);
	void setComputerLevel(int t);
	~GamePC(void);
};

