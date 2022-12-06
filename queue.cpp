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
            if(rear==MAX-1)
                return true;
            else    
                return false;
        }
        bool isEmpty()
        {
            if(front==rear)
                return true;
            else    
                return false;
        }
        void enque(int item)
        {
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
                element = array[++front];
                cout<<"Dequeued "<<element<<endl;
//when only one element (i.e. last element) is only left to dequeue
//front==rear==max-1, reset the queue i.e. front=rear=-1
                if((front == MAX-1) && (rear==MAX-1))//front==rear
                {
                    front = rear = -1;
                    cout<<endl<<"Reseting the queue again...."<<endl;
                }
                return element;
            }
        }
        void display()
        {
            cout<<"Queue elements"<<endl;
            for(int i=front+1; i<=rear; i++)
            {
                cout<<array[i]<<endl;
            }
        }
};

int main()
{
    Queue q;

    q.dequeue();

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

    q.display();

    q.enque(6);

    q.dequeue();
    q.dequeue();
    q.enque(7);//limitation of linear queue
//queue has empty spaces but we can't enque
//once queue is filled, even if we deque, no new elements can be added
   
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enque(8);//after reset
    q.display();
    return 0;
} 