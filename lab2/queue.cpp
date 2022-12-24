//linear queue

#include<iostream>
using namespace std;

const int MAX=5;

class Queue{
    private:
        int array[MAX];
        int front;
        int rear;
    public:
        Queue()
        {
            front = rear = -1;
        }
        bool isFull()
        {
            return(rear>=MAX-1);
        }
        bool isEmpty()
        {
            return(front==-1);
        }
        void enqueue(int item)
        {
            if(front==-1)
                front=0;
            if(isFull())
            {
                cout<<"Queue full, couldn't enqueue "<<item<<endl;
            }
            else
            {
                array[++rear] = item;
                cout<<"Enqueued "<<item<<endl;
            }
        }
        int dequeue()
        {
            int element;
            if(isEmpty())
            {
                cout<<"Queue empty, couldn't dequeue"<<endl;
                return 0;
            }
            else
            {
                element = array[front];
                cout<<"Dequeued "<<element<<endl;
                if(front == rear)//front=rear=max-1
                {
                    front = rear = -1;
                    cout<<endl<<"Reseting the queue again...."<<endl;
                }
                else
                    front++;
                return element;
            }
        }
        void display()
        {
            cout<<"Queue elements"<<endl;
            for(int i=front; i<=rear; i++)
            {
                cout<<array[i]<<endl;
            }
        }
};

int main()
{
    Queue q;

    q.dequeue();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();

    q.enqueue(6);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(8);
    q.display();
    return 0;
} 