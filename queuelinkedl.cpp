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
class Queue
{
    private:
        node<T> *front, *rear;
    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
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
        void enqueue(T item)
        {
            node<T>* newNode = createNewNode(item);
            if(front == NULL)
                front = newNode;
            else
                rear->next = newNode;
            rear = newNode;
            cout<<"Enqueued "<<item<<endl;
        }
        T dequeue()
        {
            T item;
            node<T> *temp = front;
            if(front==NULL)
                throw("UNDERFLOW");
            item = front->value;
            front = front->next;
            delete temp;
            cout<<"Dequeued "<<item<<endl;
            return item;
        }
        void display()
        {
            node<T> *temp = front;
            cout<<"Queue elements"<<endl;
            if(front==NULL)
                cout<<"Empty"<<endl;
            else
            {
                while(temp->next != NULL)
                {
                    cout<<temp->value<<endl;
                    temp=temp->next;
                }
                cout<<rear->value<<endl;
            }
        }
};

int main()
{
    Queue<int> q;
    try
    {
        q.display();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.display();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.display();
    }
    catch(const char* err)
    {
        cerr << err << '\n';
    }
    return 0;
}