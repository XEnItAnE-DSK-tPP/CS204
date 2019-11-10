#include<bits/stdc++.h>

using namespace std;

class graph
{
    public:
    int V,E;
    list<int> *adj;
    graph(int v, int e);
};

graph::graph(int v,int e)
{
    V=v;
    E=e;
    adj=new list<int>[V];
}

void insertEdge(graph* g,int x, int y)
{
    g->adj[x].push_back(y);
}

void BFS(graph* grph,int s) 
{ 
    bool *visited=new bool[grph->V]; 
    for(int i=0;i<grph->V;i++) 
        visited[i]=false; 
   
    list<int> queue; 
  
    visited[s]=true; 
    queue.push_back(s); 
  
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        s=queue.front(); 
        cout<<s<<" "; 
        queue.pop_front(); 
  
        for (i=grph->adj[s].begin();i!=grph->adj[s].end();++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i]=true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    graph newGraph=graph(n,m);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        insertEdge(&newGraph,x,y);
        //cout<<"A"<<endl;
    }
    BFS(&newGraph,2);
    return 0;
}
