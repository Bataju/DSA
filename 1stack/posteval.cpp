#include<iostream>
#include <ctype.h>
#include<string>
#include<cmath>
#include"stack.cpp"
using namespace std;

int postfixevaluator(string expr)
{
    int op1, op2, result=0;
    Stack<int> s;
    for(int i=0; i<expr.length(); i++)
    {
        if(expr[i]==' ')
            continue;
        if(isalnum(expr[i]))
        {
            s.push(int(expr[i])-int('0'));//else ascii value of the number will be pushed
        }
        else 
        {
            op1 = s.pop();
            op2 = s.pop();
            if(expr[i]=='+')
                result = op2 + op1;
            else if(expr[i]=='-')
                result = op2 - op1;
            else if(expr[i]=='*')
                result = op2*op1;
            else if(expr[i]=='/')
                result = op2/op1;
            else 
                result = pow(op2, op1);//^
            s.push(result);
        }
    }
    return result;
}

int main()
{
    cout<<postfixevaluator("5 6 2 ^ 2 - *")<<endl;
    return 0;
}