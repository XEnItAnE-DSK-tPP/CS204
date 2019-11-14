#include<iostream> 
#include<list> 

using namespace std; 

class Graph 
{ 
    int V;
    list<int> *adj; 
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void DFS(int v); 
    void DFSUtil(int v, bool visited[]);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i])
            DFSUtil(*i, visited); 
} 
void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    DFSUtil(v, visited); 
} 
  
int main() 
{
    int n,m;
    cin>>n>>m;
    Graph g=Graph(n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }

    int z;
    cin>>z;
    g.DFS(z);
    return 0; 
} 
