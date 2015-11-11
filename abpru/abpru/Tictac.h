#pragma once
#include  <vector>
#include <string>

using namespace std;
class Tictac
{
private:
	
	int MinMax; //1 means max 0 means min 
	int level;
	int state;
	bool done; //Terminal Node
	vector<Tictac*> node;
	vector<vector<char>> v;
	bool CheckDone(vector<vector<char>> v, char c);
	
public:
	Tictac();
	Tictac(int m, int l);
	Tictac(int m);
	~Tictac();
	void ReadInput(char* s);
	void Expand();
	vector<vector<char>> GetVector();
	void SetVector(vector<vector<char>> newV);
	
};

