#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* nxt;
};

class Queue
{
    private:
    int length;
    Node list,*rear;
    public:
    Queue();
    void push(int);
    void pop();
    int front();
    int size();
    bool empty();
};

Queue::Queue()
{
    length=0;
    list.nxt=NULL;
    rear=&list;
}
void Queue::push(int x)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->nxt=NULL;
    rear->nxt=newNode;
    rear=rear->nxt;
    length++; 
}
void Queue::pop()
{
    Node *tmp=list.nxt;
    if(tmp)
    {
        list.nxt=tmp->nxt;
        free(tmp);
        length--;
    }
    else return;
}
int Queue::size()
{
    return length;
}
int Queue::front()
{
    if(list.nxt)
    {
        return list.nxt->data;
    }
    else return INT_MIN;
}
bool Queue::empty()
{
    return length==0;
}


int main()
{
    Queue newQueue=Queue();
    int op;
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                int x;
                cin>>x;
                newQueue.push(x);
                break;
            }
            case 2:
            {
                newQueue.pop();
                break;
            }
            case 3:
            {
                cout<<newQueue.front()<<endl;
                break;
            }
            case 4:
            {
                cout<<newQueue.size()<<endl;
                break;
            }
            case 5:
            {
                if(newQueue.empty())cout<<"Empty"<<endl;
                else cout<<"Not Empty"<<endl;
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
