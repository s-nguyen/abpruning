#include "Tictac.h"

Tictac::Tictac(int m)
{
	this->MinMax = m;
	this->level = 0;
	
}
Tictac::Tictac(int m, int l)
{
	this->MinMax = m;
	this->level = l;
	
}
Tictac::Tictac()
{

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
		for (int j = 0; j < this->v[j].size(); j++)
		{

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