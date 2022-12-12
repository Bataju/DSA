#include<iostream>
#include <ctype.h>
#include<string>
#include"stack.cpp"
using namespace std;

int precedence(char op)
{
    if(op=='^')
        return 3;
    if(op=='/' || op=='*')
        return 2;
    else if(op=='+'||op=='-')
        return 1;
    else
        return 0;
}

string infix2postfix(string str)
{
    Stack<char> s;
    string result="";
    char poppedItem;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')
            continue;//skip white spaces
        if(isalnum(str[i]))
            result=result+str[i];
        else if(str[i]=='(')
            s.push('(');
        else if(str[i]==')')
        {
            while(s.stackTop() != '(')
            {
                poppedItem = s.pop();
                result=result+poppedItem;
            }
            s.pop();//pop (
        }
        else if(s.stackTop()=='(' || s.isEmpty())//if stack is empty or stack top is ( push any operator
            s.push(str[i]);
        else if(precedence(str[i])>precedence(s.stackTop()))
            s.push(str[i]);
        //for ^, assoiativity is r to l(so push)
        //so for same precedence, we need to push as the later is to be evaluated first
        else if(s.stackTop()=='^' && str[i]=='^')
            s.push(str[i]);
        //case for precedence of scanned item <= precedence of top of stack (except for ^)
        else
        {
            while (!s.isEmpty())
            {
                poppedItem=s.pop();
                result=result+poppedItem;
                if(precedence(str[i])>precedence(s.stackTop()))
                    break;
            } 
            s.push(str[i]);
        }
    }
    while(!s.isEmpty())
    {
        poppedItem = s.pop();
        result=result+poppedItem;
    }
    return result;
}


int main()
{
    string str="k+l-m*n+(o^p)*w/u/v*t+q^j^a";
    cout<<infix2postfix(str)<<endl;
}