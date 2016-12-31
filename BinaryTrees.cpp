//Binary Search Trees

struct Node {
	int d;
	bool visited;
	Node* left;
	Node* right;

	Node(int data)
	{
		d = data;
		visited = false;
		left = nullptr;
		right = nullptr;
	}
};


//find min node in BST
Node* findMin(Node*A) {
	while (A->left != nullptr)
		A = A->left;
	return A;
}

//Delete Node
//Remember:
//When passing the pointer to the node, 
//either pass a reference to the pointer, 
//or return the pointer to node after making the changes
void deleteFromTree(Node* & A, int d)
{
	if (A == nullptr) return;

	if (d < A->d) deleteFromTree(A->left, d);
	else if (d > A->d) deleteFromTree(A->right, d);
	else
	{//found node to delete
		Node* T;
		//case 1: no children
		if (A->left == nullptr && A->right == nullptr)
		{
			delete(A);
			A = nullptr;
		}
		//case 2: only one child
		else if (A->left == nullptr)
		{
			T = A;
			A = A->right;
			delete(T);
			T = nullptr;
		}
		else if (A->right == nullptr)
		{
			T = A;
			A = A->left;
			delete(T);
			T = nullptr;
		}//two children
		else
		{
			T = findMin(A->right);
			A->d = T->d; //copy them (study copy constructors)
			deleteFromTree(A->right, T->d);
		}
	}
}

//Print tree, BFS style
void printTree(Node* A)
{
	queue<Node*> Q;

	Q.push(A);
	Node* T;

	while(!Q.empty())
	{
		T = Q.front();Q.pop();
		cout << T->d << " ";

		if(T->left != nullptr)
			Q.push(T->left); 
		if(T->right != nullptr)
			Q.push(T->right);
	}
}


//Search Node
Node* search(Node* A, int d, Node* T)
{
    if (A == 0) return T;
    if (d < A->d) T = search(A->left, d, T);
    else if (d > A->d) T = search(A->right, d, T);
    else return A;

    return T;
}

//Search Node returning Success
bool search(Node* A, int d, bool found)
{
    if (!A) return found;
    if (found) return found;

    if (A->d == d)
    {
        found = true;
        return found;
    }

    if (d < A->d)
        found = search(A->left, d, found);
    if (d > A->d)
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

	
//Invert tree
Node* InvertTree(Node * node){

	//base case
	if(node == 0) return null;
	
	//get children
	Node* right = InvertTree(node->left);
	Node* left = InvertTree(node->right);
	
	//switch children on way back
	node->left = right;
	node->right = left;
	
	return node;

}

//O(n) because each node is visited only once. Traversals are different from searches which are O(log n)!


/*
Iteration 1 : i = 0, j = 0. arr[0] < arr[0] is false. So, the inner while loop breaks.
Iteration 2: i =1, j = 0. arr[1] < arr[0] is true. j becomes 1.
Iteration 3 : i = 1, j = 1. Condition false. We break. Note that j will remain 1 and is not reset back to 0.
Iteration 4 : i = 2, j = 1. arr[2] < arr[1]. True. j = 2.
Iteration 5 : i = 2, j = 2. Condition false. Break.
Iteration 6 : i = 3, j = 2. arr[3] < arr[2]. True. j = 3.
Iteration 7 : i = 3, j = 3. Condition false. Break.
*/
