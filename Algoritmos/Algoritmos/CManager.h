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
	vector<int> m_merge;
	vector<int> m_quick;
	vector<int> m_bucket;
	vector< vector<int> > m_vec;


	double start, end, time;
	ofstream ficheroSalida;
	public:

	void ExecuteAlgorithms();
	vector <int> Ascendentes(int n);
	vector <int> Descendentes(int n);
	vector <int> Random(int n);

	/* Ordenamientos */
	vector <int> BubbleSort(vector <int>);
	vector <int> InsertionSort(vector <int>);

	vector <int> Merge(vector<int> left, vector<int> right);
	vector <int> MergeSort(vector <int>);

	int partition(std::vector<int> &vec, int low, int high);
	vector<int> quickSort(std::vector<int>& vec, int low, int high);

	vector<int> CountingSort(vector <int> &Vector);
	vector<int> BucketSort(vector <int> &Vector);
	vector<int> radixSort(vector <int> &Vector);
	
	int linearSearch(std::vector<int> vec, int value);
	int binarySearch(std::vector<int> vec, int l, int r, int value);

	void benchMark(vector<int>);
	void benchMarkSerch(int);
	void printVectori(vector<int>);
	void printSearchi(int);
	void SortTrails(vector<int>);
};

