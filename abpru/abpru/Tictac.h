#pragma once
#include <iostream>
#include  <vector>
#include <string>
#include <algorithm>

using namespace std;
class Tictac
{
private:
	
	string MinMax; //1 means max 0 means min 
	int level;
	int state;
	bool done; //Terminal Node
	int gameResults;
	vector<Tictac*> child;
	vector<vector<char>> v;
	bool CheckDone(vector<vector<char>> vv, char c);
	bool CheckFullDone(vector<vector<char>> vv);
	
	
public:
	Tictac();
	Tictac(string m, int l);
	Tictac(string m);
	~Tictac();
	void ReadInput(char* s);
	void Expand();
	vector<vector<char>> GetVector();
	void SetVector(vector<vector<char>> newV);
	void PrintBoard(vector<vector<char>> b);
	int MiniMax(Tictac* node, int depth, string m, int &c); //Node, depth, maximizingPlayer
	bool GetDone();
	int GetState();
	int GetLevel();
	int GetMaxLevel(Tictac* node);
	int AlphaBeta(Tictac* node, int depth, int a, int b, string m, int &c, int &aTotal, int &bTotal);
};

