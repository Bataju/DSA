#include <iostream>
using namespace std;
const int MAX = 50;

struct Node
{
    int data;
    int next;
};

class Queue
{
private:
    Node node[MAX];
    int head; // start of the list
    int size; // number of elements

public:
    Queue()
    {
        head = -1;
        size = 0;
    }
    int getNode(int data)
    {
        int index;
        if (size == MAX)
            throw("Queue is full, no more enqueue possible.");
        else
        {
            index = size;
            size++;
        }
        node[index].data = data;
        node[index].next = -1;
        return index;
    }
    void enqueue(int data)
    {
        int index = getNode(data);
        if (head == -1)
        {
            head = index;
        }
        else
        {
            int i = head;
            while (node[i].next != -1)
                i = node[i].next;
            node[i].next = index;
            node[index].next = -1;
        }
        cout << "enququed " << data << " at index " << index << endl;
    }
    int dequeue()
    {
        if(size==0)
            throw("Queue empty, no dequeue possible.");
        int item = node[head].data;
        int itemindex = head;
        head = node[head].next;
        cout << "dequeued " << item << " from index " << itemindex << endl;
        size--;
        return item;
    }
    void displaySize()
    {
        cout << "Size of list: " << size << endl;
    }
    void displayQueue()
    {
        cout << "List elements.." << endl;
        if (head == -1)
        {
            cout << "Empty" << endl;
        }
        else
        {
            int i = head;
            while (node[i].next != -1)
            {
                cout << node[i].data << endl;
                i = node[i].next;
            }
            cout << node[i].data << endl;
        }
    }
};

int main()
{
    Queue q;
    try
    {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.dequeue();
        q.displayQueue();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    return 0;
}