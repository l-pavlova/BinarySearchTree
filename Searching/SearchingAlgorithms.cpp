#include <iostream>

using namespace std;

//O(logn)
bool binarySearch(int* sortedArr, int start, int end, int num)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (sortedArr[mid] == num)
			return true;
		else if (sortedArr[mid] > num)
			return binarySearch(sortedArr, start, mid - 1, num);
		else
			return binarySearch(sortedArr, mid + 1, end, num);
	}
	return false;
}
//O(logn)
bool ternarySearch(int* sortedArr, int left, int right, int num)
{
	while (left < right)
	{
		int mid1 = (2 * left + right) / 3;
		int mid2 = (left + right * 2) / 3;
		if (sortedArr[mid1] == num || sortedArr[mid2] == num)
			return true;
		if (sortedArr[mid1] > num)
			return ternarySearch(sortedArr, left, mid1-1, num);
		else if (sortedArr[mid1]<num && sortedArr[mid2]>num)
			return ternarySearch(sortedArr, mid1+1, mid2-1, num);
		else
			return ternarySearch(sortedArr, mid2+1, right, num);
	}
	return false;
}
int main()
{

	int arr[8] = { 3,6,8,13,77,321,544,600 };
	cout << ternarySearch(arr, 0, 7, 544);
	cin.get();
	return 0;
}
