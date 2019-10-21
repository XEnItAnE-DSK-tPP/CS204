#include <bits/stdc++.h>

using namespace std;
int COUNT;

bool isVal(int m, int n,int x, int y, bool* grid, bool* vis)
{
    if(x<m&&y<n&&x>=0&&y>=0)
    {
        if(!*((vis+x*n)+y)&& *((grid+x*n)+y))
            return true;
        else return false;
    }
    return false;
}

void bfs(int m, int n, int i, int j, bool* grid, bool* vis)
{
    if(!(*((grid+i*n)+j))||*((vis+i*n)+j))
        return;
    
    *((vis+i*n)+j)=true;
    COUNT++;
    int xMove[]={0,0,1,-1};
    int yMove[]={1,-1,0,0};
    for(int u=0;u<4;u++)
    {
        if(isVal(m,n,i+yMove[u],j+xMove[u],grid,vis))
        {
            bfs(m,n,i+yMove[u],j+xMove[u],grid,vis);
        }
    }
}

void largestBlackBlock(int m, int n, bool* grid,bool* vis)
{
    int max=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            COUNT=0;
            if(j+1<n)
            {
                bfs(m,n,i,j,grid,vis);
            }
            if(COUNT>=max)
            {
                max=COUNT;
            }
        }
    }
    cout<<max<<endl;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int qty;
    cin>>qty;
    bool grid[m][n]={false};
    bool vis[m][n];
    for(int i=0;i<qty;i++)
    {
        int x,y;
        cin>>x>>y;
        grid[x-1][y-1]=true;
    }
    largestBlackBlock(m,n,(bool*)grid,(bool*)vis);
    return 0;
}