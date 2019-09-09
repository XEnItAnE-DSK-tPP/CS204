#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

struct numberList
{
    string data;
    struct numberList *next;
};
typedef struct numberList numNode;

bool isNum1Big(string str1, string str2)
{
    int n=str1.length();
    for(int i=0;i<n;i++)
    {
        if(str1[i]>str2[i])
        {
            return true;
        }
        if(str1[i]<str2[i])
        {
            return false;
        }
    }
    return false;
}

void push_num_sublist(string data, numNode* listHead)
{
    numNode* temp;
    temp=listHead;
    while(temp->next!=NULL)
    {
        string num1=data,num2=temp->next->data;
        num1+=num2;
        num2+=data;
        if(isNum1Big(num1,num2))
        {
            break;
        }
        temp=temp->next;
    }
    numNode* newNode=(numNode*)malloc(sizeof(numNode));
    newNode->data=data;
    newNode->next=temp->next;
    temp->next=newNode;
}

void printList(numNode* listHead)
{
    numNode* temp;
    for(int i=9;i>=0;i--)
    {
        temp=listHead+i;
        while(temp->next!=NULL)
        {
            cout<<temp->next->data;
            temp=temp->next;
        }
    }
}

int main()
{
    int tCases;
    cin>>tCases;
    while(tCases--)
    {
        int numQty;
        cin>>numQty;
        numNode subList[10];
        for(int i=0;i<10;i++)
        {
            subList[i].next=NULL;
        }
        while(numQty--)
        {
            string num;
            cin>>num;
            int n=num[0]-'0';
            push_num_sublist(num,&subList[n]);
        }
        printList(subList);
        cout<<endl;
    }
    return 0;
}