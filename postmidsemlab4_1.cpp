#include<bits/stdc++.h>

using namespace std;

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

void insertEdge(vector<int> edge[],int a, int b)
{
    edge[a].push_back(b);
    edge[b].push_back(a);
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(4*m>n*n) cout<<"NO"<<endl;
    else
    {
        vector<int> edge[n];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            insertEdge(edge,a,b);
        }
        bool visited[n]={false},check=true;
        int color[n]={0};
        visited[0]=true;
        color[0]=1;
        isBipartiate(edge,visited,color,0,&check);
        for(int i=1;i<n&&!visited[i];i++)
        {
            color[i]=1;
            isBipartiate(edge,visited,color,i,&check);
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
