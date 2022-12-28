#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

class CircularLinkedList
{
private:
    node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    void insertAtEnd(int item)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
        {
            node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
        }
        newNode->next = head;
        cout << "Inserted " << item << " at the end." << endl;
    }
    void insertAtFront(int item)
    {
        node *newNode = new node;
        node *temp = head;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        head = newNode;
        cout << "Inserted " << item << " at the front." << endl;
    }
    int deleteFromEnd()
    {
        int item;
        node *temp = head;
        if (head == NULL)
            throw("List is empty, couln't delete item from the end.");
        if (head->next == head)
        {
            item = head->value;
            delete head;
            head = NULL;
        }
        else
        {
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            item = temp->next->value;
            delete temp->next;
            temp->next = head;
        }
        cout << "Deleted " << item << " from the end." << endl;
        return item;
    }
    int deleteFromFront()
    {
        int item;
        node *temp = head;
        if (head == NULL)
            throw("List is empty, couln't delete item from the end.");
        if (head->next == head)
        {
            item = head->value;
            delete head;
            head = NULL;
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            item = head->value;
            delete head;
            head = temp->next;
        }
        cout << "Deleted " << item << " from the front." << endl;
        return item;
    }
    void display()
    {
        node *temp = head;
        if (head == NULL)
            cout << "Empty.." << endl;
        else
        {
            cout << "List elements.." << endl;
            while (temp->next != head)
            {
                cout << temp->value << endl;
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    }
};

int main()
{
    CircularLinkedList c;
    try
    {
        c.display();
        c.insertAtEnd(1);
        c.deleteFromEnd();
        c.insertAtEnd(2);
        c.deleteFromFront();
        c.insertAtEnd(3);
        c.display();
        c.insertAtFront(4);
        c.insertAtFront(5);
        c.insertAtFront(6);
        c.display();
        c.deleteFromEnd();
        c.deleteFromFront();
        c.display();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    return 0;
}
