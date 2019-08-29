#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct et{
string value;
et *r, *l;
};

struct var 
 {
 	string v;
    int i;
  };
 std::vector<var> variable;
 
bool isOperator(string c) 
{ 
     if (!c.compare("+") || !c.compare("-") || !c.compare("*") || !c.compare("/") || !c.compare("^")) 
        return true;
    return false; 
}
int getval(et * r)
{   if(isdigit(r->value[0]))
	 {
	 	return stoi(r->value);
	 }	
	else
		{
		  for(int j=0;j<variable.size();j++)
	     {  
		  if(!(r->value.compare(variable[j].v)))
		   {
			return variable[j].i;
		   }
	     }
	    } 
}
int eval(et* root)  
{   
    if (!root)  
        return 0;   
    if (!root->l && !root->r)  
    	{    //cout<<"$"<<getval(root);
        return getval(root);  
    }
    int lvalue = eval(root->l);  
    int rvalue = eval(root->r);  
    if (root->value=="+")  
        return lvalue+rvalue;  
  
    if (root->value=="-")  
        return lvalue-rvalue;  
  
    if (root->value=="*")  
        return lvalue*rvalue;  
        
    if (root->value=="/")  
        return lvalue/rvalue; 
  
    return pow(lvalue, rvalue);
}

et* newNode(string v) 
{ 
    et * temp = new et; 
    temp->l = nullptr; 
    temp->r = nullptr;
    temp->value = v; 
    return temp; 
} 

et* Tree(std::vector<std::string> s) 
{   
    stack<et*> st; 
    et *t, *t1, *t2;
    for (int i=0; i < s.size(); i++) 
    { 
        if (!isOperator(s[i])) 
        { 
            t = newNode(s[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(s[i]); 
            t1 = st.top();
            st.pop();
            t2 = st.top(); 
            st.pop();
            t->r = t1; 
            t->l = t2; 
            st.push(t); 
        } 
    }
    t = st.top(); 
    st.pop(); 
     
    return t; 
} 
int priority(char a) {
    int temp;
    if (a == '^')
        temp = 1;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 3;
    return temp;
}
string postfx(string d)
{
 int c=d.length();
    stack<char> operator_stack;
     vector<string> f;
      string g;
     int j=0,k=0;
    stringstream output;

    for (unsigned i = 0; i < d.length(); i++) {
        if (d[i] == '+' || d[i] == '-' || d[i] == '*' || d[i] == '/' || d[i] == '^') {
              output<<" ";
              f.push_back(output.str());
               while (!operator_stack.empty() && priority(operator_stack.top()) <= priority(d[i])) {
                output << operator_stack.top();
                output<<" ";
                 operator_stack.pop(); 
                }
                 f.push_back(output.str());  
                  
            operator_stack.push(d[i]);
            
        } 
          else if (d[i] == '(') 
            {
            operator_stack.push(d[i]);
            } 
          else if (d[i] == ')') 
              { f.push_back(output.str());
                output<<" ";
                while (operator_stack.top() != '(') 
               { 
               output << operator_stack.top();
                output<<" ";
                operator_stack.pop();
               }
                f.push_back(output.str()); 
                f.push_back(output.str());    
            operator_stack.pop();
        } else {
            output <<d[i];
         }
          
    }
         output<<" ";
    while (!operator_stack.empty()) {
        output <<operator_stack.top();
         output<<" ";
        operator_stack.pop();
    } 
      output<<" ";
     f.push_back(output.str());
     int t=f.size()-1;
    g=f[t];
    f.clear();
  return g;
}

void asign (string f)
{  
	string g1;
	int c=0;
	string t;
	for(int i=0;i<f.size();i++)
		 {
		 	if(f[i]=='=')
              { 
              	t=f[i-1];
              	//cout<<t<<endl;
              	c=i+1;
               }
              
		 }
		 for(;c<f.size();c++)
		 	g1.push_back(f[c]);
  //cout<<g1;		 
  string g=postfx(g1);
  std::istringstream iss(g);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
   //for(int i=0;i<results.size();i++)    
       //cout<<results[i]<<endl;
  et*root=Tree(results);
  //cout<<eval(root);
  int prn=0;
  for(int j=0;j<results.size();j++)
  {
  	if(isOperator(results[j]))
      prn++;
  }
    if(c!=0)
     {   
     	for(int x=0;x<variable.size();x++)
     	{
     		if(!(t.compare(variable[x].v)))
     		{
              variable[x].i=eval(root);
                 if(prn!=0)
              {
              cout<<variable[x].i<<endl;
              }
              goto abc;
     		}
     	}
         var d;
         
         d.v=t;
         d.i=eval(root);
         if(prn!=0)
         {
         cout<< d.i<<endl;
          }
         variable.push_back(d);
	    abc:
	    
     }
   
}
int main()
{   
	int cas;
	  cin>>cas;
	    while(cas--) 
	   	 {
	   	 	int nol;
	   	 	 cin>>nol;
	   	 	  while(nol--)
	   	 	  	 {
	   	 	  	 	 string infix;
	   	 	  	 	 cin>>infix;
	   	 	  	 	 asign(infix);

	   	 	  	 }
	    }
return 0;	   	 
}
