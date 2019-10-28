#include <bits/stdc++.h>

using namespace std;

void insertEdge(int a, int b, vector<int> graph[])
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void isBipartiate(vector<int> grph[],bool* visit, int* color, int cur, bool* res)
{
    for(int u:grph[cur])
    {
        if(!visit[u])
        {
            visit[u]=true;
            color[u]=3-color[cur];
            isBipartiate(grph,visit,color,u,res);
            if(!(*res)) break;
        }
        else if(color[u]==color[cur])
        {
            *res=false;
            break;
        }
    }
}

int main()
{
    int n,m,count=0;
    cin>>n>>m;
    vector<int> graph[2*n];
    for(int i=0;i<m;i++)
    {
        int a,b,wght;
        cin>>a>>b>>wght;
        wght=wght%2;
        if(wght==1)
        {
            insertEdge(a,b,graph);
        }
        else
        {
            insertEdge(a,n,graph);
            insertEdge(n,b,graph);
            n++;count++;
        }
    }
    m+=count;
    if(m*4>n*n) cout<<"YES"<<endl;
    else
    {
        bool visit[n]={false},check=true;
        int color[n]={0};
        visit[0]=true;
        color[0]=1;
        isBipartiate(graph,visit,color,0,&check);
        for(int i=1;i<n&&!visit[i];i++)
        {
            isBipartiate(graph,visit,color,0,&check);
        }
        if(check) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
