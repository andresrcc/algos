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


class HashMapChaining
{
	vector<Node*> hash_table;
public:
	HashMapChaining()
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

	~HashMapChaining()
	{
		hash_table.clear();
	}

};

//Linear Probing

struct Entry
{
	int key;
	int value;

	Entry(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
};


class HashMapProbing
{
	vector<Entry*> hash_table;
public:
	HashMapProbing()
	{
		hash_table.assign(TABLE_SIZE, nullptr);
	}


	int hash_function(int key)
	{
		return key % TABLE_SIZE;
	}


	void insert(int key, int value)
	{
		int hash = hash_function(key);

		while (hash_table[hash] != nullptr && hash_table[hash]->key != key)
		{
			hash = hash_function(hash + 1);
		}

		if (hash_table[hash] != nullptr)
			delete hash_table[hash];

		hash_table[hash] = new Entry(key, value);
	}

	int search(int key)
	{
		int hash = hash_function(key);
		while (hash_table[hash] != nullptr && hash_table[hash]->key != key)
		{
			hash = hash_function(hash + 1);
		}

		return hash_table[hash] == nullptr ? -1 : hash_table[hash]->value;
	}


	void remove(int key)
	{
		int hash = hash_function(key);

		while (hash_table[hash] != nullptr)
		{
			if (hash_table[hash]->key == key)
				break;

			hash = hash_function(hash + 1);
		}

		if (hash_table[hash] == nullptr) return;

		delete hash_table[hash];
	}

	~HashMapProbing()
	{
		hash_table.clear();
	}
};

