#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

class Edge
{
    public:
    int src, dest;
    lli wght;
};

class subset
{
    public:
    int parent,rank;
};

class Graph
{
    public:
    int V,E;
    Edge* edges;

    Graph(int v,int e)
    {
        this->V=v;
        this->E=e;
        this->edges = new Edge[e*sizeof(Edge)];
    }
};

int compEdge(const void *a, const void *b)
{
    Edge* e1=(Edge*)a;
    Edge* e2=(Edge*)b;
    return e1->wght > e2->wght;
}

int find(subset subsets[], int i)  
{  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}

void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}

void cycle(Graph* graph)  
{  
    lli res=0;
    int V = graph->V;
    int e = 0;
    int i = 0;
    vector<Edge> mst;
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compEdge);  
    subset *subsets = new subset[( V * sizeof(subset) )];  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
    while (e < V - 1 && i < graph->E)  
    {  
        Edge next_edge = graph->edges[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
        if (x != y)  
        {  
            mst.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }
    for(int i=0;i<mst.size();i++)
    {
        cout<<(mst.at(i)).src<<" "<<(mst.at(i)).dest<<" "<<(mst.at(i)).wght<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    //declaration of graph
    Graph *graph;
    *graph=Graph(n,m);

    int x,y;
    lli w;
    
    //insertion of individual edge
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        graph->edges[i].src=x;
        graph->edges[i].dest=y;
        graph->edges[i].wght=w;
    }
    cycle(graph);
    return 0;
}
