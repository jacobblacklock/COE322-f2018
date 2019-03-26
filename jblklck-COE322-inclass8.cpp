#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main () 
{
	int tf = 0;
	vector<int> randvector;
	int i = 0;
	while (tf == 0)
	{
		int r = (100. * rand()/RAND_MAX); 
		randvector.push_back(r);
		if (randvector[i] == 42)
		{
			tf = 1;
		}
		i = i + 1;
	}
	cout << "Size of random vector: " << randvector.size() << endl;
}
