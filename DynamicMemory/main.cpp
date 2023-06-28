#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int*push_back(int arr[], int &n, int value);
int*push_front(int arr[], int &n, int value);

int*pop_back(int arr[], int &n);



void main()
{
    setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
    int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
    Print(arr, n);

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";

	}
	cout << endl;
}

int* push_back(int arr[], int &n, int value)
{
	//Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];

	//копируем значения из исходного массива
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	// Удаляем массив
	delete[] arr;

	//Подменяем адрес старого новым массивом

	arr = buffer;

	//только после этого можно добавить значение:
	arr[n] = value;

	//"Только после этого в массив arr, можно добавить значение.
	n++;
	// Возвращаем новый массив.

	return arr;
}
int* push_front(int arr[], int& n, int value) 
{
	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];

	}
	delete[] arr;
    arr = buffer;
	arr[0] = value;
	n++;
	return buffer;
 
	


}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}