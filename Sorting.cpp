// Comparison based sorting
//merge, quicksort heapsort
//dont care type of data sorted. They only compare data.
//all take an input array a and sort its elements into a non-decreasing order in O(n log n)

//Merge-Sort
//Classic divide and conquer.
//if a.size() == 1 -> assume already sorted.
//else split into two halves a0 = a[0], ... , a[n/2 - 1] and a1 = a[n/2] , ... , a[n-1]
//sort each recursively
//merge the sorted a0 and a1 to get the fully sorted a0

void merge(vector<int> &A0, vector<int> &A1, vector<int>& A){
	int i0 = 0, i1 = 0;
	
	for(int i = 0; i < A.size();i++){
		if(i0 == A0.size())
			A[i] = A1[i1++];
		else if (i1 == A1.size())
			A[i] = A0[i0++];
		else if (A0[i0] < A1[i1])
			A[i] = A0[i0++];
		else
			A[i] = A1[i1++];
	}
}

void mergeSort(vector<int> &A){
	if(A.size() <= 1) return;
	
	vector<int> A0,A1;
	
	A0.assign(A.begin(),A.begin() + A.size()/2);
	A1.assign(A.begin() + A.size()/2 + 1, A.end());

	mergeSort(A0);
	mergeSort(A1);
	
	merge(A0,A1,a);
}

//Quicksort

void quickSort(vector<int> A){
	quickSort(A,0);
}
//notice how on each iteration: p increases and q decreases. And element at position j is either moved to the front, left where it is or moved to the back.
void quickSort(vector<int>& A, int start){
	int n = A.size();
	if(n <= 1) return;
	
	int pivot = A[start + rand() % n];
	
	int p = start - 1;
	int j = start; 
	int q = start + n;
	
	// a[i .. p] < x < a[q..i+n-1]

	while (j < q){
		if(A[j] < pivot) swap(j++, ++p);  //move to left partition (beginning of array)
		else if (A[j] > pivot) swap(j,--q); //move to right partition (end of array)
		else j++ //keep in the middle
	}
	
	quickSort(A, start, p - start + 1);
	quickSort(A, q, n - (q - start ));
	
}
