#include <iostream>
using namespace std;
const int MAX = 5;

class Deque
{
private:
    int array[MAX];
    int front;
    int rear;

public:
    Deque()
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
    void insertrear(int item)
    {
        if (isFull())
            cout << "Queue full, couldn't insert " << item << " at rear end."<<endl;
        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else if (rear == MAX - 1)
                rear = 0;
            else
                rear++;
            array[rear] = item;
            cout << "Inserted " << item << " at the rear end. At index " << rear << "."<<endl;
        }
    }
    void insertfront(int item)
    {
        if (isFull())
            cout << "Queue full, couldn't insert " << item << " at front."<<endl;
        else
        {
            if (rear == -1)
            {
                rear = MAX-1;
                front = MAX-1;
            }
            else if (front == 0)
                front = MAX - 1;
            else
                front--;
            array[front] = item;
            cout << "Inserted " << item << " at the front. At index " << front << "."<<endl;
        }
    }
    int deleterear()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue empty, couldn't delete from rear end."<<endl;
            return -1;
        }
        else
        {
            element = array[rear];
            cout << "Deleted " << element << " from rear end."<<endl;
            if (front == rear)
            {
                front = rear = -1;
                cout << "Deque reset." << endl;
            }
            else
            {
                if (rear == 0)
                    rear = MAX - 1;
                else
                    rear--;
            }
        }
        return element;
    }
    int deletefront()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue empty, couldn't delete from front."<<endl;
            return -1;
        }
        else
        {
            element = array[front];
            cout << "Deleted " << element << " from front."<<endl;
            if (front == rear)
            {
                front = rear = -1;
                cout << "Deque reset." << endl;
            }
            else
            {
                if (front == MAX - 1)
                    front = 0;
                else
                    front++;
            }
        }
        return element;
    }
    void display()
    {
        int i;
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
        cout << "Queue elements" << endl;
        if(front==rear)
            cout<<"Empty"<<endl;
        else
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
    Deque d;
    d.insertfront(1);
    d.insertfront(2);
    d.insertfront(3);
    d.insertfront(4);
    d.insertrear(6);
    d.display();
    d.deletefront();
    d.deletefront();
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.display();
    return 0;
}
