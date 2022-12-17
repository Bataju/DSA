#include <iostream>
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
        return ((front == 0 && rear == MAX - 1) || front == rear + 1);
    }
    bool isEmpty()
    {
        return (front == -1);
    }
    void enqueue(int item)
    {
        if (isFull())
            cout << "Queue full, couldn't enqueue " << item << endl;
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX;
            array[rear] = item;
            cout << "Enqueued " << item << "." << endl;
        }
    }
    int dequeue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue empty, couldn't dequeue" << endl;
            return -1;
        }
        else
        {
            element = array[front];
            cout << "Dequeued " << element << "." << endl;
            if (front == rear)
            {
                front = rear = -1; // reset
            }
            else
                front = (front + 1) % MAX; // CIRCULAR
        }
        return element;
    }
    void display()
    {
        int i;
        cout << "Front: " << front << endl;
        ;
        cout << "Rear: " << rear << endl;
        cout << "Queue elements.." << endl;
        if (front != -1)
        {
            for (i = front; i != rear; i = (i + 1) % MAX)
            {
                cout << array[i] << endl;
            }
            cout << array[i] << endl;
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