#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int*push_back(int arr[], int &n, int value);


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