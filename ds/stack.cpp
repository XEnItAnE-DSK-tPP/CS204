#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* nxt;
};

class Stack
{
    public:
        int height;
        Node list;
        Stack();
        void push(int);
        void pop();
        int size();
        int top();
        bool empty();
};

Stack::Stack()
{
    height=0;
    list.nxt=NULL;
}
void Stack::push(int x)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=x;
    newnode->nxt=list.nxt;
    list.nxt=newnode;
    height++;
}
void Stack::pop()
{
    Node* tmp=list.nxt;
    list.nxt=tmp->nxt;
    free(tmp);
    height--;
}
bool Stack::empty()
{
    return height==0;
}
int Stack::size()
{
    return height;
}
int Stack::top()
{
    return list.nxt->data;
}


int main()
{
    Stack newStack=Stack();
    int op;
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                int in;
                cin>>in;
                newStack.push(in);
                break;
            }
            case 2:
            {
                newStack.pop();
                break;
            }
            case 3:
            {
                cout<<newStack.top();
                break;
            }
            case 4:
            {
                cout<<newStack.size();
                break;
            }
            case 5:
            {
                if(newStack.empty)cout<<"Empty"<<endl;
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
