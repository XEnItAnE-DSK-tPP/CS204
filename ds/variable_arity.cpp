#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *child,*right;
};

Node* newNode(int num)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->child=newNode->right=NULL;
}



Node* insert(Node* root,int data)
{
    if(!root)return newNode(data);

    if(data<root->data)root->child=insert(root->child,data);
    else
    {
        Node* tmp=root->right;
        if(tmp)
        {
            while(!tmp->right)
            {
                tmp=tmp->right;
            }
            tmp->right=insert(tmp->right,data);
        }
        else{root->right=insert(root->right,data);}
    }
    
    return root;
}

bool search(Node* root,int data)
{
    if(!root)return false;

    if(root->data==data) return true;

    if(root->data>data)
        return search(root->child,data);
    else
    {
        Node* tmp=root->right;
        while(!tmp)
        {
            if(tmp->data==data)return true;
        }
    }
    return false;
}

void print(Node* root)
{
    if(!root)
    {
        print(root->child);
        cout<<root->data<<endl;
        Node*tmp=root->right;
        while(!tmp)
        {
            cout<<tmp->data<<endl;
            tmp=tmp->right;
        }
    }
}

int main()
{
    Node* head;
    int op;
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                int x;
                head=insert(head,x);
                break;
            }
            case 2:
            {
                int x;
                cout<<search(head,x)<<endl;
                break;
            }
            case 3:
            {
                print(head);
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}
