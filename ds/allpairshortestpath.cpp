#include <bits/stdc++.h> 
using namespace std; 
  
#define INF 99999  
  
void printSolution(int **dist,int V);  
  
void floydWarshall (int **graph,int V)  
{  
    int i, j, k;  
    int **dist=new int*[V];
    for(int i=0;i<V;i++)dist[i]=new int[V];
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    printSolution(dist,V);  
}  
void printSolution(int **dist,int V)  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}  
  
int main()  
{
    int V,E;
    cin>>V>>E; 
    int **graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
    }
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(i==j)graph[i][j]=0;
            else graph[i][j]=INF;
    while(E--)
    {
        int x,y,wght;
        cin>>x>>y>>wght;
        graph[x][y]=wght;
    }
    floydWarshall(graph,V);  
    return 0;
}
