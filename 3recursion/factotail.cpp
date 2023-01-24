#include<iostream>
using namespace std;

long int factoMain(int n, long int result)
{ 
    if(n<0)
        throw("That's a negative number.");
    if(n==0)
        return result;
    else
        return factoMain(n-1, result*n);
}

long int facto(int n)//wrapper
{
    return factoMain(n, 1);
}

int main()
{
    int number;
    cout<<"Enter a positive integer: ";
    cin>>number;
    try
    {
        long int result = facto(number);
        cout<<"Factorial of "<<number<<": "<<result<<endl;
    }
    catch(const char* err)
    {
        cout<<err<<endl;
    }
    return 0;
}