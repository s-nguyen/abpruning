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

void Tictac::Expand(vector<char> v)
{
	for (int i = 0; i < v.size(); i++) //tranverse through the current state
	{
		if (v[i] == '_') //A placeable location
		{
			if (this->MinMax == 0) //X's turn
			{
				vector<char> temp = this->GetVector();
				temp[i] = 'X';
				Tictac* temp = new Tictac(0, this->level+1);	
				this->node.push_back(temp);
			}
		}
	}

}

