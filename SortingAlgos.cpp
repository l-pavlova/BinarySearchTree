#include <iostream>
using namespace std;


//SLOW
//best case O(n)
//worst case O(n^2)
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//best case O(n)
//worst case O(n^2)
void insertionSort(int* arr, int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//worst case & best case O(n^2)
void selectionSort(int* arr, int n)
{
	int index = 0;
	for (int i = 0; i < n - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
}
//FAST
void merge(int* arr, int l, int m, int r)
{
	int i, j;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + j + 1];
	i = 0;
	j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[l + k] = L[i++];
		}
		else
		{
			arr[l + k] = R[j++];
		}
		k++;
	}
	while (i < n1)
	{
		arr[l + k] = L[i++];
		k++;
	}
	while (j < n2)
	{
		arr[l + k] = R[j++];
		k++;
	}
}
//worst case O(nlogn)
//best case O(nlogn)
//requires O(n) memory
void mergeSort(int* arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}

}
int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
//worst case O(n^2)
//best case O(nlogn)
//doesnt require extra space, better for smaller arrays
void quickSort(int* arr, int l, int r)
{

	if (l < r)
	{
		int pi = partition(arr, l, r);

		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}

}
int* countingSort(int* arr, int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int* helper = new int[max + 1];
	for (int i = 0; i <= max; i++)
	{
		helper[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		helper[arr[i]]++;
	}
	for (int i = 1; i < max + 1; i++)
	{
		helper[i] += helper[i - 1];
	}
	int j = 0;
	int* res = new int[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		helper[arr[i]]--;
		res[helper[arr[i]]] = arr[i];
	}
	return res;
}

int main()
{
	//tests
	int arr[13] = { 1,9,2,5,3,4,6,7,8,17,56,21, 33 };
	//bubbleSort(arr, 13);
	//insertionSort(arr, 13);
	//selectionSort(arr, 13);
	//mergeSort(arr, 0, 12);
	//auto res = countingSort(arr, 13);
	quickSort(arr, 0, 12);
	for (int i = 0; i < 13; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cin.get();
	return 0;
}
