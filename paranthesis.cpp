#include<iostream>
#include<string>
#include"stack.cpp"

using namespace std;

int checkParanthesis(string str)
{
    Stack s;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(')
            s.push(str[i]);
        else if(str[i]=='{')
            s.push(str[i]);
        else if(str[i]=='[')
            s.push(str[i]);
        else if(str[i]==')')
        {
            if(s.stackTop()=='(')
                s.pop();
            else
                return 0;
        }
        else if(str[i]=='}')
        {
            if(s.stackTop()=='{')
                s.pop();
            else
                return 0;
        }
        else if(str[i]==']')
        {
            if(s.stackTop()=='[')
                s.pop();
            else
                return 0;
        }
        else if(str[i]==' ')
            continue;
        else
            continue;
    }
    if(s.isEmpty())
        return 1;
    else
        return 0;
}

int main()
{
    string expr = "99+((9-0)-{98-[99-0]}*2";
    int flag = checkParanthesis(expr);
    if(flag)
        cout<<"ok"<<endl;
    else
        cout<<"not ok"<<endl;
    return 0;
}