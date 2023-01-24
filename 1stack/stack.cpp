#include<iostream>
const int MAX = 50;

using namespace std;

template <class T>
class Stack{
    private:
        T array[MAX];
        int top;
    public:
        Stack()
        {
            top = -1;
        }
        bool isFull()
        {
            return (top>=MAX-1);
        }
        bool isEmpty()
        {
            return top==-1;
        }
        void push(T item)
        {
            if(isFull())
                cout<<"Stack full, "<<item<<" couldn't be pushed"<<endl;
            else
            {
                array[++top]=item;
                cout<<"Pushed "<<item<<endl;
            }
        }
        T pop()
        {
            if(isEmpty())
            {
                cout<<"Stack empty, no more pop"<<endl;
                exit(0);
            }
            else
            {
                cout<<"Popped "<<array[top]<<endl;
                return array[top--];
            }
        }
        T stackTop()
        {
            return array[top];
        }
        void display()
        {
            cout<<"Stack elements"<<endl;
            for(int i=0; i<=top; i++)
            {
                cout<<array[i]<<endl;
            }
        }
};

// int main()
// {
//     Stack<int> s;
//     int n;
//     char ch;
//     do
//     {
//         cout<<"Enter number to be pushed: ";
//         cin>>n;
//         s.push(n);
//         cout<<"Continue? ['y' or 'n']: ";
//         cin>>ch;
//     } while (ch != 'n' && ch != 'N');
//     s.display();
//     while(!s.isEmpty())
//     {
//         s.pop();
//     }
//     cout<<"After popping..."<<endl;
//     s.display();
//     return 0;
// }
