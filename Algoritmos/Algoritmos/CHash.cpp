#include "CHash.h"


CHash::CHash(int b)
{
	
}

void CHash::insertItem(int x)
{
	int a;
	cout << "Vector Random: [ ";
	for (size_t i = 0; i < x; i++)
	{
		a = (rand() % x) + 1;
		Vec.push_back(a);
		//HashHash.insert(std::make_pair(1,));
		HashHash[i].push_back (a);
		cout << Vec[i] << ",";
	}
	cout << " ]" << endl;

}

