//Binary Search Trees

struct Node {
    int data;
    bool visited;
    vector<Node*> Nodes;
  };


	//find min node in BST
	Node* findMin(Node*A){
	  while(A->left != 0)
	    A = A->left;
	  return A;
	}

	//Delete Node
	void deleteFromTree(Node*A, int d){
	  if(A == 0) return;

	  if(d < A->d) deleteFromTree(A->left,d);
	  else if (d > A->d) deleterFromTree(A->right, d);
	  else{//found node to delete
	    Node* T;
	    //case 1: no children
	    if(A->left == 0 && A->right == 0){
	      delete(A);
	      A = null;
	    }
	    //case 2: only one child
	    else if (A->left == 0){
	      T = A;
	      A = A->right;
	      delete(T);
	      T= null;
	    }else if (A->right == 0){
	      T = A;
	      A = A->left;
	      delete(T);
	      T = null;
	    }//two children
	    else{
	      T = findMin(A->right);
	      A->d = T->d; //copy them (study copy constructors)
	      deleteFromTree(A->right, T->d);
	    }
	  }
	}
	
//Search Node
Node* search(Node* A, int d, Node* T){
  if(A == 0) return T;
  if(d < A->value) T = search(A->left, d, T);
  else if(d > A->value) T = search(A->right, d, T);
  else return A;

  return T;
}

//Search Node returning Success
bool search(Node*A, int d, bool found){
    if (!A) return found;
    if(found) return found;

    if(A->data == d){
      found = true;
      return found;
    }

    if( d < A->data)
      found = search(A->left, d, found);
    if( d > A->data)
      found = search(A->right, d, found);

    return found;

  }


//Insert Node
void insert(Node* A, int d){
  if(A == 0) A = new Node(d);
  if(d < A->value) insert(A->left, d);
  else insert(A->right, d);
}

  //Tree Height
	int treeHeight(Node *A){
	  if (A == 0) return 0;
	  return 1 + (max(treeHeight(A->left), treeHeight(A->right)));
	}

	//Is balanced BST
	bool isBalancedTree(Node* A){
	  if (A == 0) return true;
	  return abs(treeHeight(A->left) - treeHeight(A->right)) <= 1;
	}

	//////////
	
//Graphs

//Representation

//benefits?
class GraphNode {
	int d;
	vector<GraphNode*> Nodes;
}

//can be of GraphNode too
vector<vector<int>> AdjacencyList;

//can adjacency matrix
vector<vector<int>> AdjacencyMatrix;

//AdjacencyList with weights
vector<vector<pair<int,int>>> AdjacencyListWithWeights //where AdjacencyListWithWeights[i] = make_pair(distance,value)

//Traversal

  //maze runner
  
vector<int> X = {1,0,-1, 0};
vector<int> Y = {0,1, 0, -1};

  bool MR(int i, int j){
    if (found) return;
    if (visited[i][j]) return;
    if (OutOfRange(i,j))return;

    visited[i][j] = true;
    if (M[i][j] == 'exit'){
      found = true;
      return;
    }

    for (int k = 0; k < 4; k++)
        MR(i+X[k],j+Y[k]);
  }

  //dfs
  void dfs(Node* A){
    if (A->visited)return;
    A->visited = true;
    for (auto node: A->Nodes)
      dfs(node);
  }

  //pseudo dfs
  void dfs(Node *A){
   stack<Node*> S;
   Node * T;
   S.push(A);
   while(!S.empty()){
     T = S.top();
     S.pop();
     T->visited = true;
     for(auto n : T->Nodes)
      S.push(n);
   }
  }

  //bfs
  void bfs(Node* A){
    queue<Node*> Q;
    Q.push(A);
    Node* T;
    while(!Q.empty()){
      T = Q.front();
      Q.pop();
      T->visited = true;
      for (auto node : T->Nodes)
        Q.push();
    }
  }

  
  //Sorting
  
  
 //topological sort
  stack<Node*> TP(Node*A, Graph G){
    stack<Node*> S;
    for (auto V: G){
      S = dfsS(V,S);
    }

    return S;
  }

  stack<Node*> dfsS(Node*A, stack<Node*> S){
    if(A->visited) return S;
    A->visited =true;
    for(auto a: A->Nodes)
      S = dfsS(a,S);
    S.push(A);
    return S;
  }
  
  
//Optimized search

//implement > operator for your class Node
bool operator > (const Node& l, const Node& r){
  return l.d > r.d;
}

vector<Node*> dijkstra(Node* A){
  priority_queue<Node*, vector<Node*>, greater<Node*> P;

  P.push(A);
  Node* T;
  vector<Node*> path;

  while(!P.empty()){
    T = P.top(); P.pop();
    T->visited = true;
    path.push_back(T);
    for(auto node : T->Nodes){
      if(!node->visited)
        P.push(node);
    }
  }

  return path;
}

//representations for adjacency lists

int N; //number of vertices
vector<vector<int>> Graph; //the graph
vector<int> visited; //visited nodes

void dfs(int node){
  if(!visited[node]){
    visited[i] = true;
    for(auto vertex : Graph[node])
      dfs(vertex);
  }
}

void bfs(int node){
  queue<int> Q;
  int temp;
  Q.push(node);

  while(!Q.empty()){
    temp = Q.front(); Q.pop();
    if(!visited[node]){
      visited[vertex] = true;
      for (auto vertex : Graph[node])
        Q.push(vertex);
    }
  }
}

//why use?
bool check_graph_connected_dfs(){
  int start = 0;
  auto visited = vector<int>(N,false);
  dfs(start);
  return(find(V.begin(), V.end(), 0) == V.end());
}

//Heaps

vector<int> BubbleDown(Node* A, int i){
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l >= A.size()) return A;

  int min_i = i;

  if(A[l] < A[i]) min_i = l;

  if(r < A.size() && A[r] < A[min_i]) min_i = r;

  if(min_i != i){
    swap(A[i], A[min_i]);
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

vector<int> heapify(Node* A){
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