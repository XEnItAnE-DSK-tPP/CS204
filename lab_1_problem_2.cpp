#include<bits/stdc++.h> 
using namespace std; 
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n1 > n2) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
  
string findDifference(string str1, string str2) 
{ 
    string strt1, strt2;
    int k;
    for(k=0;k<str1.length();k++)
        if(str1[k]!='0')
            break;
    for(int i=k;i<str1.length();i++)
        strt1.push_back(str1[i]);
    for(k=0;k<str2.length();k++)
        if(str2[k]!='0')
            break;
    for(int i=k;i<str2.length();i++)
        strt2.push_back(str2[i]);
    if (isSmaller(strt1, strt2)) 
        swap(str1, str2); 
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    int carry = 0; 
  
    for (int i=n2-1; i>=0; i--) 
    { 
        int sub = ((str1[i+diff]-'0') -(str2[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
  
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0)
            str.push_back(sub+'0'); 
        carry = 0; 
    } 
    reverse(str.begin(), str.end()); 
    string strf;
    for(k=0;k<str.length();k++)
        if(str[k]!='0')
            break;
    for(int i=k;i<str.length();i++)
        strf.push_back(str[i]);
    return strf; 
}       
//main function
int main() 
{
    int test_cases;
    cin>>test_cases;
    cout<<"\n";
    string  str1[test_cases], str2[test_cases], str;
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