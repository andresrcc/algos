/**
To Do:
*Include traversing in pre post and in order
*Include IsBST method
*Include sucessor and predecessor
*Test further
*/

struct Node{
	int data;
	bool visited;
	Node* left;
	Node* right;
	
	Node(int d){
		data = d;
		visited = false;
		left = nullptr;
		right = nullptr;
	}
};

class Tree{
	Node* root;
	public:
	
	Tree(){
		root = nullptr;
	}
	
	Node* findMin(){
		if (root == nullptr) return nullptr;
		return findMin(root);
	}
	
	Node* findMin(Node* A){
		Node* T = A;
		while(T->left != nullptr)
			T = T->left;
		return T;
	}
	
	int treeHeight(){
		if (root == nullptr) return -1;
		return treeHeight(root);
	}
	
	int treeHeight(Node* A){
		if(A == nullptr) return -1;
		return max(treeHeight(A->left), treeHeight(A->right)) + 1;
	}
	
	bool isBalancedBST(){
		if(root == nullptr) return true;
		return isBalancedBST(root);
	}
	
	bool isBalancedBST(Node* A){
		return abs(treeHeight(A->right) - treeHeight(A->left)) <= 1;
	}
	
	void insert(int d){
		if(root == nullptr) return;
		insert(root, d);
	}
	
	void insert(Node* A, int d){
		if(A == nullptr){
			A = new Node(d);
			return;
		}
		
		if(d < A->data) insert(A->left, d);
		else insert(A->right,d);
	}
	
	bool search(int d){
		if (root == nullptr) return;
		return search(root, d);
	}
	
	bool search(Node*A, int d){
		
		bool found = false;
		
		if (d == A->data){
			return true;
		}
		
		
		if(d < A->data) found = search(A->left,d);
		else found = search(A->right, d);
		
		return found;
	}
	
	Node* search(int d){
		if(root == nullptr) return;
		return search(root,d);
	}
	
	Node* search(int d){
		if(d == A->data){
			return A;
		}
		
		Node* T = nullptr;
		
		if(d < A->data) T = search(A->left, d);
		else T = search(A->right, d);
		
		return T;
	}
	
	void deleteNode(int d){
		if(root = nullptr) return;
		deleteNode(root, d);
	}
	
	void deleteNode(Node* A, int d){
		if (A == nullptr) return;
		
		if(d < A->data) deleteNode(A->left, data);
		else if(d > A->data) deleteNode(A->right, data);
		else{
			if(A->left == nullptr && A->right == nullptr)
				delete(A);
			else if (A->left == nullptr && A->right != nullptr){
				Node* T = A;
				A = A->right;
				delete T;
			}else if(A->right == nullptr && A->left !- nullptr){
				Node* T = A;
				A = A->left;
				delete T;
			}
			else{
				//copy minimum on right to A, delete minimum
				Node* T = findMin(A->right);
				A->d = T->d; //(copy the data)
				deleteNode(A->right, T->d);
				
			}
		}
	}
	
	void invertTree(){
		if (root == nullptr) return;
		root = invertTree(root);
	}
	
	Node* invertTree(Node* A){
		if(A == nullptr) return nullptr;
		
		Node* left = invertTree(A->left);
		Node* right = invertTree(A->right);
		
		A->left = right;
		A->right = left;
		
		return A;
	}
};
