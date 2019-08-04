#include<bits/stdc++.h>
using namespace std;
//declaring  function
int isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return 1; 
    if (n1 > n2) 
        return 0; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return 1; 
        else if (str1[i] > str2[i]) 
            return 0; 
    } 
    return 1; 
}
string  findDifference(string str1,  string str2)
{
    string stemp1,  stemp2;
    int k;
    for(k=0;k<str1.length();k++)
    {
        if(str1[i]!=0)
        {
            break;
        }
    }
    for(;k<str1.length();k++)
    {
        stemp1.push_back(str1[i]);
    }
    
    for(k=0;k<str2.length();k++)
    {
        if(str2[i]!=0)
        {
            break;
        }
    }
    for(;k<str2.length();k++)
    {
        stemp2.push_back(str2[i]);
    }
    //to make  sure that string 2 is larger
    if(isSmaller(stemp1,stemp2)==0)
    {
        swap(str1, str2);
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
