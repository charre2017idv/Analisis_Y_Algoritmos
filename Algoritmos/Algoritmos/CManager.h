#pragma once
#include "Header.h"
#include "Cfibbonnaci.h"
class CManager
{
public:
	CManager();
	~CManager();
public:
	/* Objects*/
	Cfibbonnaci Fibo;
	/* Variables */
	vector<int> m_ascendentes;
	vector<int> m_descendentes;
	vector<int> m_random;
	vector<int> m_bubble;

	double start, end, time;
public:
	void ExecuteAlgorithms();
	vector <int> Ascendentes(int n);
	vector <int> Descendentes(int n);
	vector <int> Random(int n);

	/* Ordenamientos */
	vector <int> BubbleSort(vector <int>);

	void printVectori(vector<int>);
	void SortTrails(vector<int>);
};

