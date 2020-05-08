
#include <stdafx.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <stdlib.h> 
#include <stdio.h> 
#include <iomanip>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

const int sizes[4] = { 30000, 100000, 300000, 1000000 };

void merge(long long arr[], int start, int mid, int end)
{
	int start2 = mid + 1;

	if (arr[mid] <= arr[start2]) {
		return;
	}

	while (start <= mid && start2 <= end) {

	
		if (arr[start] <= arr[start2]) {
			start++;
		}
		else {
			int value = arr[start2];
			int index = start2;

			while (index != start) {
				arr[index] = arr[index - 1];
				index--;
			}
			arr[start] = value;

			start++;
			mid++;
			start2++;
		}
	}
}


void mergeSort(long long arr[], int l, int r)
{
	if (l < r) {


		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void swapValue(int *a, int *b)
{
	int *temp = a;
	a = b;
	b = temp;
	return;
}

void InsertionSort(int arr[], int *begin, int *end)
{

	int left = begin - arr;
	int right = end - arr;

	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;


		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	return;
}


int* Partition(int arr[], int low, int high)
{
	int pivot = arr[high];   
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
		
			i++;

			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (arr + i + 1);
}

int *MedianOfThree(int * a, int * b, int * c)
{
	if (*a < *b && *b < *c)
		return (b);

	if (*a < *c && *c <= *b)
		return (c);

	if (*b <= *a && *a < *c)
		return (a);

	if (*b < *c && *c <= *a)
		return (c);

	if (*c <= *a && *a < *b)
		return (a);

	if (*c <= *b && *b <= *a)
		return (b);
}

void IntrosortUtil(int arr[], int * begin, int * end, int depthLimit)
{
	int size = end - begin;
	if (size < 16)
	{
		InsertionSort(arr, begin, end);
		return;
	}

	if (depthLimit == 0)
	{
		make_heap(begin, end + 1);
		sort_heap(begin, end + 1);
		return;
	}
	int * pivot = MedianOfThree(begin, begin + size / 2, end);

	swapValue(pivot, end);

	int * partitionPoint = Partition(arr, begin - arr, end - arr);
	IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
	IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

	return;
}

void introsort(int arr[], int *begin, int *end)
{
	int depthLimit = 2 * log(end - begin);

	IntrosortUtil(arr, begin, end, depthLimit);

	return;
}


int main()
{
	setlocale(LC_ALL, "ru");
	//clock_t start, stop;
	//string path = "1range_1size_1version";
	//ifstream fin;
	//fin.open(path);
	//long long mass[N];
	//int arr[N];
	//if (!fin.is_open()) cout << "Ошибка открытия файла" << endl;
	//else
	//{
	//	cout << "Файл открыт!" << endl;
	//	int i = 0;
	//	while (!fin.eof())
	//	{

	//		fin >> mass[i];
	//		fin >> arr[i];
	//		i++;
	//	}
	//}
	//fin.close();
	//start = clock();
	////mergeSort(mass, 0, N - 1);
	////sort(mass, mass + N);
	////stable_sort(mass, mass + N);
	////introsort(arr, arr, arr + N);
	//stop = clock();
	//cout << "Время "  << (float)(stop - start) / CLOCKS_PER_SEC << " секунд" << endl;
	//cout << endl;

	for (int i =1; i<=4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 5; k++)
			{
				string path =to_string(i) + "range_" + to_string(j) + "size_" + to_string(k) + "verion"; 
				//string path = "1range_1size_"+ to_string(1) + "version";
				cout << path << endl;
				clock_t start, stop;
				ifstream fin;
				fin.open(path);
				const int N = sizes[j-1];
				//long long mass[N];
				long long *mass = new long long[N];
				int *arr =new int [N];
				if (!fin.is_open()) cout << " " << endl;
				else
				{
					cout << "Файл открыт!" << endl;
					int i = 0;
					while (!fin.eof())
					{

						fin >> mass[i];
						fin >> arr[i];
						i++;
					}
				}
				fin.close();
				start = clock();
				
				
				//stable_sort(mass, mass + N);
				introsort(arr, arr, arr + N);
				stop = clock();
				cout << "Время сортировки (1) файла " << path << " " << (float)(stop - start) / CLOCKS_PER_SEC << " секунд" << endl;
				cout << endl;
				for (int i = 1; i <= 4; i++)
				{
					for (int j = 1; j <= 4; j++)
					{
						for (int k = 1; k <= 5; k++)
						{
							string path = to_string(i) + "range_" + to_string(j) + "size_" + to_string(k) + "verion";
							//string path = "1range_1size_"+ to_string(1) + "version";
							cout << path << endl;
							clock_t start, stop;
							ifstream fin;
							fin.open(path);
							const int N = sizes[j - 1];
							long long *mass = new long long[N];
							int *arr = new int[N];
							if (!fin.is_open()) cout << " " << endl;
							else
							{
								cout << "Файл открыт!" << endl;
								int i = 0;
								while (!fin.eof())
								{

									fin >> mass[i];
									fin >> arr[i];
									i++;
								}
							}
							fin.close();
							start = clock();
						    mergeSort(mass, 0, N - 1);
							stop = clock();
				cout << "Время сортировки файла(2) "<< path << " "<< (float)(stop - start) / CLOCKS_PER_SEC << " секунд" << endl;
				cout << endl;

				for (int i = 1; i <= 4; i++)
				{
					for (int j = 1; j <= 4; j++)
					{
						for (int k = 1; k <= 5; k++)
						{
							string path = to_string(i) + "range_" + to_string(j) + "size_" + to_string(k) + "verion";
							//string path = "1range_1size_"+ to_string(1) + "version";
							cout << path << endl;
							clock_t start, stop;
							ifstream fin;
							fin.open(path);
							const int N = sizes[j - 1];
							long long *mass = new long long[N];
							int *arr = new int[N];
							if (!fin.is_open()) cout << " " << endl;
							else
							{
								cout << "Файл открыт!" << endl;
								int i = 0;
								while (!fin.eof())
								{

									fin >> mass[i];
									fin >> arr[i];
									i++;
								}
							}
							fin.close();
							start = clock();
							sort(mass, mass + N);
							stop = clock();
							cout << "Время сортировки файла(3) " << path << " " << (float)(stop - start) / CLOCKS_PER_SEC << " секунд" << endl;
							cout << endl;
							for (int i = 1; i <= 4; i++)
							{
								for (int j = 1; j <= 4; j++)
								{
									for (int k = 1; k <= 5; k++)
									{
										string path = to_string(i) + "range_" + to_string(j) + "size_" + to_string(k) + "verion";
										//string path = "1range_1size_"+ to_string(1) + "version";
										cout << path << endl;
										clock_t start, stop;
										ifstream fin;
										fin.open(path);
										const int N = sizes[j - 1];
										long long *mass = new long long[N];
										int *arr = new int[N];
										if (!fin.is_open()) cout << " " << endl;
										else
										{
											cout << "Файл открыт!" << endl;
											int i = 0;
											while (!fin.eof())
											{

												fin >> mass[i];
												fin >> arr[i];
												i++;
											}
										}
										fin.close();
										start = clock();
										sort(mass, mass + N);
										stop = clock();
										cout << "Время сортировки файла(4) " << path << " " << (float)(stop - start) / CLOCKS_PER_SEC << " секунд" << endl;
										cout << endl;
				delete[] arr;
				delete[] mass;
			}
		}
	}
	return 0;
}


