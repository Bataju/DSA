#include <iostream>
#include <ctype.h>
#include <string>
#include "stack.cpp"
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infix2postfix(string str)
{
    Stack<char> s;
    string result = "";
    char poppedItem;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        if (isalnum(str[i]))
            result = result + str[i];
        else if (str[i] == '(' || s.stackTop() == '(' || s.isEmpty())
            s.push(str[i]);
        else if (str[i] == ')')
        {
            while (s.stackTop() != '(')
            {
                poppedItem = s.pop();
                result = result + poppedItem;
            }
            s.pop(); // pop (
        }
        else if (precedence(str[i]) > precedence(s.stackTop()))
            s.push(str[i]);
        else if ((precedence(str[i]) == precedence(s.stackTop())) && str[i] == '^')
            s.push(str[i]);
        else
        {
            while (!s.isEmpty())
            {
                poppedItem = s.pop();
                result = result + poppedItem;
                if (precedence(str[i]) > precedence(s.stackTop()))
                    break;
            }
            s.push(str[i]);
        }
    }
    while (!s.isEmpty())
    {
        poppedItem = s.pop();
        result = result + poppedItem;
    }
    return result;
}

int main()
{
    string str = "k+l-m*n+(o^p)*w/u/v*t+q^j^a";
    cout << infix2postfix(str) << endl;
}