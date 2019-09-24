#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void insertSort(double arr[], int n)
{
    int i, j;
    double tmp;
    for(int i=1;i<n;i++)
    {
        tmp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]<tmp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
}
double findMedian(double arr[], int n)
{
    insertSort(arr,n);
    return arr[n/2];
}
void swap(double* a,double *b)
{
    double c=*a;
    *a=*b;
    *b=c;
}
int partition(double arr[], int l, int u, double x)
{
    int i;
    for(i=l;i<u;i++) if(arr[i]==x) break;
    swap(&(arr[i]),&(arr[u]));
    i=l;
    for(int j=l;j<u;j++)
    {
        if(arr[j]<=x)
        {
            swap(&(arr[i]),&(arr[j]));
            i++;
        }
    }
    swap(&(arr[i]),&(arr[u]));
    return i;
}
double kthSmallest(double arr[], int l, int u, int k)
{
    if(k>0&&k<u-l+1)
    {
        int n=u-l+1;
        int i;
        double median[(n+4)/5];
        for(i=0;i<n/5;i++)
        {
            median[i]=findMedian(arr+l+i*5,5);
        }
        if(i*5<n)
        {
            median[i]= findMedian(arr+l+i*5,n%5);
            i++;
        }
        double medofmed=(i==1)?median[i-1]:kthSmallest(median,0,i-1,i/2);
        int pos=partition(arr,l,u,medofmed);
        if((pos-l)==(k-1)) return arr[pos];
        else if(pos-l>k-1) return kthSmallest(arr,l,pos-1,k);
        else    return kthSmallest(arr,pos+1,u,k-pos+l-1);
    }
}
int main()
{
    int tC;
    cin>>tC;
    while(tC--)
    {
        int nPoints;
        cin>>nPoints;
        double points[nPoints], a, b;
        for(int i=0;i<nPoints;i++)
        {
            cin>>a>>b;
            points[i]=sqrt((a*a)+(b*b));
        }
        int pos=(nPoints+1)/2;
        cout<<kthSmallest(points,0,nPoints-1,pos)<<endl;
    }
    return 0;
}
