#include<iostream>
using namespace std;

void towersOfHanoi(int n, char source, char destination, char auxillary)
{
    if(n==1)
        cout<<"Move "<<source<<" to "<<destination<<". "<<endl;
    else
    {
        towersOfHanoi(n-1, source, auxillary, destination);
        towersOfHanoi(1, source, destination, auxillary);
        towersOfHanoi(n-1, auxillary, destination, source);
    }
}

int main()
{
    towersOfHanoi(5, 'A', 'B', 'C');//a source b destination
    return 0;
}
