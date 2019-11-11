#include<bits/stdc++.h>

using namespace std;

class TrieNode
{
    public:
    bool end;
    TrieNode* nxt[52];
    TrieNode()
    {
        for(int i=0;i<52;i++)nxt[i]=NULL;
        end=false;
    }
};

TrieNode dictionary;



int ind(char a)
{
    if('z'-a>=0)return a-'a';
    else return a-'A'+26;
}

TrieNode* insNode()
{
    TrieNode* newNode=(TrieNode*)malloc(sizeof(TrieNode));
    for(int i=0;i<52;i++)newNode->nxt[i]=NULL;
    return newNode;
}

bool chk(string str)
{
    string strTmp=str;
    reverse(strTmp.begin(),strTmp.end());
    if(str==strTmp) return false;
    else
    {
        TrieNode* tmp=&dictionary;
        for(int i=0;i<strTmp.length();i++)
        {
            int n=ind(strTmp[i]);
            if(tmp->nxt[n])tmp=tmp->nxt[n];
        }
        if(tmp->end) return true;
        else
        {
            tmp=&dictionary;
            for(int i=0;i<str.length();i++)
            {
                int n=ind(str[i]);
                tmp->nxt[n]=insNode();
                tmp=tmp->nxt[n];
            }
            tmp->end=true;
        }
        return false;    
    }
    
}

int main()
{
    for(int i=0;i<52;i++)dictionary.nxt[i]=NULL;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(chk(str))
        {
            cout<<"YES"<<endl;
            break;
        }
    }
    if(i==n)cout<<"NO"<<endl;
}