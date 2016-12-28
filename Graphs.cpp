//Graphs

//Representation

//benefits?
class GraphNode {
	int d;
	vector<GraphNode*> Nodes;
}

//can be of GraphNode too
vector<vector<int>> AdjacencyList;

//can adjacency matrix
vector<vector<int>> AdjacencyMatrix;

//AdjacencyList with weights
vector<vector<pair<int,int>>> AdjacencyListWithWeights //where AdjacencyListWithWeights[i] = make_pair(distance,value)

//Traversal

  //maze runner
  
vector<int> X = {1,0,-1, 0};
vector<int> Y = {0,1, 0, -1};

  bool MR(int i, int j){
    if (found) return;
    if (visited[i][j]) return;
    if (OutOfRange(i,j))return;

    visited[i][j] = true;
    if (M[i][j] == 'exit'){
      found = true;
      return;
    }

    for (int k = 0; k < 4; k++)
        MR(i+X[k],j+Y[k]);
  }

  //dfs
  void dfs(Node* A){
    if (A->visited)return;
    A->visited = true;
    for (auto node: A->Nodes)
      dfs(node);
  }

  //pseudo dfs
  void dfs(Node *A){
   stack<Node*> S;
   Node * T;
   S.push(A);
   while(!S.empty()){
     T = S.top();
     S.pop();
     T->visited = true;
     for(auto n : T->Nodes)
      S.push(n);
   }
  }

  //bfs
  void bfs(Node* A){
    queue<Node*> Q;
    Q.push(A);
    Node* T;
    while(!Q.empty()){
      T = Q.front();
      Q.pop();
      T->visited = true;
      for (auto node : T->Nodes)
        Q.push();
    }
  }

  
  //Sorting
  
  
 //topological sort
  stack<Node*> TP(Node*A, Graph G){
    stack<Node*> S;
    for (auto V: G){
      S = dfsS(V,S);
    }

    return S;
  }

  stack<Node*> dfsS(Node*A, stack<Node*> S){
    if(A->visited) return S;
    A->visited =true;
    for(auto a: A->Nodes)
      S = dfsS(a,S);
    S.push(A);
    return S;
  }
  
  
//Optimized search

//implement > operator for your class Node
bool operator > (const Node& l, const Node& r){
  return l.d > r.d;
}

vector<Node*> dijkstra(Node* A){
  priority_queue<Node*, vector<Node*>, greater<Node*> P;

  P.push(A);
  Node* T;
  vector<Node*> path;

  while(!P.empty()){
    T = P.top(); P.pop();
    T->visited = true;
    path.push_back(T);
    for(auto node : T->Nodes){
      if(!node->visited)
        P.push(node);
    }
  }

  return path;
}


//representations for adjacency lists

int N; //number of vertices
vector<vector<int>> Graph; //the graph
vector<int> visited; //visited nodes

void dfs(int node){
  if(!visited[node]){
    visited[i] = true;
    for(auto vertex : Graph[node])
      dfs(vertex);
  }
}

void bfs(int node){
  queue<int> Q;
  int temp;
  Q.push(node);

  while(!Q.empty()){
    temp = Q.front(); Q.pop();
    if(!visited[node]){
      visited[vertex] = true;
      for (auto vertex : Graph[node])
        Q.push(vertex);
    }
  }
}

//why use?
bool check_graph_connected_dfs(){
  int start = 0;
  auto visited = vector<int>(N,false);
  dfs(start);
  return(find(V.begin(), V.end(), 0) == V.end());
}


//**************PROCESS this solution*****************//
//simply a DFS with a little trick at the end! cool cool!
// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
using namespace std;
 
// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);
 
public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);
 
    return 0;
}

//Count steps to destination
http://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/

//Dijkstra with a set (PROCESS)
struct edge { int to, length; };
        
int dijkstra(const vector< vector<edge> > &graph, int source, int target) {
  
  vector<int> min_distance( graph.size(), INT_MAX ); //initialize vector with "infinite value"
  min_distance[ source ] = 0;
  set< pair<int,int> > active_vertices;
  active_vertices.insert( {0,source} );
            
  while (!active_vertices.empty()) {
    
    int where = active_vertices.begin()->second;
    
    if (where == target) return min_distance[where];
    
    active_vertices.erase( active_vertices.begin() );

    for (auto ed : graph[where]){   
      if (min_distance[ed.to] > min_distance[where] + ed.length) {
	
	active_vertices.erase( { min_distance[ed.to], ed.to } );
	
        min_distance[ed.to] = min_distance[where] + ed.length;
	
        active_vertices.insert( { min_distance[ed.to], ed.to } );
      }
    }
  }
    return INT_MAX;
}

