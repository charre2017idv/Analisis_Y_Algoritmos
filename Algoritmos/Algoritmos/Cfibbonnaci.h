//--------------------------------------------------------------------------------------
// File: Cfibbonnaci.h
// Version: v 0.1
// Creation Date: 29/04/2019
// Author: Roberto Charreton Kaplun
// Summary: 
// Errors: 
// Bugs: 
// Nice to Have: 0,1,1,2,3,5,8,13,21,34.
//--------------------------------------------------------------------------------------
#pragma once
#include "Header.h"
class Cfibbonnaci
{
public:
	Cfibbonnaci();
	~Cfibbonnaci();
public:
	int FibonacciRecursive(int n);
	int FibonacciNoRecursive(int n);
	void execute();
public:
	int m_number;
	double start, end, time;
	int m_x = 0;
	int m_f;
	int m_n1;
	int m_n2;
};

