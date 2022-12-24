#include<iostream>
using namespace std;

int fiboTail(int n, int a=0, int b=1)
{
    if(n==1)
        return a;
    else if(n==2)
        return b;
    else
        return fiboTail(n-1, b, a+b);
}

int main()
{
    int number;
    cout<<"How many terms of the fibonacci sequence do you wish for? ";
    cin>>number;
    for(int i=1;i<=number;i++)
    {
        cout<<fiboTail(i)<<", ";
    }
    return 0;
}