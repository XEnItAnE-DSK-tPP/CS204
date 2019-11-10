#include<bits/stdc++.h>

using namespace std;

class leaf
{
    public:
    int data;
    leaf *left,*right;
};

void storeBSTNodes(vector<leaf*>*list,leaf*root)
{
    if(root)
    {
        storeBSTNodes(list,root->left);
        (*list).push_back(root);
        storeBSTNodes(list,root->right);
    }
}

leaf* buildTree(vector<leaf*>*list,int strt,int end)
{
    if(strt>end) return NULL;

    int mid=(strt+end)/2;
    leaf* root=(*list)[mid];
    
    root->left=buildTree(list,strt,mid-1);
    root->right=buildTree(list,mid+1,end);
    
    return root;
}

leaf* build(leaf* root)
{
    vector<leaf*> list;
    storeBSTNodes(&list,root);
    int n=list.size();
    return buildTree(&list,0,n-1);
}

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
                root=build(root);
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
                root=build(root);
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
