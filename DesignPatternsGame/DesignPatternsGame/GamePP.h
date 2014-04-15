#pragma once
#include<vector>
#include"ReversiBoard.h"
#include"ReversiState.h"
#include"HumanPlayer.h"
#include"ComputerPlayer.h"
#include"windows.h"

class GamePP
{
	static GamePP* instance;
	//clasa Singleton

	ReversiBoard* b;
	int currentplayer;
	int win;
	HumanPlayer player1;
	HumanPlayer player2;
	GamePP(void);
	bool IsGameOver();
	void SwitchTurn();
public:
	static GamePP* getInstance();
	void init(std::vector<std::vector<int>>& board);//, int stplayer);
	int move(std::vector<std::vector<int>>& board, int i, int j);
	int getPlayer();
	int GetWinner();
	int getScore(int player);
	~GamePP(void);
};