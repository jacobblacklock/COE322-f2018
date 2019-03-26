//fibonacci
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int fofn(int i)
{
	if (i==0 || i==1)
		return 1;
	else
		return (i-1) + (i-2);
} 

int fib(int i)
{
	if (i==0||i==1)
		return 1;
	else 
		return fib(i-1) + fib(i-2);
}	

int main ()
{
	cout << "Input Fn n value to calculate: " << endl;
	int n;
	cin >> n;
	cout << "Fn is " << fofn(n) << endl;
	cout << "Input how many fibonacci numbers to print out: " << endl;
	int k;
	cin >> k;
	cout << "Fibonacci sequence: " << endl;
	int i;
	for (i=0;i<k;i++)
	{
		cout << fib(i) << endl;
	}
}

