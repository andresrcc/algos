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
class MyStack
{
	Node* top;
public:

	MyStack()
	{
		top = nullptr;
	}

	void push(int data)
	{

		Node* T;
		T = new Node(data);
		T->next = top;
		top = T;
	}

	void pop()
	{
		if (top == nullptr) return;

		Node* T = top;

		top = top->next;

		delete(T);
	}

	Node* peek()
	{
		return top;
	}
};
 
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
