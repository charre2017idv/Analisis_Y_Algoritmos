#include<iostream> 
#include <list> 
#include <vector>
#include <map>
using namespace std;

class CHash
{
	int BUCKET;    // No. of buckets 
	map<float, vector<int>> HashHash;
	vector <int> Vec;
public:
	CHash(int V);  // Constructor 

	// inserts a key into hash table 
	void insertItem(int x);

};