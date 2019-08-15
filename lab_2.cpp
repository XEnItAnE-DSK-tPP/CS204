#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

struct CoordinateList
{
    int coor_x, coor_y;
    struct CoordinateList *nextNode;
};

typedef struct CoordinateList LLN;

void list_length(LLN *list, string *str)
{
    LLN *tempNode;
    tempNode=list;
    int count=0;
    while(tempNode->nextNode!=NULL)
    {
        count++;
        tempNode=tempNode->nextNode;
    }
    *str+=std::to_string(count);
    *str+="\n";
    return;
}

void search_a_b(LLN *list, int x, int y, string *str)
{
    LLN *tempNode;
    tempNode=list->nextNode;
    while(tempNode->nextNode!=NULL)
    {
        if(tempNode->coor_x==x&&tempNode->coor_y==y)
        {
            *str+="True\n";
            return;
        }
        tempNode=tempNode->nextNode;
    }
    *str+="False\n";
    return;
}

void search_dist(LLN *list, float distance, string *str)
{
    LLN* tempNode;
    tempNode=list;
    float dissq=distance*distance;
    int count=0;
    while(tempNode->nextNode!=NULL)
    {
        float x=(float)(tempNode->nextNode->coor_x), y=(float)(tempNode->nextNode->coor_y);
        float tempdissq=(x*x)+(y*y);
        if(dissq-tempdissq>=0)
        {
            count++;
        }
        tempNode=tempNode->nextNode;
    }
    *str+=std::to_string(count);
    *str+="\n";
    return;
}

void delete_a_b(LLN *list, int x, int y, string *str)
{
    LLN* tempNode;
    tempNode=list;
    while(tempNode->nextNode!=NULL)
    {
        if(tempNode->nextNode->coor_x==x&&tempNode->nextNode->coor_y==y)
        {
            LLN* tbd=tempNode->nextNode;
            tempNode->nextNode=tbd->nextNode;
            free(tbd);
            return;
        }
        tempNode=tempNode->nextNode;
    }
    *str+="-1\n";
    return;
}

void delete_first(LLN *list, string *str)
{
    LLN* tempNode;
    if(list->nextNode!=NULL)
    {
        tempNode=list->nextNode;
        list->nextNode=tempNode->nextNode;
        free(tempNode);
        return;
    }
    else
    {
        *str+="-1\n";
        return;
    }
}

void add_at_first(LLN *list, int x, int y)
{
    LLN* newNode=(LLN*)malloc(sizeof(LLN));
    newNode->coor_x=x;
    newNode->coor_y=y;
    newNode->nextNode=list->nextNode;
    list->nextNode=newNode;
}

int main()
{
    LLN coordinate_list;
    coordinate_list.nextNode=NULL;
    int test_cases;
    cin>>test_cases;
    string final_result="";
    for(int i=0;i<test_cases;i++)
    {
        int func_type;
        cin>>func_type;
        switch(func_type)
        {
            case 1:
            {
                int a, b;
                cin>>a>>b;
                add_at_first(&coordinate_list, a, b);
                break;
            }
            case 2:
            {
                delete_first(&coordinate_list, &final_result);
                break;
            }
            case 3:
            {
                int a, b;
                cin>>a>>b;
                delete_a_b(&coordinate_list, a, b, &final_result);
                break;
            }
            case 4:
            {
                float dist;
                cin>>dist;
                search_dist(&coordinate_list, dist, &final_result);
                break;
            }
            case 5:
            {
                int a, b;
                cin>>a>>b;
                search_a_b(&coordinate_list, a, b, &final_result);
                break;
            }
            case 6:
            {
                list_length(&coordinate_list, &final_result);
                break;
            }
        }
    }
    cout<<"\n"<<final_result;
    return 0;
}
