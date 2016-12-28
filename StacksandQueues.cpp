//linked lists
//basic linked list
//reverse
//find a loop

//stack
struct Node
{
    int d;
    struct Node *next;    
}*top;
 
class mystack
{
    public:
        Node *push(Node *, int);
        Node *pop(Node *);
        void traverse(Node *);
        mystack()
        {
            top = NULL;
        }               
};
 

Node* mystack::push(Node *top, int data)
{
	//create new element
    Node *T;
    T = new Node;
    T->d = data;
	
	//have it's next point to head
    T->next = top;
	
	//T becomes new top element of stack
    top = T;
    return top;
}
 
Node* mystack::pop(Node *top)
{
    if (top == NULL)
        return NULL;
	
	//store top in temp
	Node* T = top;
	
	//next become new top
    top = top->next;
	
	//delete old top
    delete(T);
	
	//return new top? (should be optional)
    return top;
}
 

void mystack::traverse(Node *top)
{       

	if (top == NULL)
		return;
	
    Node *T = top;
	
	while (ptr != NULL)
		ptr = ptr->next;
	//add a statement to print if want to.
}


//queue
//full queue implementation
