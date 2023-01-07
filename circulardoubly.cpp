#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *prev;
    node *next;
};

template <class T>
class DoublyLinkedList
{
private:
    node<T> *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }
    node<T> *createNewNode(T item)
    {
        node<T> *newNode = new node<T>;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->data = item;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
    void addAtFront(T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head == NULL)
        {
            head = newNode;
            head->prev = head->next = head;
        }
        else
        {
            node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;

            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
        cout << "Added " << item << " at the front." << endl;
    }
    void addAtEnd(T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head == NULL)
        {
            head = newNode;
            head->prev = head->next = head;
        }
        else
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Added " << item << " at the end." << endl;
    }
    void addAfterElement(T reference, T item)
    {
        node<T> *newNode = createNewNode(item);
        node<T> *temp = head;
        node<T> *posttemp = NULL;
        while (temp->data != reference)
        {
            if (temp->next == head)
                throw("No such element in the list");
            temp = temp->next;
        }
        posttemp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = posttemp;
        posttemp->prev = newNode;
        cout << "Added " << item << " after the element " << reference << "." << endl;
    }
    void addBeforeElement(T reference, T item)
    {
        node<T> *newNode = createNewNode(item);
        if (head->data == reference)
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
        else
        {
            node<T> *temp = head;
            node<T> *pretemp = temp;
            while (temp->data != reference)
            {
                if (temp->next == head)
                    throw("No such element in the list");
                pretemp = temp;
                temp = temp->next;
            }
            newNode->prev = pretemp;
            newNode->next = temp;
            pretemp->next = newNode;
            temp->prev = newNode;
        }
        cout << "Added " << item << " before the element " << reference << "." << endl;
    }
    T deleteAtFront()
    {
        T item;
        node<T> *temp = head;
        node<T> *storeHead = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        item = head->data;
        head = head->next;
        temp->next = head;
        head->prev = temp;
        delete storeHead;
        cout << "Deleted " << item << " from the front." << endl;
        return item;
    }
    T deleteAtEnd()
    {
        T item;
        node<T> *temp = head;
        node<T> *pretemp = temp;
        while (temp->next != head)
        {
            pretemp = temp;
            temp = temp->next;
        }
        item = temp->data;
        pretemp->next = head;
        head->prev = pretemp; 
        delete temp;
        cout << "Deleted " << item << " from the end." << endl;
        return item;
    }
    T deleteAfterElement(T reference)
    {
        T item;
        node<T> *temp = head;
        node<T> *store = NULL;
        while (temp->data != reference)
        {
            if (temp->next == head)
                throw("Can't perform deletion because no such element exists in the list.");
            temp = temp->next;
        }
        if (temp->next == head)
            throw("Can't perform deletion (deleteAfterElement) because the given element is the last element.");
        store = temp->next; // node to be deleted
        item = store->data;
        temp->next = store->next;
        store->next->prev = temp;
        delete store;
        cout << "Deleted " << item << " after the element " << reference << "." << endl;
        return item;
    }
    T deleteBeforeElement(T reference)
    {
        T item;
        if (head->data == reference)
            throw("Can't perform deletion (deleteBeforeElement) because the given element is the first element.");
        if (head->next->data == reference)
        {
            node<T> *temp = head;
            node<T> *storeHead = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            item = head->data;
            head = head->next;
            temp->next = head;
            head->prev = temp;
            delete storeHead;
        }
        else
        {
            node<T> *pretemp = head;
            node<T> *temp = pretemp;
            node<T> *posttemp = temp;
            while (posttemp->data != reference)
            {
                if (posttemp->next == NULL)
                    throw("Can't perform deletion because no such element exists in the list.");
                pretemp = temp;
                temp = posttemp;
                posttemp = posttemp->next;
            }
            item = temp->data;
            pretemp->next = posttemp;
            posttemp->prev = pretemp;
            delete temp;
        }
        cout << "Deleted " << item << " before the element " << reference << "." << endl;
        return item;
    }
    void display()
    {
        node<T> *temp = head;
        cout << "Elements.." << endl;
        while (temp->next != head)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    void displayReverse()
    {
        node<T> *temp = head;
        node<T> *storetemp = NULL;
        while (temp->next != head)
            temp = temp->next;
        storetemp = temp;
        cout << "Elements in reverse order.." << endl;
        while (temp->prev != storetemp)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    DoublyLinkedList<int> d;
    try
    {
        d.addAtFront(1);
        d.addAtEnd(2);
        d.addAtEnd(5);
        d.addBeforeElement(5, 4);
        d.addAfterElement(2, 3);

        d.display();
        d.displayReverse();

        d.deleteAtFront();
        d.deleteAtEnd();

        d.display();
        d.displayReverse();

        d.addBeforeElement(2, 0);
        d.addAfterElement(4, 6);

        d.display();
        d.displayReverse();

        d.deleteBeforeElement(4);
        d.deleteAfterElement(2);

        d.display();
        d.displayReverse();

        d.deleteBeforeElement(0);
        d.deleteAfterElement(6);

    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
    return 0;
}
