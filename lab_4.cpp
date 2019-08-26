#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct expTreeNode
{
    string content;
    struct expTreeNode *left,*right;
};
typedef struct expTreeNode treeNode;

treeNode *newNode(string str)
{
    treeNode *temp=new treeNode;
    temp->left=temp->right=NULL;
    temp->content=str;
    return temp;
}

bool stringNumber(string str)
{
	if(str[0]-'0'>=0&&'9'-str[0]>=0)
		return true;
	return false;
}

int priority_of_operator(string opr)
{
    switch (opr[0])
    {
        case '(':
        {
            return 5;
        }
        case '^':
        {
            return 4;
        }
        case '/':
        {
            return 3;
        }
        case '*':
        {
            return 2;
        }
        case '+':
        case '-':
        {
            return 1;
        }
        case '=':
        {
            return 0;
        }
    }
}

bool isSymbol(string str)
{
    switch(str[0])
    {
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
        case '=':
        {
            return true;
        }
        default:
        {
            return false;
        }
    }
}

bool isSymbol1(string str, int index)
{
    for(int i=index-1;i>=0;i--)
    {
        if(str[i]==' ')
        {
            i--;
        }
        else
        {
            switch(str[i])
            {
                case '(':
                case '^':
                case '/':
                case '*':
                case '+':
                case '-':
                case '=':
                {
                    return true;
                    break;
                }
            }
            return false;
        }
    }
}

bool isCharacter(char toCheck)
{
    if('z'-toCheck>=0&&toCheck-'a'>=0)
    {
        return true;
    }
    if(toCheck-'A'>=0&&'Z'-toCheck>=0)
    {
        return true;
    }   
     return false;
}

bool isNumber(char toCheck)
{
    if(toCheck>='0'&&toCheck<='9')
    {
        return true;
    }
    return false;
}

void print_postfix(vector<string> postexp)
{
    for(int i=0;i<postexp.size();i++)
    {
        cout<<(string)postexp.at(i)<<" ";
    }
}

vector<string> convert_to_postfix(string expression)
{
    vector<string> cneval;
    cneval.push_back("NULL");
    vector<string> postExp;
    stack<string> symbols;
    int length=expression.length();
    string number="", variavle="";
    for(int i=0;i<length;i++)
    {
        switch(expression[i])
        {
            case '(':
            {

                symbols.push("(");
                break;
            }
            case ')':
            {
                while(symbols.top()!="(")
                {
                    postExp.push_back(symbols.top());
                    symbols.pop();
                    if(symbols.empty())
                    {
                        cout<<"Cannot be evaluated."<<endl;
                        return cneval;
                    }
                }
                symbols.pop();
                break;
            }
            case '^':
            case '/':
            case '*':
			
			{
                if(isSymbol1(expression,i))
                {
                    cout<<"Cannot be evaluated."<<endl;
                    return cneval;
                }
                else
                {
					if((!symbols.empty())&&(symbols.top()=="-"||symbols.top()=="+"))
					{
                        string top;
                        top=(string)symbols.top();
						symbols.pop();
						if(!symbols.empty()&&priority_of_operator((string)symbols.top())>0)
						{
							postExp.push_back(top);
						}
                        else
                        {
                            symbols.push(top);
                        }
					}
                    if((!symbols.empty())&&(priority_of_operator((string)symbols.top())<=priority_of_operator(expression[i]+"00")))
                    {
                        postExp.push_back(symbols.top());
                        symbols.pop();
                    }
                    string sym="";
                    sym+=expression[i];
                    symbols.push(sym);
                }
                break;
            }
            case '=':
            {
                if(isSymbol1(expression,i))
                {
                    cout<<"Cannot be evaluated."<<endl;
                    return cneval;
                }
                else
                {
                    if((!symbols.empty())&&priority_of_operator(symbols.top())>=priority_of_operator(expression[i]+"00"))
                    {
                        postExp.push_back(symbols.top());
                        symbols.pop();
                    }
                    string sym="";
                    sym+=expression[i];
                    symbols.push(sym);
                }
                break;
            }
            case '+':
            case '-':
            {
                if(isSymbol1(expression,i))
                {
                    postExp.push_back("0");
                }
                else
                {
                    if((!symbols.empty())&&(symbols.top()=="-"||symbols.top()=="+"))
                    {  
                        string top;
                        top=symbols.top();
                        symbols.pop();
                        if((!symbols.empty())&&priority_of_operator(symbols.top())>0)
                        {
                            postExp.push_back(top);
                        }
                        else
                        {
                            symbols.push(top);
                        }
                    }
                    if((!symbols.empty())&&priority_of_operator(symbols.top())>=priority_of_operator(expression[i]+"00"))
                    {
                        if(symbols.top()!="(")
                        {
                            postExp.push_back(symbols.top());
                            symbols.pop();
                        }
                    }
                }
                string sym="";
                sym+=expression[i];
                symbols.push(sym);
                break;
            }
            case ' ':
            {
                i++;
                break;
            }
        }
        if(isCharacter(expression[i]))
        {
            variavle+=expression[i];
            if(!isCharacter(expression[i+1]))
            {
                if(isNumber(expression[i+1]))
                {
                    cout<<"Cannot be Evaluated.";
                    return cneval;
                }
                postExp.push_back(variavle);
                variavle="";
            }
        }
        if(isNumber(expression[i]))
        {
            number+=expression[i];
            if(!isNumber(expression[i+1]))
            {
                if(isCharacter(expression[i+1]))
                {
                    cout<<"Cannot be evaluated.";
                    return cneval;
                }
                postExp.push_back(number);
                number="";
            }
        }
    }
    while(!symbols.empty())
    {
        postExp.push_back(symbols.top());
        symbols.pop();
    }
    return postExp;
}

