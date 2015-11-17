#include <iostream>
#include "Tictac.h"
using namespace std;

int main(int argc, char* argv[])
{
	int moves = 0;
	int state;
	int depth;
	int a = -2;
	int b = 2;
	int aTotal = 0;
	int bTotal = 0;
	Tictac *t = new Tictac("Max");

	if (argc != 2){
		cout << "Usage: .\abpru startstate" << endl;
		return -1;
	}

	t->ReadInput(argv[1]);
	t->Expand();
	depth = t->GetMaxLevel(t);

	if (!t->GetDone())
	{
		state = t->MiniMax(t, depth, "Max", moves);
	}

	cout << argv[0] << " " << argv[1] << endl << endl;
	cout << "Running without alpha-beta pruning" << endl;
	cout << "Game Result: " << state << endl;
	cout << "Moves considered without alpha-beta pruning: " << moves << endl << endl;

	cout << "------------------------------------------------" << endl << endl;

	cout << "Running with alpha-beta pruning" << endl;
	moves = 0;
	state = t->AlphaBeta(t, depth, a, b, "Max", moves, aTotal, bTotal, t->getCut());

	t->PrintBoard2();

	cout << "Game Result: " << state << endl;
	cout << "Moves Considered with alpha-beta pruning: " << moves << endl;
	cout << "Alpha cuts: " << aTotal << endl;
	cout << "Beta cuts: " << bTotal << endl;

	return 0;
}