//Hash Tables
//Hash Tables

//With Chaining

//PROCESS

vector<list<int>> t;
int n; // total number of items in the hash table Also n <= t.size();

bool add(int x){
	if(find(x) != null) return false; //if element exists dont add
	if(n+1 > t.size()) resize(); //how to resize vector or list????
	
	t[hash(x)].push_back(x);
	n++;
	return true;
}


int get(list<int> l; int i){
	return *advance(l.begin(), i);
}

int remove(int x){
	int j = hash(x); //find index
	for(int i = 0; i < t[j].size(); i++){
		int y = get(t[j],i);
		if(x == y){
			t[j].erase(i);
			n--;
			return y;
		}
	}
	return NULL;
}

int find(int x){
	int j = hash(x);
	for(int i = 0; i < t[j].size();i++)
		int node = get(t[j],i);
		if(x == node)
			return node;
	return NULL;
}
