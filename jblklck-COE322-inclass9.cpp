//vector challenge ica 9
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<float> random_vector(int length)
{
	vector<float> vector1(length);	
	for (auto &i : vector1)
	{
		i = (10. * rand()/RAND_MAX);
	}	
	return vector1;
}

vector<float> sort(vector<float> vector2)
{
	int length = vector2.size();
	for (int j; j<length; j++)
	{
		//change starting point of vector loop
		double vectormin = vector2[j];
		for (int i = j; i < length; i++)
		{	
			//loop through to replace first value with minimum value
			if (vector2[i] < vectormin)
			{
				vector2[j] = vector2[i];
				vector2[i] = vectormin;
				vectormin = vector2[j];
			}
		}	
	}
	return vector2;
}

void printvector(vector<float> vector3)
{
	for (auto i : vector3)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main() 
{
	//creates a vector of random values of a specified length then sorts it
	int length = 10;
	
	vector<float> values = random_vector(length);	
	vector<float> values2 = sort(values);
	
	cout << "Before sorting: " << endl;
	printvector(values);
	cout << "After sorting (min to max): " << endl;
	printvector(values2);
}



