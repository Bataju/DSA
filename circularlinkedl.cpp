#include <iostream>
using namespace std;

template <class T>
class node
{
    public:
        T value;
        node *next;
};

template <class T>
class CircularLinkedList
{
private:
    node<T>* head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    node<T>* createNewNode(T item)
    {
        node<T> *newNode = new node<T>;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = NULL;
        return newNode;
    }
    void insertAtEnd(T item)
    {
        node<T>* newNode = createNewNode(item);
        if (head == NULL)
            head = newNode;
        else
        {
            node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
        }
        newNode->next = head;
        cout << "Inserted " << item << " at the end." << endl;
    }
    void insertAtFront(T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head == NULL)
            head = newNode;
        else
        {
            node<T>* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
        }
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << item << " at the front." << endl;
    }
    T deleteFromEnd()
    {
        T item;
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
            node<T> *temp = head;
            node<T> *preTemp = temp;
            while (temp->next != head)
            {
                preTemp = temp;
                temp = temp->next;
            }
            item = temp->value;
            preTemp->next = head;
            delete temp;
        }
        cout << "Deleted " << item << " from the end." << endl;
        return item;
    }
    T deleteFromFront()
    {
        T item;
        node<T> *temp = head;
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
        node<T> *temp = head;
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
    CircularLinkedList<int> c;
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
