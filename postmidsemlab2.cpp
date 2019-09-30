#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

typedef long long int lli;

struct point
{
    int x, y;
    bool operator<(point p)
    {
        return (x<p.x)||(x==p.x&&y<p.y);
    }
};

void insert(vector<point> *list, int x, int y);
lli area(point p, point top, point secTop);
point scondTop(stack<point> stck);
vector<point> hull(vector<point> *list);
void printPointList(vector<point> list);

int main()
{
    int n;
    cin>>n;
    vector<point> points;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        insert(&points,x,y);
    }
    cout<<endl;
    sort(points.begin(),points.end());
    vector<point> ans=hull(&points);
    printPointList(ans);
    return 0;
}

void insert(vector<point> *list, int x, int y)
{
    point* newPoint=(point*)malloc(sizeof(point));
    newPoint->x=x;
    newPoint->y=y;
    (*list).push_back(*newPoint);
}

lli area(point p, point top, point secTop)
{
    return (lli)(((top.x-p.x)*(secTop.y-top.y))-((top.y-p.y)*(secTop.x-top.x)));
}

point secondTop(stack<point> stck)
{
    point tmp=(point)stck.top(), p;
    stck.pop();
    p=stck.top();
    stck.push(tmp);
    return p;
}

vector<point> hull(vector<point> *list)
{
    int n=(*list).size();
    stack<point> hull;
    vector<point> fHull;
    hull.push((point)(*list).at(0));
    hull.push((point)(*list).at(1));
    for(int i=2;i<n;i++)
    {
        while(hull.size()>1&&area((point)(*list).at(i),(point)hull.top(),secondTop(hull))<=0) hull.pop();
        hull.push((point)(*list).at(i));
    }
    hull.pop();
    while(!hull.empty())
    {
        fHull.insert(fHull.begin(),(point)hull.top());
        hull.pop();
    }
    int n2=fHull.size();
    hull.push((point)(*list).at(n-1));
    hull.push((point)(*list).at(n-2));
    for(int i=n-3;i>=0;i--)
    {
        while(hull.size()>1&&area((point)(*list).at(i),(point)hull.top(),secondTop(hull))<=0) hull.pop();
        hull.push((point)(*list).at(i));
    }
    hull.pop();
    while(!hull.empty())
    {
        fHull.insert(fHull.begin()+n2,(point)hull.top());
        hull.pop();
    }
    return fHull;
}

void printPointList(vector<point> list)
{
    int n=list.size();
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<((point)list.at(i)).x<<" "<<((point)list.at(i)).y<<endl;
    }
}