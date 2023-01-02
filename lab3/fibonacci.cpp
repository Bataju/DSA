#include<iostream>
using namespace std;

long long int fibo(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}

int main()
{
    int number;
    cout<<"How many terms of the fibonacci sequence do you wish for? ";
    cin>>number;
    for(int i=1;i<=number;i++)
    {
        cout<<fibo(i)<<", ";
    }
    return 0;
}