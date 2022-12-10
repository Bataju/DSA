#include<iostream>
const int MAX = 50;

using namespace std;

class Stack{
    private:
        char array[MAX];
        int top;
    public:
        Stack()
        {
            top = -1;
        }
        bool isFull()
        {
            if(top == MAX -1)
                return true;
            else
                return false;
        }
        bool isEmpty()
        {
            if(top==-1)
                return true;
            else 
                return false;
        }
        void push(int item)
        {
            if(isFull())
                cout<<"Stack full, "<<item<<" couldn't be pushed"<<endl;
            else
            {
                array[++top]=item;
            }
        }
        char pop()
        {
            if(isEmpty())
            {
                cout<<"Stack empty, no more pop"<<endl;
                exit(0);
            }
            else
            {
                return array[top--];
            }
        }
        char stackTop()
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
//     Stack s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.push(6);//should bring error full

//     s.display();

//     s.pop();

//     s.display();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();//error empty

//     s.display();
//     return 0;
// }
