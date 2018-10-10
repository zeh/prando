#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>

void ShiftDown(int *arr, int i, int size)
{
	int k = i;
	int j = -8888;
	while (j != k)
	{
		j = k;
		if (2 * j <= size && arr[2 * j] > arr[k])
		{
			k = 2 * j;
		}
		if (2 * j + 1 <= size && arr[2 * j + 1] > arr[k])
		{
			k = 2 * j + 1;
		}
		std::swap(arr[j], arr[k]);
		//std::cout << "SWAP:" << i << "<->" << j << "   ";
	
	}
		
	
}

void HeapSort(int *arr, int size)
{
	//build heap structure
	for (int i = size / 2; i >= 0; i--)
	{
		ShiftDown(arr, i, size);
	}
	//sort
	for (int i = size; i >= 1; i--)
	{
		std::swap(arr[0], arr[i]);
		ShiftDown(arr, 0, i-1);
	}
}

int *GenerateRand(int size)
{
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20000;
	}
	return arr;
}

int main()
{
	int size = 200;
	int *arr = GenerateRand(size);

	HeapSort(arr, size-1);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//delete arr;
	system("pause");
	return 0;
}
