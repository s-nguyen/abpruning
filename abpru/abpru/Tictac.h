#pragma once
#include <iostream>
#include  <vector>
#include <string>

using namespace std;
class Tictac
{
private:
	
	string MinMax; //1 means max 0 means min 
	int level;
	int state;
	bool done; //Terminal Node
	vector<Tictac*> node;
	vector<vector<char>> v;
	bool CheckDone(vector<vector<char>> v, char c);
	
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

};

