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


Tictac::~Tictac()
{
}

vector<char> Tictac::GetVector()
{
	return this->v;
}

void Tictac::SetVector(vector<char> newV)
{
	this->v = newV;
}

void Tictac::ReadInput(char* s)
{
	char* i;	

	for (i = s; *i; i++)
	{
		this->v.push_back(*i);
	}
	this->done = 0;
	this->state = 0;
}

void Tictac::Expand()
{
	for (int i = 0; i < this->v.size(); i++) //tranverse through the current state
	{
		if (this->v[i] == '_') //A placeable location
		{
			vector<char> temp = this->GetVector();
			if (this->MinMax == 1) //X's turn
			{
				temp[i] = 'X';
				Tictac* t = new Tictac(0, this->level+1);	//MinMax, level
				t->SetVector(temp);
				if (this->CheckDone(temp, 'X')) //Check if there is winner
				{

				}
				this->node.push_back(t);
			}
			else if (this->MinMax == 0) //O's Turn
			{
				temp[i] = 'O';
				Tictac* t = new Tictac(1, this->level+1); //Who turn is next, next level
				t->SetVector(temp);
				if (this->CheckDone(temp, 'O')) //Check if there is winner
				{

				}
				this->node.push_back(t);
			}
			
		}
	}

}

bool Tictac::CheckDone(vector<char> v, char c) //checks if there is a Winner so node stop expanding
{
	int count = 0;
	if (c == 'X') //X placed something check
	{
		//Check Rows
		for (int i = 0; i < v.size(); i++) //first row
		{
			if (v[i] == c)
			{
				count++;
			}
			else
			{
				count = 0;
			}
			
		}
	
	}
	else if (c == 'O') //O placed something check
	{

	}
	return false;
}