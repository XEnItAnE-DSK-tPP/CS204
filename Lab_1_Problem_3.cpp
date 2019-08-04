#include<bits/stdc++.h>
using namespace std;
string findProduct(string str1, string  str2)
{
    int n1=str1.length(),  n2=str2.length();
    int result[n1+n2];
    for(int i=0;i<n1+n2;i++)
        result[i]=0;
    int carry;
    for(int i=n1-1;i>=0;i=i-1)
    {
        carry=0;
        for(int j=n2-1;j>=0;j=j-1)
        {
            result[i+j+1]+=(str1[i]-'0')*(str2[j]-'0')+carry;
            carry=result[i+j+1]/10;
            result[i+j+1]=result[i+j+1]%10;
        }
        result[i]+=carry;
    }
    
    int start=0;
    for(int i=0;i<n1+n2;i++)
    {
        if(result[i]==0)
        {
            start++;
        }
        else
        {
            break;
        }
    }
    string product="";
    for(int i=start;i<n1+n2;i++)
    {
        product.push_back('0'+result[i]);
    }
    return product;
}
int main()
{
    int test_cases;
    cin>>test_cases;
    cout<<"\n";
    string str1[test_cases],str2[test_cases];
    for(int i=0;i<test_cases;i++)
    {
        cin>>str1[i];
        cin>>str2[i];
        cout<<"\n";
    }
    for(int i=0;i<test_cases;i++)
    {
        cout<<findProduct(str1[i],str2[i])<<"\n";
    }
    return 0;
}