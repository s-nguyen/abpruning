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
	bool done;
	vector<Tictac> node;
	vector<char> v;

public:

	Tictac(int m, int l);
	Tictac(int m);
	~Tictac();
	void ReadInput(char* s);
	void Expand(vector<char> v);
	vector<char> GetVector();
	void SetVector(vector<char> newV);
};

