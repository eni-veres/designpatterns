#pragma once
#include<vector>
#include"ReversiState.h"

class ReversiBoard
{
private:
	static ReversiBoard* boardinstance;
	std::vector<std::vector<int>> board;

	ReversiBoard(void);
	std::vector<std::pair<int, int>> GetDirections(int x, int y, int player);
	void checkNorth(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkNorthEast(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkEast(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkSouthEast(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkSouth(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkSouthWest(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkWest(int x, int y, int player, std::vector<std::pair<int, int>>& d);
	void checkNorthWest(int x, int y, int player, std::vector<std::pair<int, int>>& d);
public:
	static ReversiBoard* getBoardInstance();
	int GetScore(int player);
	std::vector<std::vector<int>> GetBoardState();
	bool IsBoardFilled();
	std::vector<std::pair<int, std::vector<std::pair<int, int>>>> GetMoves(int player);
	int SumBoard(int player);	
	void UndoMove(int x, int y, int player, std::vector<std::pair<int, int>> directions);
	void MakeMove(int x, int y, int player, std::vector<std::pair<int, int>> directions);

	~ReversiBoard(void);
};