treeNode* MakeTree(vector<string> postfix)
{
    stack<treeNode*> st;
    treeNode *t, *t1, *t2;
    int n=postfix.size();
    for(int i=0;i<n;i++)
    {
        if(!isSymbol((string)postfix.at(i)))
        {
            t=newNode((string)postfix.at(i));
            st.push(t);
        }
        else
        {
            t=newNode((string)postfix.at(i));
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            t->left=t2;
            t->right=t1;
            st.push(t);
        }
    }
    t=st.top();
    return t;
}

int calculate(int num1, int num2, string oper)
{
    char sign=oper[0];
    switch(sign)
    {
        case '+':
        {
            return num1+num2;
        }
        case '-':
        {
            return num1-num2;
        }
        case '*':
        {
            return num1*num2;
        }
        case '/':
        {
            return num1/num2;
        }
        case '^':
        {
            int res=1;
            if(num2>0)
            {
                for(int i=0;i<num2;i++)
                {
                    res*=num1;
                }
            }
            else if(num2<0)
            {
                for(int i=0;i>num2;i=i-1)
                {
                    res/=num1;
                }
            }
            return res;
        }
    }
}

bool correctness(treeNode* tree, vector<string> *names, vector<int> *values)
{
    if(isSymbol(tree->content))
    {
        return (correctness(tree->left,names,values)&correctness(tree->right,names,values));
    }
    else if(stringNumber(tree->content))
    {
        return true;
    }
    else
    {
        for(int i=0;i<(*names).size();i++)
        {
            if(tree->content==(string)(*names).at(i))
            {
                return true;
            }
        }
        return false;
    }
    
}

int evaluate1(treeNode* expTree,vector<string> *varNames,vector<int> *varVals)
{
    if(expTree)
    {
        int num1,num2;
        if(!isSymbol((string)expTree->content))
        {
            if(stringNumber((string)expTree->content))
            {
                int num=0;
                for(int i=0;i<((string)expTree->content).length();i++)
                {
                    num*=10;
                    num+=expTree->content[i]-'0';
                }
                return num;
            }
            else
            {
                for(int i=0;i<(*varNames).size();i++)
                {
                    if((string)(*varNames).at(i)==expTree->content)
                    {
                        return (int)(*varVals).at(i);
                    }
                }
            }
            
        }
        else
        {
            num1 = evaluate1(expTree->left,varNames,varVals);
            num2 = evaluate1(expTree->right,varNames,varVals);
        }
        return calculate(num1, num2, expTree->content);
    }
}

void evaluate(treeNode* expTree,vector<string> *varNames,vector<int> *varVals)
{
    if(expTree&&correctness(expTree,varNames,varVals))
    {
        int num1,num2;
        if(!isSymbol((string)expTree->content))
        {
            if(stringNumber((string)expTree->content))
            {
                int num=0;
                for(int i=0;i<((string)expTree->content).length();i++)
                {
                    num*=10;
                    num+=expTree->content[i]-'0';
                }
                cout<<num;
            }
            else
            {
                for(int i=0;i<(*varNames).size();i++)
                {
                    if((string)(*varNames).at(i)==expTree->content)
                    {
                        cout<<(int)(*varVals).at(i);
                    }
                }
            }
            
        }
        else
        {
            num1 = evaluate1(expTree->left,varNames,varVals);
            num2 = evaluate1(expTree->right,varNames,varVals);
        }
        cout<<calculate(num1, num2, expTree->content);
    }
    cout<<"Cannot be evaluated"<<endl;
}

void assign(treeNode *tree, vector<string> *varNames, vector<int> *varVals)
{
    if(isSymbol(tree->left->content))
    {
        cout<<"Cannot be evaluated.";
        return;
    }
    else
    {
        int n=(*varNames).size();
        int value=evaluate1(tree->right,varNames,varVals);
        int i;
        for(i=0;i<n;i++)
        {
            if(tree->left->content==(string)(*varNames).at(i))
            {
                (*varVals).at(i)=value;
            }
        }
        if(i==n)
        {
            (*varNames).push_back(tree->left->content);
            (*varVals).push_back(value);
        }
    }
}

int main()
{
    int tCases;
    cin>>tCases;
    for(int i=0;i<tCases;i++)
    {
        int operationCount;
       	cin>>operationCount;
    	vector<int> values;
        vector<string> names;
        treeNode *tree;
        for(int j=0;j<operationCount;j++)
	    {
            string input;
            cin>>input;
            vector<string> input_postfix=convert_to_postfix(input);
            if((string)input_postfix[0]=="NULL")
            {
                j++;
            }
            else
            {
                tree=MakeTree(input_postfix);
                if((string)tree->content=="=")
                {
                    assign(tree, &names, &values);
                }
                else
                {
                    evaluate(tree,&names,&values);
                }
            }
	    }
    }
    return 0;
}
