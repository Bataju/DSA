#include<iostream>
#include <ctype.h>
#include<string>
#include"stack.cpp"
using namespace std;

string reverse(string str)
{
    string result = "";
    for(int i=str.length()-1; i>=0; i--)
        result=result+str[i];
    return result;
}

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

string infix2prefix(string str)
{
    str = reverse(str);
    Stack s;
    string result="";
    char poppedItem;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')
            continue;//skip white spaces
        if(isalnum(str[i]))
            result=result+str[i];
        else if(str[i]==')')
            s.push(')');
        else if(str[i]=='(')
        {
            while(s.stackTop() != ')')
            {
                poppedItem = s.pop();
                result=result+poppedItem;
            }
            s.pop();
        }
        else if(s.stackTop()==')' || s.isEmpty())//if stack is empty or stack top is ) push any operator
            s.push(str[i]);
        else if(precedence(str[i])<precedence(s.stackTop()))
        {
            while (!s.isEmpty())
            {
                poppedItem=s.pop();
                result=result+poppedItem;
                if(precedence(str[i])>=precedence(s.stackTop()))
                    break;
            } 
            s.push(str[i]);
        }
        else if(s.stackTop()=='^' && str[i]=='^')//r to l
        {
            poppedItem=s.pop();
            result=result+poppedItem;
            s.push(str[i]);
        }
        else//precedence(str[i])>=precedence(s.stackTop())
            s.push(str[i]);
    }
    while(!s.isEmpty())
    {
        poppedItem = s.pop();
        result=result+poppedItem;
    }
    return reverse(result);
}


int main()
{
    string str="k+l-m*n+(o^p)*w/u/v*t+q^j^a";
    cout<<infix2prefix(str)<<endl;
}