#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

bool check_parenthesis(string str_paren)
{
	stack<char> stck_paren;
	int n=str_paren.length();
	for(int i=0;i<n;i++)
	{
		if((str_paren[i]=='(')||(str_paren[i]=='{')||(str_paren[i]=='[')||(str_paren[i]=='<'))
		{
			stck_paren.push(str_paren[i]);
		}
		else if((str_paren[i]==')')||(str_paren[i]=='}')||(str_paren[i]==']')||(str_paren[i]=='>'))
		{
			if(stck_paren.empty())
			{
				return false;
			}
			switch(str_paren[i])
			{
				case ')':
				{
					if(stck_paren.top()=='(')
						stck_paren.pop();
					else return false;
					break;
				}
				case '}':
				{
					if(stck_paren.top()=='{')
						stck_paren.pop();
					else return false;
					break;
				}
				case ']':
				{
					if(stck_paren.top()=='[')
						stck_paren.pop();
					else return false;
					break;
				}
				case '>':
				{
					if(stck_paren.top()=='<')
						stck_paren.pop();
					else return false;
					break;
				}
			}
		}
		else if(str_paren[i]=='|')
		{
			if((stck_paren.empty())||(stck_paren.top()!='|'))
			{
				stck_paren.push('|');
			}
			else
			{
				stck_paren.pop();
			}
		}
	}
	return stck_paren.empty();
}

int main()
{
	int test_cases;
	cin>>test_cases;
	bool yes_or_no[test_cases];
	for(int i=0;i<test_cases;i++)
	{
		string input;
		cin>>input;
		yes_or_no[i]=check_parenthesis(input);
	}
	for(int i=0;i<test_cases;i++)
	{
		if(yes_or_no[i])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}