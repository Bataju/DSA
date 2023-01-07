#include <iostream>
using namespace std;
const int MAX = 50;

struct Node
{
    int data;
    int next;
};

class List
{
private:
    Node node[MAX];
    int head; // start of the list
    int size; // number of elements

public:
    List()
    {
        head = -1;
        size = 0;
    }
    int getNode(int data)
    {
        int index;
        if (size == MAX)
            throw("List is full, no more insertion possible.");
        else
        {
            index = size;
            size++;
        }
        node[index].data = data;
        node[index].next = -1;
        return index;
    }
    void insertAtBeg(int data)
    {
        int index = getNode(data);
        node[index].next = head;
        head = index;
        cout << "inserted " << data << " at front at index " << index << endl;
    }
    void insertAtEnd(int data)
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
        cout << "inserted " << data << " at end at index " << index << endl;
    }
    int delAtBeg()
    {
        if(size==0)
            throw("List is empty, no deletion possible.");
        int item = node[head].data;
        int itemindex = head;
        head = node[head].next;
        cout << "deleted " << item << " from the beginning at index " << itemindex << endl;
        size--;
        return item;
    }
    int delAtEnd()
    {
        if(size==0)
            throw("List is empty, no deletion possible.");
        int item;
        int i = head, secondToLast = i;
        while (node[i].next != -1)
        {
            secondToLast = i;
            i = node[i].next;
        }
        item = node[i].data;
        node[secondToLast].next = -1;
        cout << "deleted " << item << " from the end at index " << i << endl;
        size--;
        return item;
    }
    void displaySize()
    {
        cout << "Size of list: " << size << endl;
    }
    void displayList()
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
    List l;
    try
    {
        l.displayList();
        l.insertAtBeg(1);
        l.insertAtBeg(2);
        l.insertAtBeg(3);
        l.insertAtBeg(4);
        l.displayList();

        l.insertAtEnd(5);
        l.insertAtEnd(6);
        l.displayList();

        l.insertAtBeg(7);
        l.displayList();

        l.delAtBeg();
        l.insertAtEnd(8);
        l.displayList();
        l.insertAtBeg(0);
        l.displayList();

        l.delAtEnd();
        l.delAtBeg();
        l.displayList();
        l.displaySize();

        l.delAtBeg();
        l.delAtBeg();

        l.displayList();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    return 0;
}