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
class LinkedList
{
private:
    node<T> *head;

public:
    LinkedList()
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
    void addAtEnd(T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head == NULL)
            head = newNode;
        else
        {
            node<T> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Added " << item << " at the end." << endl;
    }
    void addAtFront(T item)
    {
        node<T> *newNode = createNewNode(item);
        newNode->next = head;
        head = newNode;
        cout << "Added " << item << " at the front." << endl;
    }
    void addAfterElement(T elem, T item)
    {
        node<T> *newNode = createNewNode(item);
        node<T> *temp = head;
        while (temp->value != elem)
        {
            if (temp->next == NULL)
                throw("No such element in the list ");
            temp = temp->next;
        }
        node<T> *storeNext = temp->next;
        temp->next = newNode;
        newNode->next = storeNext;
        cout << "Added " << item << " after the element " << elem << "." << endl;
    }
    void addBeforeElement(T elem, T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head->value == elem)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node<T> *pretemp = head;
            node<T> *temp = head;
            while (temp->value != elem)
            {
                if (temp->next == NULL) // reached the end but elem not found
                    throw("No such element in the list ");
                pretemp = temp;
                temp = temp->next;
            }
            pretemp->next = newNode;
            newNode->next = temp;
        }
        cout << "Added " << item << " before the element " << elem << "." << endl;
    }
    T deleteFromEnd()
    {
        int item;
        if (head == NULL)
            throw("Couldn't delete from an empty list.");
        if (head->next == NULL) // only 1 element
        {
            item = head->value;
            delete head;
            head = NULL;
        }
        else
        {
            node<T> *pretemp = head;
            node<T> *temp = head;
            while (temp->next != NULL)
            {
                pretemp = temp;
                temp = temp->next;
            }
            item = temp->value;
            delete temp;
            pretemp->next = NULL;
        }
        cout << "Deleted " << item << " from the end." << endl;
        return item;
    }
    T deleteFromFront()
    {
        int item;
        if (head == NULL)
            throw("Couldn't delete from an empty list.");
        if (head->next == NULL)
        {
            item = head->value;
            delete head;
            head = NULL;
        }
        else
        {
            node<T> *temp = head->next;
            item = head->value;
            delete head;
            head = temp;
        }
        cout << "Deleted " << item << " from the front." << endl;
        return item;
    }
    T deleteAfterElement(T element)
    {
        T item;
        node<T> *temp = head;
        node<T> *storeNodeToBeDeleted;
        while (temp->value != element)
        {
            if (temp->next == NULL)
                throw("No such element in the list.");
            temp = temp->next;
        }
        storeNodeToBeDeleted = temp->next;
        item = temp->next->value;
        temp->next = temp->next->next;
        delete storeNodeToBeDeleted;
        cout << "Deleted " << item << " after the element " << element << "." << endl;
        return item;
    }
    void display()
    {
        node<T> *temp = head;
        cout << "List elements.." << endl;
        if (head == NULL)
            cout << "Empty" << endl;
        else
        {
            while (temp->next != NULL)
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
    LinkedList<int> l;
    try
    {
        l.addAtEnd(1);
        l.addAtEnd(2);
        l.addAtFront(6);
        l.addAtFront(7);
        l.display();

        l.addAfterElement(1, 12);
        l.addBeforeElement(6, 14);
        l.display();

        l.deleteFromFront();
        l.deleteFromEnd();
        l.deleteAfterElement(1);
        l.display();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }
    return 0;
}