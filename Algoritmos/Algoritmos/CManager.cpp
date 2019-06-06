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

vector<int> CManager::Merge(vector<int> left, vector<int> right)
{
	vector<int> result;
	while (left.size() > 0 || right.size() > 0) 
	{
		if (left.size() > 0 && right.size() > 0)
		{
			if (left[0] <= right[0]) 
			{
				result.push_back(left[0]);
				left.erase(left.begin());
			}
			else 
			{
				result.push_back(right[0]);
				right.erase(right.begin());
			}
		}
		else if (left.size() > 0) 
		{
			for (int i = 0; i < left.size(); i++)
				result.push_back(left[i]);
			break;
		}
		else if (right.size() > 0) 
		{
			for (int i = 0; i < right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}

vector<int> CManager::MergeSort(vector<int> m)
{
	if (m.size() <= 1)
		return m;

	vector<int> left, right, result;
	int middle = ((int)m.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(m[i]);
	}

	for (int i = middle; i < (int)m.size(); i++) {
		right.push_back(m[i]);
	}

	left = MergeSort(left);
	right = MergeSort(right);
	result = Merge(left, right);

	return result;
}

int CManager::partition(std::vector<int> &vec, int low, int high)
{
	int pivot = vec[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{

		if (vec[j] <= pivot)
		{
			i++;
			int swap = vec[i];
			vec[i] = vec[j];
			vec[j] = swap;
		}
	}
	int swap = vec[i + 1];
	vec[i + 1] = vec[high];
	vec[high] = swap;
	return (i + 1);
}

vector <int> CManager::quickSort(std::vector<int>& vec, int low, int high)
{
	if (low < high)
	{
		int mid = partition(vec, low, high);

		quickSort(vec, low, mid - 1);
		quickSort(vec, mid + 1, high);
	}
	return vec;
}

vector <int> CManager::CountingSort(vector<int>& Vector)
{
	int max = *max_element(Vector.begin(), Vector.end());
	int min = *min_element(Vector.begin(), Vector.end());
	int range = max - min + 1;
	vector<int> count(range), output(Vector.size());

	// Store count of each character
	for (int i = 0; i < Vector.size(); i++)
		count[Vector[i] - min]++;
	// Change count[i] so that count[i] now contains actual position of this character in output array  
	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];
	// Gen the output array
	for (int i = Vector.size() - 1; i >= 0; i--)
	{
		output[count[Vector[i] - min] - 1] = Vector[i];
		count[Vector[i] - min]--;
	}
	// Copy the output array to vector, so that Vector now  contains sorted characters 
	for (int i = 0; i < Vector.size(); i++)
		Vector[i] = output[i];

	return Vector;
}

vector<int> CManager::BucketSort(vector<int> &Vector)
{
	int i, j;
	int count[20];
	int n = Vector.size();
	for (i = 0; i < n; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		(count[Vector[i]])++;

	for (i = 0, j = 0; i < n; i++)
		for (; count[i] > 0; (count[i])--)
			Vector[j++] = i;

	m_bucket = Vector;
	return m_bucket;
}

vector<int> CManager::radixSort(vector<int>& Vector)
{
	m_vec.resize(10);
	int temp, m = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < Vector.size(); j++)
		{
			temp = (int)(Vector[j] / pow(10, i)) % 10;
			m_vec[temp].push_back(Vector[j]);
		}
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < m_vec[k].size(); l++)
			{
				Vector[m] = m_vec[k][l];
				m++;
			}
			m_vec[k].clear();
		}

		m = 0;
	}


	return Vector;
}

int CManager::linearSearch(std::vector<int> vec, int value)
{

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int CManager::binarySearch(std::vector<int> vec, int l, int r, int value)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (vec[mid] == value)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (vec[mid] > value)
			return binarySearch(vec, l, mid - 1, value);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(vec, mid + 1, r, value);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
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

void CManager::benchMarkSerch(int i)
{
	start = omp_get_wtime();
	i;
	end = omp_get_wtime();
	cout << "Time: " << end - start << " seconds" << endl;

	ficheroSalida.open("Serch.txt", ios::app);
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

void CManager::printSearchi(int i)
{
	cout << "The Search is in: " << i << endl;
}

void CManager::SortTrails(vector<int> VectorGen)
{
	// Bubble Sort
	//cout << "Bubble Sort" << endl;
	//benchMark(BubbleSort(VectorGen));
	//printVectori(BubbleSort(VectorGen));
	//cout << endl;
	
	////Insertion Sort
	//cout << "Insertion Sort" << endl;
	//benchMark(InsertionSort(VectorGen));
	//printVectori(InsertionSort(VectorGen));
	
	//// Merge Sort
	//cout << "Merge Sort" << endl;
	//benchMark(MergeSort(VectorGen));
	//printVectori(MergeSort(VectorGen));

	// Quick Sort
	//cout << "Quick Sort" << endl;
	//benchMark(quickSort(VectorGen, 0, VectorGen.size()));
	//printVectori(quickSort(VectorGen,0,VectorGen.size()));

	// Counting Sort
	//cout << "Counting Sort" << endl;
	//benchMark(CountingSort(VectorGen));
	//printVectori(CountingSort(VectorGen));

	// Bucket Sort
	//cout << "Bucket Sort" << endl;
	//benchMark(BucketSort(VectorGen));
	//printVectori(BucketSort(VectorGen));

	// Radix Sort
	cout << "Radix Sort" << endl;
	benchMark(radixSort(VectorGen));
	printVectori(radixSort(VectorGen));

	// Binary Search
	//cout << "Binary Search" << endl;
	//benchMarkSerch(binarySearch(VectorGen, 0, VectorGen.size(), 6));
	//printSearchi(binarySearch(VectorGen, 0, VectorGen.size(), 6));

	// Binary Search
	//cout << "Linear Search" << endl;
	//benchMarkSerch(linearSearch(VectorGen, 6));
	//printSearchi(linearSearch(VectorGen  , 6));

	cout << endl;
}

