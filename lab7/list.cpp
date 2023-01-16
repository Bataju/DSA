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
        size++;
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
        size++;
        cout << "inserted " << data << " at end at index " << index << endl;
    }
    void insertAfterElement(int reference, int data)
    {
        int index = getNode(data);
        int i=head, temp;
        if(head == -1)
            throw("List is empty, no such element");
        while(node[i].data != reference)
        {
            if(node[i].next == -1)
                throw("No such element in the list");
            i=node[i].next;
        }
        temp = node[i].next;
        node[i].next = index;
        node[index].next = temp;
        size++;
        cout << "inserted " << data << " after the element "<<reference<<" at index " << index << endl;
    }
    void insertBeforeElement(int reference, int data)
    {
        int index = getNode(data);
        int i=head, pre_i=i, temp;
        if(head == -1)
            throw("List is empty, no such element");
        if(node[head].data==reference)
        {
            node[index].next = head;
            head = index;
        }
        else
        {
            while(node[i].data != reference)
            {
                if(node[i].next == -1)
                    throw("No such element in the list");
                pre_i = i;
                i=node[i].next;
            }
            node[pre_i].next = index;
            node[index].next = i;
        }
        size++;
        cout << "inserted " << data << " before the element "<<reference<<" at index " << index << endl;
    }
    int delAtBeg()
    {
        if(head==-1)
            throw("List is empty, no deletion possible.");
        int item = node[head].data;
        int itemindex = head;
        head = node[head].next;
        cout << "deleted " << item << " from the beginning at index " << itemindex << endl;
        return item;
    }
    int delAtEnd()
    {
        if(head==-1)
            throw("List is empty, no deletion possible.");
        int item;
        int i = head, secondToLast = i;
        if(node[head].next == -1)
        {
            item = node[head].data;
            head = -1;
        }
        else
        {
            while (node[i].next != -1)
            {
                secondToLast = i;
                i = node[i].next;
            }
            item = node[i].data;
            node[secondToLast].next = -1;
        }
        cout << "deleted " << item << " from the end at index " << i << endl;
        return item;
    }
    int delAfterElement(int reference)
    {
        int item;
        int i=head, store_i;
        while(node[i].data!=reference)
        {
            if(node[i].next == -1)
                throw("No such element in the list");
            i=node[i].next;
        }
        if(node[i].data == reference && node[i].next==-1)
            throw("No element after the given element, therefore no deletion");
        store_i = i;
        i=node[i].next;//i is the index of node to be deleted
        item = node[i].data;
        node[store_i].next = node[i].next;
        cout << "deleted " << item << " after the element "<<reference<<" at index " << i << endl;
        return item;
    }
    int delBeforeElement(int reference)
    {
        int item;
        int i=head, pre_i=i, pre_pre_i = pre_i;
        if(node[i].data == reference)
            throw("No element before the given element, therefore no deletion");
        if(node[node[i].next].data == reference)//reference element is the 2nd element
        {
            item = node[head].data;
            head = node[head].next;
        }
        else
        {
            while(node[i].data!=reference)
            {
                if(node[i].next == -1)
                    throw("No such element in the list");
                pre_pre_i = pre_i;
                pre_i = i;
                i = node[i].next;
            }
            item = node[pre_i].data;
            node[pre_pre_i].next = node[pre_i].next;//i
        }
        cout << "deleted " << item << " before the element "<<reference<<" at index " << pre_i << endl;
        return item;
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
        l.insertAtBeg(1);
        l.insertAtEnd(2);
        l.insertAtEnd(3);
        l.insertAtEnd(4);
        l.insertAtBeg(0);
        l.displayList();

        l.delAtBeg();
        l.delAtEnd();
        l.displayList();

        l.insertAfterElement(3, 4);
        l.insertBeforeElement(2, 1);

        l.insertAtBeg(88);
        l.insertAtEnd(99);

        l.displayList();

        l.delAfterElement(4);
        l.delAfterElement(88);
        l.displayList();

        l.delBeforeElement(2);
        l.delBeforeElement(4);

        l.delBeforeElement(2);
        l.displayList();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    return 0;
}