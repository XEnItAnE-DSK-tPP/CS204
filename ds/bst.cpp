#include<bits/stdc++.h>

using namespace std;

class leaf
{
    public:
    int data;
    leaf *left,*right;
};

leaf *minNode(leaf*node)
{
    leaf* tmp=node;
    while(tmp&&tmp->left)tmp=tmp->left;
    return tmp;
}

leaf* newLeaf(int key)
{
    leaf*nl=(leaf*)malloc(sizeof(leaf));
    nl->data=key;
    nl->left=nl->right=NULL;
    return nl;
}

leaf* insertData(leaf* root,int num)
{
    if(!root)return newLeaf(num);

    if(num<root->data)root->left=insertData(root->left,num);
    if(num>root->data)root->right=insertData(root->right,num);

    return root;
}

leaf* searchData(leaf*root,int num)
{
    if(!root)return root;

    if(num<root->data)return searchData(root->left,num);
    if(num>root->data)return searchData(root->right,num);

    return root;
}

leaf* deleteData(leaf* root,int key)
{
    if(!root)
    {
        cout<<"Not Found"<<endl;
        return root;
    }

    if(root->data>key) root->left=deleteData(root->left,key);
    else if(root->data<key) root->right=deleteData(root->right,key);

    else
    {
        if(!(root->left))
        {
            leaf* tmp=root->right;
            free(root);
            return tmp;
        }
        else if(!(root->right))
        {
            leaf* tmp=root->left;
            free(root);
            return tmp;
        }

        leaf* x=minNode(root->right);
        root->data=x->data;
        root->right=deleteData(root->right,x->data);
    }
    return root;
}

void inOrder(leaf*root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<endl;
        inOrder(root->right);
    }
}

int main()
{
    int op;
    leaf* root=NULL;
    while(cin>>op)
    {
        switch(op)
        {
            case 1:
            {
                int data;
                cin>>data;
                root=insertData(root,data);
                break;
            }
            case 2:
            {
                int data;
                cin>>data;
                if(searchData(root,data))cout<<"found";
                else cout<<"Not found";
                cout<<endl;
                break;
            }
            case 3:
            {
                int data;
                cin>>data;
                deleteData(root,data);
                break;
            }
            case 4:
            {
                inOrder(root);
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
