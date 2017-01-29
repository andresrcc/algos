//---Comparison based sorting---//
//merge, quicksort heapsort
//dont care type of data sorted. They only compare data.
//all take an input array a and sort its elements into a non-decreasing order in O(n log n)

//Merge-Sort
//Classic divide and conquer.
//if a.size() == 1 -> assume already sorted.
//else split into two halves a0 = a[0], ... , a[n/2 - 1] and a1 = a[n/2] , ... , a[n-1]
//sort each recursively
//merge the sorted a0 and a1 to get the fully sorted a0
#include "stdafx.h"
#include <iostream>
#include<vector>
#include <queue>
#include <list>
#include <iomanip>

using namespace std;

#define SIZE 9

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

vector<int> merge(vector<int> left, vector<int> right)
{
	vector<int> result;
	while ((int)left.size() > 0 || (int)right.size() > 0) {

		if ((int)left.size() > 0 && (int)right.size() > 0) {
			if ((int)left.front() <= (int)right.front()) {
				result.push_back((int)left.front());
				left.erase(left.begin());
			}
			else {
				result.push_back((int)right.front());
				right.erase(right.begin());
			}
		}

		else if ((int)left.size() > 0) {
			for (int i = 0; i < (int)left.size(); i++)
				result.push_back(left[i]);
			break;
		}

		else if ((int)right.size() > 0) {
			for (int i = 0; i < (int)right.size(); i++)
				result.push_back(right[i]);
			break;
		}
	}
	return result;
}

vector<int> mergeSort(vector<int> m)
{
	if (m.size() <= 1)
		return m;

	vector<int> left, right, result;
	int middle = ((int)m.size() + 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(m[i]);
	}

	for (int i = middle; i < (int)m.size(); i++) {
		right.push_back(m[i]);
	}

	left = mergeSort(left);
	right = mergeSort(right);
	result = merge(left, right);

	return result;
}

//QuickSort
int Partition(vector<int>& numbers, int left, int right, int pivot){
    while(left <= right){
        while(numbers[left] < pivot) left++;
        while(numbers[right] > pivot) right--;

        if(left <= right){
            iter_swap(numbers.begin() + left,numbers.begin() + right);
            left++;
            right--;
        }
    }
    return left;
}

void QuickSort(vector<int> &numbers, int left, int right){
    if (left >= right) return; //nothing to sort

    int pivot = numbers[(left + right)/2];
    int index = Partition(numbers, left, right, pivot);
    QuickSort(numbers, left, index-1);
    QuickSort(numbers, index, right);


}


//Heapsort

vector<int> BubbleDown(vector<int> A, int i){
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l >= A.size()) return A;

  int min_i = i;

  if(A[l] < A[i]) min_i = l;

  if(r < A.size() && A[r] < A[min_i]) min_i = r;

  if(min_i != i){
    iter_swap(A.begin() + i, A.begin() + min_i);
    A = BubbleDown(A,min_i);
  }

  return A;
}

vector<int> heapify(vector<int> A){
  for(int i = A.size() - 1; i >=0; i--)
    A = BubbleDown(A,i);
  return A;
}

 void heapSort(vector<int> &A) {
    vector<int> heap = heapify(A);
	int n = A.size() - 1;
	
	while( n > 1){
		iter_swap(heap.begin() + n, heap.begin());
		BubbleDown(heap,0);
		n--;
	}
	
	A = heap.reverse();
  }

//----integer sorting algorithms----//
//Specialized for sorting small integers

//counting sort
void CountingSort(vector<int> arr)
{
	int i, j, k;
	int idx = 0;
	int min, max;

	min = max = arr[0];
	for (i = 1; i < arr.size(); i++)
	{
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;
	/* creates k buckets */
	vector<int> B(k, 0);

	for (i = 0; i < k; i++) B[i] = 0;

	for (i = 0; i < arr.size(); i++) B[arr[i] - min]++;
	for (i = min; i <= max; i++)
		for (j = 0; j < B[i - min]; j++) arr[idx++] = i;
}

//radix sort
const int MAX = 10;
void RadixSortLSD(vector<int> a)
{
	int i, bucket[MAX], maxVal = 0, digitPosition = 1;
	for (i = 0; i < a.size(); i++)
	{
		if (a[i] > maxVal) maxVal = a[i];
	}

	int pass = 1; // used to show the progress

	/* maxVal: this variable decide the while-loop count
	if maxVal is 3 digits, then we loop through 3 times */
	while (maxVal / digitPosition > 0)
	{
		/* reset counter */
		int digitCount[10] = {0};

		/* count pos-th digits (keys) */
		for (i = 0; i < a.size(); i++)
			digitCount[a[i] / digitPosition % 10]++;

		/* accumulated count */
		for (i = 1; i < 10; i++)
			digitCount[i] += digitCount[i - 1];

		/* To keep the order, start from back side */
		for (i = a.size() - 1; i >= 0; i--)
			bucket[--digitCount[a[i] / digitPosition % 10]] = a[i];

		/* rearrange the original array using elements in the bucket */
		for (i = 0; i < a.size(); i++)
			a[i] = bucket[i];

		/* move up the digit position */
		digitPosition *= 10;
	}
}
