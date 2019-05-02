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
	Manager.ExecuteAlgorithms();
	cin.ignore();
	cin.get();
	return 0;
}

