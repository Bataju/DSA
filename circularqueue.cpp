#include<iostream>
using namespace std;
const int MAX = 5;

class Queue
{
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
            if((front==0 && rear==MAX-1) || front==rear+1)
                return true;
            else
                return false;
        }
        bool isEmpty()
        {
            if(front==-1)
                return true;
            else
                return false;
        }
        void enqueue(int item)
        {
            if(isFull())
                cout<<endl<<"Queue full, couldn't enqueue "<<item<<endl;
            else
            {
                if(front==-1)
                {
                    front = 0;
                }
                
                rear=(rear+1)%MAX;
                array[rear] = item;
                cout<<endl<<"Enqueued "<<item<<"."<<endl;
            }
        }
        int dequeue()
        {
            int element;
            if(isEmpty())
            {
                cout<<endl<<"Queue empty, couldn't dequeue"<<endl;
                return -1;
            }
            else
            {
                element = array[front];
                cout<<endl<<"Dequeued "<<element<<"."<<endl;
                if(front==rear)
                {
                    front = rear = -1;
                }
                else
                    front = (front+1)%MAX; //CIRCULAR
            }
            return element;
        }
        void display()
        {
            int i;
            for(int j=0; j<20; j++)
            {
                cout<<"__";
            }
            cout<<endl<<"Front: "<<front<<endl;;
            cout<<"Rear: "<<rear<<endl;
            cout<<"Queue elements.."<<endl;
            if(front!=-1)//to prevent from printing value at array[-1] when queue is empty
            {
                for(i=front; i!=rear; i=(i+1)%MAX)
                {
                    cout<<array[i]<<endl;
                }
                cout<<array[i]<<endl;
            }
            for(int j=0; j<20; j++)
            {
                cout<<"__";
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
    q.enqueue(6);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(7);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}