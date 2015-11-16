#include "Tictac.h"

Tictac::Tictac(string m)
{
	this->MinMax = m;
	this->level = 0;
	this->done = false;

	this->gameResults = 0;
	this->state = 0;
}
Tictac::Tictac(string m, int l)
{
	this->MinMax = m;
	this->level = l;
	this->done = false;
	
}
Tictac::Tictac()
{
	this->done = false;
}

Tictac::~Tictac()
{
}

vector<vector<char>> Tictac::GetVector()
{
	return this->v;
}

void Tictac::SetVector(vector<vector<char>> newV)
{
	this->v = newV;
}

bool Tictac::GetDone()
{
	return this->done;
}

int Tictac::GetState()
{
	return this->state;
}

int Tictac::GetLevel()
{
	return this->level;
}


void Tictac::ReadInput(char* s)
{
	char* i;	
	int row = 0;
	vector<char> temp;
	for (i = s; *i; i++)
	{
		if (row % 3 == 0)
		{
			temp.clear();
		}
		temp.push_back(*i);
		if ((row + 1) % 3 == 0)
		{
			v.push_back(temp);
		}
		row++;
		
	}
	this->done = 0;
	this->state = 0;
}

void Tictac::Expand()
{
	if (!this->CheckFullDone(this->GetVector()))
	{
		for (int i = 0; i < this->v.size(); i++) //tranverse through the current state
		{
			for (int j = 0; j < this->v[i].size(); j++)
			{
				if (this->done == false)
				{
					if (this->v[i][j] == '_')
					{
			
						vector<vector<char>> temp = this->GetVector();
						if (this->MinMax.compare("Max") == 0) //X's turn place an X
						{
							
							temp[i][j] = 'X';
							Tictac *t = new Tictac("Min", this->level + 1); //0 Minmax means its O's turn
							t->SetVector(temp);
							if (this->CheckDone(t->GetVector(), 'X')) //check if terminal node
							{
								t->done = true;
								t->state = 1;
								this->state = 1;
							}
							else if (this->CheckFullDone(t->GetVector()))
							{
								t->done = true;
								this->state = 0;
							}
							this->child.push_back(t);
							if (t->done != true)
							{
								t->Expand();
							}

						}
						else if (this->MinMax.compare("Min") == 0) // O's turn to place O
						{
							temp[i][j] = 'O';
							Tictac *t = new Tictac("Max", this->level + 1);
							t->SetVector(temp);
							if (this->CheckDone(t->GetVector(), 'O'))
							{
								t->done = true;
								t->state = -1;
								this->state = -1;
							}
							else if (this->CheckFullDone(t->GetVector()))
							{
								t->done = true;
								this->state = 0;
							}
							this->child.push_back(t);
							if (t->done != true)
							{
								t->Expand();
							}
						}
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	else
	{
		this->done = true;
		if (this->CheckDone(this->GetVector(), 'X'))
		{
			this->gameResults = 1;
		}
		else if (this->CheckDone(this->GetVector(), 'O'))
		{
			this->gameResults = -1;
		}
		else
		{
			this->gameResults = 0;
		}
	}
	
}


bool Tictac::CheckFullDone(vector<vector<char>> vv)
{
	bool full = true;
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			if (vv[i][j] == '_')
			{
				full = false;
			}
		}
	}
	if (full == true)
	{
		return true;
	}
	return false;
}
bool Tictac::CheckDone(vector<vector<char>> vv, char c) //checks if there is a Winner so node stop expanding
{
	int rowCount = 0;
	int colCount = 0;
	
	for (int i = 0; i < vv.size(); i++) //check Rows and Col
	{
		rowCount = 0;
		colCount = 0;
		for (int j = 0; j < vv[i].size(); j++)
		{
			if (vv[i][j] == c)
			{
				rowCount++;
			}
			if (vv[j][i] == c)
			{
				colCount++;
			}
		}
		if (rowCount == 3 || colCount == 3)
		{
			return true;
		}
	}
	int diagCount = 0;
	for (int i = 0; i < 3; i++) //check diagonal
	{
		if (vv[i][i] == c)
		{
			diagCount++;
		}
		if (diagCount == 3)
		{
			return true;
		}
	}
	int antiDiagCount = 0;
	for (int i = 0; i < 3; i++) //check other diagonal
	{
		if (vv[i][2 - i] == c)
		{
			antiDiagCount++;
		}
		if (antiDiagCount == 3)
		{
			return true;
		}
	}

	return false;
	
}

void Tictac::PrintBoard(vector<vector<char>> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			cout << b[i][j];
		}
		if (i + 1 < b.size())
		{
			cout << endl;
		}
	}
}

int Tictac::GetMaxLevel(Tictac* node)
{
	int depth = 0;
	if (node->done == true)
	{
		return node->level;
	}
	for (int i = 0; i < node->child.size(); i++)
	{
		int n = GetMaxLevel(node->child[i]);
		depth = max(depth, n);
	}
	return depth;
}

int Tictac::MiniMax(Tictac* node, int depth, string m, int &c)
{
	int best;
	c++;
	if (depth == 0 || node->GetDone() == true)
	{
		return node->GetState();
	}
	if (node->MinMax.compare("Max") == 0)
	{
		best = -2;
		for (int i = 0; i < node->child.size(); i++)
		{
			int n = MiniMax(node->child[i], depth - 1, "Min", c);
			best = max(best, n);
		}
		return best;
	}
	else
	{
		best = 2;
		for (int i = 0; i < node->child.size(); i++)
		{
			int n = MiniMax(node->child[i], depth - 1, "Max", c);
			best = min(best, n);
		}
		return best;
	}
}

int Tictac::AlphaBeta(Tictac* node, int depth, int a, int b, string m, int &c, int &aTotal, int &bTotal)
{
	int v;
	c++;
	if (depth == 0 || node->done == true)
	{
		return node->GetState();
	}
	if (node->MinMax.compare("Max") == 0) //maximizer turn
	{
		v = -2;
		for (int i = 0; i < node->child.size(); i++)
		{
			v = max(v, AlphaBeta(node->child[i], depth - 1, a, b, "Min", c, aTotal, bTotal));
			a = max(a, v);
			if (a == 1 && node->child.size() > 1 && i != node->child.size()-1) //fix for single child? //if a == 1 and more than 1 child
			{
				node->PrintBoard(node->GetVector());
				cout << " Beta cut" << endl << endl;;
				bTotal++;
				break;
			}
		}
		return v;
	}
	else //Minimizer
	{
		v = 2;
		for (int i = 0; i < node->child.size(); i++)
		{
			v = min(v, AlphaBeta(node->child[i], depth - 1, a, b, "Max", c, aTotal, bTotal));
			b = min(b, v);
			if (b == -1 && node->child.size() > 1 && i != node->child.size() - 1)
			{
				node->PrintBoard(node->GetVector());
				cout << " Alpha cut" << endl << endl;
				aTotal++;
				break;
			}
		}
		return v;
	}
}