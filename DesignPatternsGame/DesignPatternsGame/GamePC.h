#pragma once
#include<vector>
#include"windows.h"
//clasa Singleton
class GamePC
{
	static GamePC* instance;
	//int pl;
	GamePC(void);
	void computermove(std::vector<std::vector<int>>& board, int& player);
	int negamax(std::vector<std::vector<int>>& board, int player, int depth);// 
	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> get_moves(std::vector<std::vector<int>>& board, int player);
	std::vector< std::pair<int, int> > get_directions(std::vector<std::vector<int>>& board, int x, int y, int player);
	void undo_move(std::vector<std::vector<int>>& board, int x, int y, int player, std::vector<std::pair<int, int>> directions);
	void make_move(std::vector<std::vector<int>>& board, int x, int y, int player, std::vector<std::pair<int, int>> directions) ;
	int negamax_aux(std::vector<std::vector<int>>& board, int player, int depth, int alpha, int beta);
	int score(std::vector<std::vector<int>>& board, int player);
	//
	int checkWin(std::vector<std::vector<int>>& board);
	
	bool augment(int x, int y, int player, std::vector<std::vector<int>>& board);
	bool checkcomp (int x, int y, int player, std::vector<std::vector<int>>& board);
	void change(int x, int y, int xdir, int ydir, std::vector<std::vector<int>>& board);
	bool trace(int x, int y, int xdir, int ydir, std::vector<std::vector<int>>& board);
	bool inboard(int x, int y);
	bool checkplace(int colour, int xco, int yco, std::vector<std::vector<int>>& board);
	bool checkempty(int x, int y, const std::vector<std::vector<int>>& board);


public:
	static GamePC* getInstance();
	void init(std::vector<std::vector<int>>& board, int stplayer);
	int move(std::vector<std::vector<int>>& board, int i, int j, int& player);
	~GamePC(void);
};

