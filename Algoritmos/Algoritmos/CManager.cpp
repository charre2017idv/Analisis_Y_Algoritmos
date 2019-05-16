#include "CManager.h"



CManager::CManager()
{
}


CManager::~CManager()
{
}

void CManager::ExecuteAlgorithms()
{
	Fibo.execute();
}

vector<int> CManager::Ascendentes(int n)
{
	cout << "Vector Ascendentes: [ ";
	for (size_t i = 0; i < n; i++)
	{
		m_ascendentes.push_back(i);
		cout << m_ascendentes[i] << ",";
	}
	cout << " ]" << endl;
	return m_ascendentes;
}

vector<int> CManager::Descendentes(int n)
{
	cout << "Vector Descendente: [ ";
	for (size_t i = 0; i < n; i++)
	{
		m_descendentes.push_back(n-i-1);
		cout << m_descendentes[i] << ",";
	}
	cout << " ]" << endl;
	return m_descendentes;
}

vector<int> CManager::Random(int n)
{
	int a;
	cout << "Vector Random: [ ";
	for (size_t i = 0; i < n; i++)
	{
		a = (rand() % n) + 1;
		m_random.push_back(a);
		cout << m_random[i] << ",";
	}
	cout << " ]" << endl;
	return m_random;
}

vector<int> CManager::BubbleSort(vector<int> Vector)
{
	for (size_t i = 1; i < Vector.size(); i++)
	{
		for (size_t j = 0; j < Vector.size() - 1; j++)
		{
			if (Vector[j] > Vector[j+1])
			{
				int temp = Vector[j];
				Vector[j] = Vector[j + 1];
				Vector[j + 1] = temp;
			}
		}
	}
	return Vector;
}

vector<int> CManager::InsertionSort(vector<int> Vector)
{// Complejidad N, Mejor caso Ordenado N, Peor caso Desordenado N^2, 
	if (Vector.size() > 1) 
	{
		for (int i = 1; i < Vector.size(); ++i) {
			int j = i - 1;
			int temp = Vector[i];
			while (j >= 0 && Vector[j] > temp) {
				Vector[j + 1] = Vector[j];
				--j;
			}
			Vector[j + 1] = temp;
		}
	}
	return Vector;
}

void CManager::benchMark(vector<int> Vector)
{
	start = omp_get_wtime();
	Vector;
	end = omp_get_wtime();
	cout << "Time: " << end - start << " seconds" << endl;

	ficheroSalida.open("InsertBest.txt",ios::app);
	ficheroSalida << end - start << endl;
	ficheroSalida.close();
}

void CManager::printVectori(vector<int> vectori)
{
	for (size_t i = 0; i < vectori.size(); i++)
	{
		cout << vectori[i] << ",";
	}
	cout << endl;
}

void CManager::SortTrails(vector<int> VectorGen)
{
	// Bubble Sort
	//cout << "Bubble Sort" << endl;
	//benchMark(BubbleSort(VectorGen));
	//printVectori(BubbleSort(VectorGen));
	//cout << endl;

	//Insertion Sort
	cout << "Insertion Sort" << endl;
	benchMark(InsertionSort(VectorGen));
	printVectori(InsertionSort(VectorGen));

	cout << endl;
}

