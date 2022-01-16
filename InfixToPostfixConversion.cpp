#include<iostream>
#include<string>
#include<stack>
using namespace std;
int Precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	else
		return -1;
}
bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	else
		return false;
}
string InfixToPostfix(stack<char> s,string infix)
{
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
    	if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z'))
    	{
    		postfix+=infix[i];
    	}
    	else if(infix[i]=='(')
    	{
    		s.push(infix[i]);
    	}
    	else if(infix[i]==')')
    	{
    		while(s.top()!='(' && (!s.empty()))
    		{
    			char temp;
                temp=s.top();
                postfix+=temp;
                s.pop();
    		}
    		s.pop();
    	}
    	else if(isOperator(infix[i]))
    	{
    		if(s.empty())
    		{
    			s.push(infix[i]);
    		}
    		else
    		{
    			if(Precedence(infix[i])>Precedence(s.top()))
    			{
                   s.push(infix[i]);
    			}
    			else if(Precedence(infix[i])==Precedence(s.top()) && (infix[i]=='^'))
    			{
                    s.push(infix[i]); 
    			}
    			else
    			{
    				while((!s.empty()) && (Precedence(infix[i])<=Precedence(s.top())))
    		        {
    			      char temp;
                      temp=s.top();
                      postfix+=temp;
                      s.pop();
    		        }
    		        s.push(infix[i]);
    			}
    		}
    	}
    }
    while(!s.empty())
    {
    	postfix+=s.top();
    	s.pop();
    }
    return postfix;
}
int main()
{
    string Postfix,Infix;
    cout<<"Enter a infix expression : "<<endl;
    cin>>Infix;
    cout<<"Infix expression : "<<Infix<<endl;
    stack <char> s1;
    Postfix=InfixToPostfix(s1,Infix);
    cout<<"Postfix expression : "<<Postfix<<endl;
	return 0;
}