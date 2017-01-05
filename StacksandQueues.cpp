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
	int count;
public:

	MyStack()
	{
		top = nullptr;
		count = 0;
	}
	

		

	void push(int data)
	{
		Node* T = new Node(data);
		
		T->next = top;
		top = T;
		count++;
	}

	void pop()
	{
		if (top == nullptr) return;

		Node* T = top;
		top = top->next;

		delete T;
		count--;
	}

	int peek()
	{
		if (top == nullptr) return - 1;
		return top->d;
	}
	
	~MyStack(){
		Node* T = top;
		
		for(int i = 0; i < count; i++)
			pop();
	}
};
 
//queue
//Basic queue
class Queue{
private:
    Node* rear;
    Node* front;
public:

    Queue(){
        rear = nullptr;
        front = nullptr;
    }
    void push(int d){
        Node* T = new Node(d);

        if(front == nullptr)
            front = T;
        else
            rear->next = T;

        rear = T;
    }

    void pop(){
        if(front == nullptr) return;

        Node* T = front;
        front = front->next;
        delete T;
    }
    int peek(){
	if(front == nullptr) return -1;
        return front->d;
    };
};
