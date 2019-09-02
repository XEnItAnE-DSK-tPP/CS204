#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct usrData
{
    int usrID, balance;
};
typedef struct usrData usrNode;

void update_record(vector<usrNode*> *list, int id, int recharge, int maxSize)
{
    int i;
    usrNode* temp;
    for(i=0;i<(*list).size();i++)
    {
        temp=(usrNode*)(*list).at(i);
        if(temp->usrID==id)
        {
            temp->balance+=recharge;
            break;
        }
        if(temp->usrID>id)
        {
            break;
        }
    }
    if((*list).size()<maxSize)
    {
        if(i==(*list).size()||temp->usrID>id)
        {
            usrNode* newNode=(usrNode*)malloc(sizeof(usrNode));
            newNode->balance=recharge;
            newNode->usrID=id;
            (*list).insert((*list).begin()+i,newNode);
        }
    }
}

void print_max_bal(vector<usrNode*> *list)
{
    usrNode* max;
    if((*list).empty())
    {
        cout<<"No data available.\n";
        return;
    }
    else
    {
        max=(usrNode*)(*list).at(0);
        for(int i=0;i<(*list).size();i++)
        {
            usrNode *temp;
            temp=(usrNode*)(*list).at(i);
            if(temp->balance>max->balance)
            {
                max=temp;
            }
        }
        cout<<max->usrID<<"\n";
    }
}

int main()
{
    int number_of_users,number_of_querries;
    cin>>number_of_users>>number_of_querries;
    vector<usrNode*> companyRecord;
    for(int i=0;i<number_of_querries;i++)
    {
        int operation;
        cin>>operation;
        switch(operation)
        {
            case 1:
            {
                int usrId,recharge;
                cin>>usrId>>recharge;
                update_record(&companyRecord,usrId,recharge,number_of_users);
                break;
            }
            case 2:
            {
                print_max_bal(&companyRecord);
                break;
            }
        }
    }
    return 0;
}