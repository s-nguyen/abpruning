#include <iostream>
#include "Tictac.h"
using namespace std;

int main(int argc, char* argv[])
{
	Tictac t(1);
	
	t.ReadInput(argv[1]);


	t.Expand();
	return 0;
}