#include "Tictac.h"

Tictac::Tictac(string m)
{
	this->MinMax = m;
	this->level = 0;
	this->done = false;
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
							this->state = 1;
						}
						else
						{
							this->state = 0;
						}
						this->node.push_back(t);
						t->Expand();
					}
					else if (this->MinMax.compare("Min") == 0) // O's turn to place O
					{
						temp[i][j] = 'O';
						Tictac *t = new Tictac("Max", this->level + 1);
						t->SetVector(temp);
						if (this->CheckDone(t->GetVector(), 'O'))
						{
							t->done = true;
							this->state = -1;
						}
						else
						{
							this->state = 0;
						}
						this->node.push_back(t);
						t->Expand();
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

//if (this->v[i][j] == '_') //A placeable location
//{
//	vector<vector<char>> temp = this->GetVector();
//	if (this->MinMax == 1) //X's turn
//	{
//		temp[i][j] = 'X';
//		Tictac* t = new Tictac(0, this->level + 1);	//MinMax, level
//		t->SetVector(temp);
//		if (this->CheckDone(temp, 'X')) //Check if there is winner
//		{
//
//		}
//		this->node.push_back(t);
//	}
//	else if (this->MinMax == 0) //O's Turn
//	{
//		temp[i][j] = 'O';
//		Tictac* t = new Tictac(1, this->level + 1); //Who turn is next, next level
//		t->SetVector(temp);
//		if (this->CheckDone(temp, 'O')) //Check if there is winner
//		{
//
//		}
//		this->node.push_back(t);
//	}
//
//}
bool Tictac::CheckDone(vector<vector<char>> v, char c) //checks if there is a Winner so node stop expanding
{
	int rowCount = 0;
	int colCount = 0;
	for (int i = 0; i < v.size(); i++) //check Rows and Col
	{
		rowCount = 0;
		colCount = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == c)
			{
				rowCount++;
			}
			if (v[j][i] == c)
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
		if (v[i][i] == c)
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
		if (v[i][2 - i] == c)
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
		cout << endl;
	}
}
