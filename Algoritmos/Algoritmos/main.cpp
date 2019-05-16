//--------------------------------------------------------------------------------------
// File: main.cpp
// Version: v 0.1
// Creation Date: 29/04/2019
// Author: Roberto Charreton Kaplun
// Summary: Program to test multiple Algorithms
// Errors: 
// Bugs: Overflow in recursive fibonacci
// Nice to Have: 
//--------------------------------------------------------------------------------------
#include "Header.h"
#include "CManager.h"

int main()
{
	CManager Manager;
	//Manager.ExecuteAlgorithms();
	vector<int> MyVector = { 5,3,2,1,4 };
	int n = 20;
	for (size_t i = 0; i < n; i++)
	{
		Manager.SortTrails(Manager.Ascendentes(n));

	}
	//Manager.SortTrails(Manager.Descendentes(n));
	//Manager.SortTrails(Manager.Random(n));
	cin.ignore();
	cin.get();
	return 0;
}

