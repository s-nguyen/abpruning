#include <iostream>
#include "Tictac.h"
using namespace std;

int main(int argc, char* argv[])
{
	Tictac t("Max");
	
	t.ReadInput("OOX_X_OX_");


	t.Expand();
	return 0;
}