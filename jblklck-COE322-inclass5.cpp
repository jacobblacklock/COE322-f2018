//sum of squares function
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int squares (int i)
{
	if (i > 0)
	{
	int sum = (i*i) + squares(i-1);
	cout << "Sum is "<<sum<<endl;
	}
}

int main ()
{
	squares(100);
}
