#include<iostream>
using namespace std;

int Sum(int n, ...);

void main()
{

	setlocale(LC_ALL, "");
	cout << Sum(3, 5.8, 13, 21, 0) << endl;
}

int Sum(int n, ...);
{
	int sum = 0;
	int* pn = &n;
	while (*pn !=0)
	{
		sum += *pn++;
	}
	return sum;
}