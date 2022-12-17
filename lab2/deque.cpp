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
                rear = 0;
                front = 0;
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
                front = rear = -1; // reset
                cout << "Deque reset." << endl;
            }
            else
            {
                if (rear == 0)
                    rear = MAX - 1;
                else
                    rear--;
            } // CIRCULAR
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
                front = rear = -1; // reset
                cout << "Deque reset." << endl;
            }
            else
            {
                if (front == MAX - 1)
                    front = 0;
                else
                    front++;
            } // CIRCULAR
        }
        return element;
    }
    void display()
    {
        int i;
        cout << "Front: " << front << endl;
        cout << "Rear: " << rear << endl;
        cout << "Queue elements.." << endl;
        if (front != -1) // don't display for empty deque
        {
            for (i = front; i != rear; i = (i + 1) % MAX)
            {
                cout << array[i] << endl;
            }
            cout << array[i] << endl; // for rear
        }
    }
};

int main()
{
    Deque d;
    d.insertrear(1);
    d.insertrear(2);
    d.insertrear(3);
    d.insertrear(4);
    d.insertrear(5);

    d.deletefront();
    d.insertfront(6);
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.display();
    return 0;
}
