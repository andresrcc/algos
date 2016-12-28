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
