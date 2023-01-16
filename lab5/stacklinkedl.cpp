#include<iostream>
using namespace std;

template <class T>
class node
{
    public:
        T value;
        node* next;
};

template <class T>
class Stack
{
    private:
        node<T> *top;
    public:
        Stack()
        {
            top = NULL;
        }
        node<T>* createNewNode(T item)
        {
            node<T>* newNode = new node<T>;
            if(newNode == NULL)
                throw("OVERFLOW");
            newNode->value = item;
            newNode->next = NULL;
            return newNode;
        }
        void push(T item)
        {
            node<T>* newNode = createNewNode(item);
            newNode->next = top;
            top = newNode;
            cout<<"Pushed "<<item<<endl;
        }
        T pop()
        {
            T item;
            node<T> *temp = top;
            if(top==NULL)
                throw("UNDERFLOW");
            item = top->value;
            top = top->next;
            delete temp;
            cout<<"Popped "<<item<<endl;
            return item;
        }
        void display()
        {
            node<T> *temp = top;
            cout<<"Stack elements"<<endl;
            if(top==NULL)
                cout<<"Empty"<<endl;
            else
            {
                while(temp->next != NULL)
                {
                    cout<<temp->value<<endl;
                    temp=temp->next;
                }
                cout<<temp->value<<endl;
            }
        }
};

int main()
{
    Stack<char> s;
    try
    {
        s.display();
        s.push('1');
        s.push('2');
        s.push('3');
        s.display();
        s.pop();
        s.pop();
        s.pop();
        s.pop();//underflow
    }
    catch(const char* err)
    {
        std::cerr << err << '\n';
    }
    return 0;
}