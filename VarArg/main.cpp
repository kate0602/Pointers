#include<iostream>
#include<stdarg.h>
using namespace std;

//int Sum(int n, ...);
template<typename T>T Sum(int n, T value ...);

void main()
{
	setlocale(LC_ALL, "");
	cout << Sum(6,3, 5, 8, 13, 21 ,34) << endl;
}

int Sum(int n, ...)
{
	int sum = 0;
	/*int* pn = &n;
	while (*pn != 0)
	{
		sum += *pn++;
	}*/

	for (int* pn = &n; *pn; sum += *pn++);
	

	return sum;
}

template<typename T>T Sum(int n, T value ...)
{
	int sum = 0;
	va_list list;
	va_start(list, n);
	for (int i = 0; i < n; i++)
	{
		value = va_arg(list, T);
		cout << value << "\t";
		sum += value;

	}
	cout << endl;
	va_end(list);
	return sum;
}