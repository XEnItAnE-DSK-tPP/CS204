#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    string data;
    node*nxt;
};

int hIndex(string str)
{
    int res=0;
    for(int i=0;i<str.length();i++)
    {
        res+=((str[i]-'a')*(i+1))%256;
    }
    return res;
}

node hTable[256];
string dtemp;

void insertData(string str)
{
    int n=hIndex(str);
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=str;
    newNode->nxt=hTable[n].nxt;
    hTable[n].nxt=newNode;
}

void searchData(string str)
{
    int n=hIndex(str);
    node *tmp=hTable[n].nxt;
    while(tmp)
    {
        if(tmp->data==str)break;
        tmp=tmp->nxt;
    }
    if(!tmp)cout<<"Not ";

    cout<<"Found"<<endl;
}

void deleteData(string str)
{
    int n=hIndex(str);
    node*tmp=&(hTable[n]),*t2;
    while(tmp&&tmp->nxt)
    {
        if(tmp->nxt->data==str)break;
        tmp=tmp->nxt;
    }
    if(!tmp->nxt)cout<<"Not Found"<<endl;
    else
    {
        t2=tmp->nxt;
        tmp->nxt=t2->nxt;
        free(t2);
    }
}

void displayData()
{
    node*tmp;
    for(int i=0;i<256;i++)
    {
        tmp=hTable[i].nxt;
        if(tmp)
        {
            cout<<"Hash Index : "<<i<<endl;
            while(tmp)
            {
                cout<<"\t"<<tmp->data<<endl;
                tmp=tmp->nxt;
            }
        }
    }
}

int main()
{
    for(int i=0;i<256;i++)hTable[i].nxt=NULL;
    int op;
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                cin>>dtemp;
                insertData(dtemp);
                break;
            }
            case 2:
            {
                std::cin>>dtemp;
                searchData(dtemp);
                break;
            }
            case 3:
            {
                std::cin>>dtemp;
                deleteData(dtemp);
                break;
            }
            case 4:
            {
                displayData();
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
