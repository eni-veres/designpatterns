#pragma once
#include<vector>

//clasa Singleton
class GamePC
{
	static GamePC* instance;
	GamePC(void);
public:
	static GamePC* getInstance();
	void init(std::vector<std::vector<int>>& board, int stplayer);
	int move(std::vector<std::vector<int>>& board, int i, int j, int player);
	~GamePC(void);
};

