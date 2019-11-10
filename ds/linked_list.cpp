#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* nxt;
};

class LnkLst
{
    private:
    Node head,*rear;
    public:
    LnkLst()
    {
        head.nxt=NULL;
        rear=&head;
    }
    void push_back(int x)
    {
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->data=x;
        newNode->nxt=NULL;
        rear->nxt=newNode;
        rear=rear->nxt;
    }
    bool search(int x)
    {
        Node* tmp=head.nxt;
        while(tmp)
        {
            if(tmp->data==x) return true;
            tmp=tmp->nxt;
        }
        return false;
    }
    void push_front(int x)
    {
        if(!head.nxt) this->push_back(x);
        else
        {
            Node* newNode=(Node*)malloc(sizeof(Node));
            newNode->data=x;
            newNode->nxt=head.nxt;
            head.nxt=newNode;
        }
    }
    void remove(int x)
    {
        Node* tmp=&head,*t2;
        while(tmp&&tmp->nxt)
        {
            if(tmp->nxt->data==x) break;
            tmp=tmp->nxt;
        }
        if(!tmp) return;
        else if(tmp->nxt==rear)
        {
            rear=tmp;
        }
        else
        {
            t2=tmp;
            t2->nxt=tmp->nxt->nxt;            
        }
        free(tmp->nxt);
    }
    void print()
    {
        Node*tmp=head.nxt;
        while(tmp)
        {
            cout<<tmp->data<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    int op;
    LnkLst lList=LnkLst();
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                cin>>op;
                lList.push_back(op);
                break;
            }
            case 2:
            {
                cin>>op;
                lList.push_front(op);
                break;
            }
            case 3:
            {
                cin>>op;
                if(lList.search(op)) cout<<"Found"<<endl;
                else cout<<"Not Found";
                break;
            }
            case 4:
            {
                cin>>op;
                lList.remove(op);
                break;
            }
            case 5:
            {
                lList.print();
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}
