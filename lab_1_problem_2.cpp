#include<bits/stdc++.h>
using namespace std;
//declaring  function
string  findDifference(string str1,  string str2)
{
    //to make  sure that string 2 is larger
    if(str1.length()>str2.length())
    {
        swap(str1, str2);
    }
    if((str1.length()==str2.length())&&(str1[0]>str2[0]))
    {
        swap(str1,str2);
    }
    string str="";
    int n1=str1.length(),  n2=str2.length(), diff=n2-n1, borrow=0;
    //adding upto smaller string
    for(int i=n1-1;i>=0;i--)
    {
        int differ=((str2[i+diff]-'0')-((str1[i]-'0')-borrow));
        if(differ<0)
        {
            differ+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        str.push_back(differ + '0');
    }
    //adding rest of numbers
    for(int i=n2-n1-1;i>=0;i--)
    {
        int  differ=((str2[i]-'0')-borrow);
        if(differ<0)
        {
            differ+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        str.push_back(differ + '0');
    }
    
    //reversing resulting string
    reverse(str.begin(), str.end());
    return str;
}       
//main function
int main() 
{
    int test_cases;
    cin>>test_cases;
    cout<<"\n";
    string  str1[test_cases], str2[test_cases];
    for(int  i=0;i<test_cases;i++)
    {
        cin>>str1[i];
        cin>>str2[i];
        cout<<"\n";
    }
    for(int i=0;i<test_cases;i++)
    {
        cout <<findDifference(str1[i],str2[i])<<"\n";
    }
    return 0;
}