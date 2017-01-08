//chaining (closed addressing)
//Hash Node

//using linked list node

const int kTableSize = 128;

struct Node
{
	int key;
	int value;
	Node* next;

	Node(int k, int v)
	{
		key = k;
		value = v;
		next = nullptr;
	}
};

//chaining
struct Entry{
	int key;
	int value;
	Entry* next;
	
	Entry(int k, int v){
		key = k;
		value = v;
		next = nullptr;
	}
	
};

class HashMapChaining
{
	vector<Entry*> hash_table_;
public:
	HashMapChaining()
	{
		hash_table_.assign(kTableSize, nullptr);
	}

	int HashFunction(int key)
	{
		return key % kTableSize;
	}

	int Search(int key)
	{
		Node* node = hash_table_[HashFunction(key)];

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

	void Insert(int key, int value){
		int hash = HashFunction(key);
		
		if(hash_table_[hash] == nullptr){
			hash_table_[hash] = new Entry(key,value);
			return;
		}
		
		Entry* entry = hash_table_[hash];
		
		while(entry->next != nullptr)
			entry = entry->next;
		
		if(entry->key == key)
			entry->value = value;
		else
			entry->next = new Entry(key, value);
	}

	void Remove(int key)
	{
		Node* node = hash_table_[HashFunction(key)];
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
		hash_table_.clear();
	}

};

//Linear Probing

struct Entry
{
	int key;
	int value;

	Entry(int k, int v)
	{
		key = k;
		value = v;
	}
};


class HashMapProbing
{
	vector<Entry*> hash_table_;
public:
	HashMapProbing()
	{
		hash_table_.assign(kTableSize, nullptr);
	}


	int HashFunction(int key)
	{
		return key % kTableSize;
	}


	void Insert(int key, int value)
	{
		int hash = HashFunction(key);

		while (hash_table_[hash] != nullptr && hash_table_[hash]->key != key)
		{
			hash = HashFunction(hash + 1);
		}

		if (hash_table_[hash] != nullptr)
			delete hash_table_[hash];

		hash_table_[hash] = new Entry(key, value);
	}

	int Search(int key)
	{
		int hash = HashFunction(key);
		while (hash_table_[hash] != nullptr && hash_table_[hash]->key != key)
			hash = HashFunction(hash + 1);

		return hash_table_[hash] == nullptr ? -1 : hash_table_[hash]->value;
	}


	void Remove(int key)
	{
		int hash = HashFunction(key);

		while (hash_table_[hash] != nullptr && hash_table_[hash]->key == key)
			hash = HashFunction(hash + 1);

		if (hash_table_[hash] == nullptr) return;

		delete hash_table_[hash];
	}

	~HashMapProbing()
	{
		for(auto e : hash_table_)
			delete e;
	}
};

