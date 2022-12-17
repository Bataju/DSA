#include<iostream>
using namespace std;
const int MAX = 5;

struct pQueueElement
{
    int value;
    int priority;
};

class pQueue
{
    private:
        pQueueElement pqueue[MAX];
        int rear;
    public:
        pQueue()
        {
            rear = -1;
        }
        bool isFull()
        {
            return (rear==MAX-1);
        }
        bool isEmpty()
        {
            return (rear==-1);
        }
        void enqueue(int item, int prty)
        {
            if(isFull())
                throw("QUEUE OVERFLOW.");
            else
            {
                rear++;
                pqueue[rear].value=item;
                pqueue[rear].priority=prty;
                cout<<"Enqueued "<<item<<endl;
            }
        }
        int peek()
        {
            if(isEmpty())
                throw("QUEUE EMPTY.");
            int highestPriorityIndex = 0;
            for(int i=0; i<=rear; i++)
            {
                if(pqueue[i].priority < pqueue[highestPriorityIndex].priority)
                    highestPriorityIndex=i;
            }
            return highestPriorityIndex;
        }
        int dequeue()
        {
            if(isEmpty())
                throw("QUEUE EMPTY.");
            else
            {
                int highestPriorityIndex = peek();
                int value = pqueue[highestPriorityIndex].value;
                for(int i=highestPriorityIndex; i<=rear; i++)
                {
                    pqueue[i]=pqueue[i+1];
                }
                rear--;
                cout<<"Dequeued "<<value<<endl;
                return pqueue[highestPriorityIndex].value;
            }
        }
};

int main()
{
    pQueue pq;
    try
    {
    pq.enqueue(3, 4);
    pq.enqueue(88, 1);
    pq.enqueue(6, 4);
    pq.enqueue(76, 2);
    pq.enqueue(89, 4);
    pq.enqueue(9, 8);

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    }
    catch(const char * err)
    {
        cout<<err<<endl;
    }
    return 0;
}