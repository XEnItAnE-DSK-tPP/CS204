#include<bits/stdc++.h>

using namespace std;

struct edge
{
    int v1,v2;
};

typedef vector<pair<edge,int>> Graph;

void insertEdge(int a, int b, int wght, Graph* grph)
{
    edge* newEdge=(edge*)malloc(sizeof(edge));
    newEdge->v1=a;
    newEdge->v2=b;
    (*grph).push_back(make_pair(*newEdge,wght));
}

void insertEdge2(int a, int b, vector<int> edges[])
{
    edges[a].push_back(b);
    edges[b].push_back(a);
}

void isBipartiate(vector<int> edges[], bool* visit, int* color,int currentVer,bool*result)
{
    for(int u:edges[currentVer])
    {
        if(!visit[u])
        {
            visit[u]=true;
            color[u]=3-color[currentVer];
            isBipartiate(edges,visit,color,u,result);
            if(!(*result)) break;
        }
        else if(color[u]==color[currentVer])
        {
            *result=false;
            break;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    Graph graph;
    for(int i=0;i<m;i++)
    {
        int a,b,wght;
        cin>>a>>b>>wght;
        wght=wght%2;
        if(wght==1) insertEdge(a,b,wght,&graph);
        else
        {
            insertEdge(a,n,1,&graph);
            insertEdge(n,b,1,&graph);
            n++;
        }
    }
    vector<int> edges[n];
    bool visit[n]={false},check=true;
    int color[n]={0};
    visit[0]=true;
    color[0]=1;
    for(pair<edge,int> u : graph)
    {
        insertEdge2(u.first.v1,u.first.v2,edges);
    }
    isBipartiate(edges,visit,color,0,&check);
        for(int i=1;i<n&&!visit[i];i++)
        {
            color[i]=1;
            isBipartiate(edges,visit,color,i,&check);
        }
        if(!check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}