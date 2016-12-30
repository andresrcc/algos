//linked lists
//basic linked list
//reverse
//find a loop

//// Linked list node
struct Node
{
    int d;
    Node* next;

    Node(int data)
    {
        d = data;
        next = nullptr;
    }
};


void traverse_linked_list(Node* head)
{
    if (head == nullptr) return;

    Node* T = head;

    while (T != nullptr)
    {
        cout << T->d << " " << endl;
        T = T->next;
    }
}


//stack
class mystack
{
    private:
        Node* top;
    public:
        Node* push(Node*, int);
        Node* pop(Node*);
        void traverse(Node*);
        
        mystack()
        {
            top = NULL;
        }               
};
 

Node* mystack::push(Node* top, int data)
{
	//create new element
    Node* T;
    T = new Node;
    T->d = data;
	
	//have it's next point to head
    T->next = top;
	
	//T becomes new top element of stack
    top = T;
    return top;
}
 
Node* mystack::pop(Node* top)
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
 
//queue
//Basic queue
class Queue{
    private:
        Node* rear;
        Node* front;
    public:
        Queue();
        void push();
        void pop();
        void peek();
};

Queue::Queue(){
    rear = NULL;
    front = NULL;
}

void Queue::push(int data){
    Node* T = new Node(d);
        
    if(front == NULL)
        front = T;
    else
	rear->next = T;
        
    rear = T;
}

void Queue::pop(){
    if(front == NULL) return;
        
    Node* T = front;
    front = front->next;
    delete T;
}
