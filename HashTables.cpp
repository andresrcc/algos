//chaining (closed addressing)
//Hash Node

//using linked list node

const int TABLE_SIZE = 128;

struct Node
{
	int key;
	int value;
	Node* next;

	Node(int key_param, int value_param)
	{
		key = key_param;
		value = value_param;
		next = nullptr;
	}
};


class HashMap
{
	vector<Node*> hash_table;
public:
	HashMap()
	{
		hash_table.assign(TABLE_SIZE, nullptr);
	}

	int hash_function(int key)
	{
		return key % TABLE_SIZE;
	}

	int search(int key)
	{
		Node* node = hash_table[hash_function(key)];

		if ( node == nullptr)
			return -1;

		Node* entry = node;
		while (entry != nullptr && entry->key != key)
		{
			entry = entry->next;
		}

		if (entry == nullptr)
			return -1;
		return entry->value;
	}

	void insert(int key, int value)
	{
		Node* node = hash_table[hash_function(key)];

		if ( node == nullptr)
		{
			node = new Node(key, value);
			return;
		}

		Node* entry = node;

		while (entry->next != nullptr)
			entry = entry->next;
		if (entry->key == key)
			entry->value = value;
		else
			entry->next = new Node(key, value);
	}

	void remove(int key)
	{
		Node* node = hash_table[hash_function(key)];
		if ( node == nullptr) return;

		Node* prev = nullptr;
		Node* entry = node;

		while(entry->next != nullptr && entry->key != key)
		{
			prev = entry;
			entry = entry->next;
		}
		if(entry->key == key)
		{
			if(prev == nullptr)
			{
				Node* next = entry->next;
				delete entry;
				node = next;
			}
			else
			{
				Node* next = entry->next;
				delete entry;
				prev->next = next;
			}
		}
	}

	~HashMap()
	{
		hash_table.clear();
	}

};
