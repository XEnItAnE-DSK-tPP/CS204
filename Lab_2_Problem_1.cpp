#include<bits/stdc++.h>
using namespace std;
struct LinkedListNode
{
    int coor_x, coor_y;
    struct LinkedListNode *nextNode;
};
typedef struct LinkedListNode LLN;

void AddAtFirst(LLN* head, int x, int y)
{
    LLN *newNode=(LLN *)malloc(sizeof(LLN));
    newNode->nextNode=head->nextNode;
    head->nextNode=newNode;
    newNode->coor_x=x;
    newNode->coor_y=y;
}

void DeleteFirst(LLN *head)
{
    LLN *tempnode;
    if(head->nextNode==NULL)
    {
        cout<<"-1";
    }
    else
    {
        tempnode=head->nextNode;
        head->nextNode=tempnode->nextNode;
        free(tempnode);
        cout<<"0";
    }
}

void DeteleX_Y(LLN *head, int x, int y)
{
    LLN *tempnode, *tbd;
    tempnode=head;
    if(!((tempnode->nextNode->coor_x==x&&tempnode->nextNode->coor_y==y)||(tempnode->nextNode==NULL)))
    {
        tempnode=tempnode->nextNode;
    }
    if(tempnode->nextNode==NULL)
    {
        cout<<"-1";
    }
    else
    {
        LLN  *temp2;
        temp2=tempnode->nextNode;
        tempnode->nextNode=temp2->nextNode;
        free(temp2);
        cout<<"0";
    }
}

void  SearchInDist(LLN *head, float  distance)
{
    LLN  *tempnode;
    tempnode=head;
    while(tempnode->nextNode!=NULL)
    {
        int x=tempnode->nextNode->coor_x,  y=tempnode->nextNode->coor_y;
        int disq=(x*x)+(y*y);
        float  dis=distance*distance;
        if(dis>=(float)disq)
        {
            cout<<"("<<x<<","<<y<<") ";
        }
        tempnode=tempnode->nextNode;
    }
}

int SearchX_Y(LLN *head,  int x,  int y)
{
    int count=0;
    LLN *tempnode;
    tempnode=head;
    while(tempnode->nextNode!=NULL)
    {
        if(tempnode->nextNode->coor_x==x&&tempnode->nextNode->coor_y==y)
        {
            count++;
        }
        tempnode=tempnode->nextNode;
    }
    return count;
}

int LengthOfList(LLN  *head)
{
    int  count=0;
    LLN *tempnode;
    tempnode=head;
    while(tempnode->nextNode!=NULL)
    {
        tempnode=tempnode->nextNode;
        count++;
    }
    return count;
}

int main()
{
    int test_cases;
    cin>>test_cases;
    LLN dummy;
    dummy.nextNode=NULL;
    for(int i=0;i<test_cases;i++)
    {
        cout<<"\n";
        int func;
        cin>>func;
        switch(func)
        {
            case 1:
            {
                int x, y;
                cin>>x>>y;
                AddAtFirst(&dummy, x, y);
                break;
            }
            case 2:
            {
                DeleteFirst(&dummy);
                break;
            }
            case 3:
            {
                int x, y;
                cin>>x>>y;
                DeteleX_Y(&dummy, x, y);
                break;
            }
            case 4:
            {
                float dist;
                cin>>dist;
                SearchInDist(&dummy, dist);
                break;
            }
            case  5:
            {
                int x,  y;
                cin>>x>>y;
                cout<<SearchX_Y(&dummy,  x,  y);
                break;
            }
            case 6:
            {
                cout<<LengthOfList(&dummy);
                break;
            }
        }
    }
    return 0;
}