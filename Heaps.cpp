//Heaps

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

//verify but im pretty sure this is ok
int getParent(int i){
  if(i%2 == 0) return (i - 2) / 2;
  return (i - 1) / 2;
}


vector<int> BubbleUp(vector<int> A, int i){
  if(i == 0) return A;

  int parent_i = getParent(i);

  if(A[i] < A[parent_i]){
    swap(A[i], A[parent_i]);
    A = BubbleUp(A,parent_i);
  }
  return A;
}

vector<int> heapify(vector<int> A){
  for(int i = A.size() - 1; i >=0; i--)
    A = BubbleDown(A,i);
  return A;
}

vector<int> insertIntoHeap(vector<int> A, int d){
  if(A.size() == 0) return A;
  A.push_back(d);
  return BubbleUp(A,A.size()-1);
}

vector<int> removeFromHeap(vector<int> A){
  if(A.size() == 0) return A;
  A[0] = A[A.size() -1]; //copy last node to first
  A.pop_back(); //pop back to remove last node
  return BubbleDown(A,0); //bubble down to adjust the tree after removing
}
