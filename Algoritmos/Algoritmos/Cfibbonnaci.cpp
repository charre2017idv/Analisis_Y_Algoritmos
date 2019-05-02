#include "Cfibbonnaci.h"



Cfibbonnaci::Cfibbonnaci()
{
}


Cfibbonnaci::~Cfibbonnaci()
{
}

int Cfibbonnaci::FibonacciRecursive(int n)
{
	if (n <= 1)
		return n;
	else
		return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int Cfibbonnaci::FibonacciNoRecursive(int n)
{
	m_f;
	m_n1 = 0;
	m_n2 = 1;
	if (n <= 1)
		return n;
	else
		for (size_t i = 1; i < n; i++)
		{
			m_f  = m_n1 + m_n2;
			m_n1 = m_n2;
			m_n2 = m_f;
		}
		return m_f;
}

void Cfibbonnaci::execute()
{
	while (true)
	{
		cout << "\nIntroduce el numero en la secuencia de Fibonacci que quieres calcular: ";
		cin >> m_number;
		cout << "\nEl numero en la secuencia de Fibonacci es: " << m_number << endl;
		start = omp_get_wtime();
		cout << "El valor correspondiente con algoritmo de Fibonnaci Recursivo es : " << FibonacciRecursive(m_number) << endl;
		end = omp_get_wtime();
		time = end - start;
		cout << "Time: " << time << " seconds" << endl;
		
		start = omp_get_wtime();
		cout << "\nEl valor correspondiente con algoritmo de Fibonnaci No Recursivo es : " << FibonacciNoRecursive(m_number) << endl;
		end = omp_get_wtime();
		time = end - start;
		cout << "Time: " << time << " seconds" << endl;
	}
}
