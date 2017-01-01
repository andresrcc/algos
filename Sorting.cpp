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

//QuickSort. Call as such qsort(a, 0, SIZE - 1);
/* swap a[i] and a[j] */
void swap(int a[], int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


/* sort arr[left]...arr[right] into increasing order */
void qsort(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if (left_index >= right_index) return;

	left = left_index;
	right = right_index;

	// pivot selection
	pivot = a[(left_index + right_index) / 2];

	// partition
	while (left <= right) {
		while (a[left] < pivot) left++;
		while (a[right] > pivot) right--;
		if (left <= right) {
			swap(a, left, right);
			left++; right--;
		}
	}

	// recursion
	qsort(a, left_index, right);
	qsort(a, left, right_index);
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
void countingSort(vector<int> &A, int k) {
  vector<int> C(k, 0);

	//count ocurrences of A[i], hence the name "counting sort"
  for (int i = 0; i < A.size(); i++)
    C[A[i]]++;

//extra effort in case elements of A have associated data
//running sum of the counters, such that c[i] is number of elements in a less than or equal to i
//I believe this is done to keep track of repeated elements and where in the array they should be added.
  for (int i = 1; i < k; i++)
    C[i] += C[i-1];
  
  //place the elements backwards.
  vector<int> B(A.size());
  for (int i = A.size()-1; i >= 0; i--)
    B[--C[A[i]]] = A[i];

  A = B;
}
