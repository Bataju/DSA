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
        void push(int item)
        {
            if(isFull())
                cout<<"Stack full, "<<item<<" couldn't be pushed"<<endl;
            else
            {
                array[++top]=item;
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
