#include<iostream>

using namespace std;

long int facto(int n)
{
    if(n<0)
        throw("That's a negative number.");
    if(n==0)
        return 1;
    else
        return (n * facto(n-1));
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