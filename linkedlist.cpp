#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

class LinkedList
{
private:
    node *head;
    int length;

public:
    LinkedList()
    {
        head = NULL;
        length = 0;
    }
    int getLength()
    {
        return length;
    }
    void addAtEnd(int item)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = NULL;
        if (head == NULL) // 1st element
            head = newNode;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
        cout << "Added " << item << " at the end." << endl;
    }
    void addAtFront(int item)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = head;
        head = newNode;
        length++;
        cout << "Added " << item << " at the front." << endl;
    }
    void addAtIndex(int index, int item)
    {
        if (index > length)
            throw("Couldn't insert item at the specified index because the list is not long enough to have that index.");
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = item;
        newNode->next = NULL;

        int i = 0;
        node *temp = head;
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            while (i != index - 1)
            {
                i++;
                temp = temp->next;
            }
            node *storeNext = temp->next;
            temp->next = newNode;
            newNode->next = storeNext;
        }
        length++;
        cout << "Added " << item << " at the index " << index << "." << endl;
    }
    void addAfterElement(int elem, int value)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = value;
        newNode->next = NULL;

        node *temp = head;
        while (temp->value != elem)
        {
            if (temp->next == NULL) // no such element
                throw("No such element in the list ");
            temp = temp->next;
        }
        node *storeNext = temp->next;
        temp->next = newNode;
        newNode->next = storeNext;
        length++;
        cout << "Added " << value << " after the element " << elem << "." << endl;
    }
    void addBeforeElement(int elem, int value)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->value = value;
        newNode->next = NULL;

        if (head->value == elem)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node *pretemp;
            node *temp = head;
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
        length++;
        cout << "Added " << value << " before the element " << elem << "." << endl;
    }
    int deleteFromEnd()
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
            node *preTemp;
            node *temp = head;
            while (temp->next != NULL)
            {
                preTemp = temp;
                temp = temp->next;
            }
            item = temp->value;
            delete temp;
            preTemp->next = NULL;
        }
        length--;
        cout << "Deleted " << item << " from the end." << endl;
        return item;
    }
    int deleteFromFront()
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
            node *temp = head->next;
            item = head->value;
            delete head;
            head = temp;
        }
        length--;
        cout << "Deleted " << item << " from the front." << endl;
        return item;
    }
    int deleteAtIndex(int index)
    {
        int item, i = 0;
        node *temp = head;
        node *preTemp;
        if (index >= length)
            throw("Couldn't delete item at the specified index because the list is not long enough to have that index.");
        if (head == NULL)
            throw("Couldn't delete from an empty list.");
        if (index == 0)
        {
            temp = head->next;
            item = head->value;
            delete head;
            head = temp;
        }
        else
        {
            while (i < index)
            {
                i++;
                preTemp = temp;
                temp = temp->next;
            }
            item = temp->value;
            preTemp->next = temp->next;
            delete temp;
        }
        length--;
        cout << "Deleted " << item << " at index " << index << endl;
        return item;
    }
    int deleteAfterElement(int element)
    {
        int item;
        node *temp = head;
        node *storeNodeToBeDeleted;
        while (temp->value != element)
        {
            if (temp->next == NULL)
                throw("No such element in the list");
            temp = temp->next;
        }
        storeNodeToBeDeleted = temp->next;
        item = temp->next->value;
        temp->next = temp->next->next;
        delete storeNodeToBeDeleted;
        length--;
        cout << "Deleted " << item << " after the element " << element << endl;
        return item;
    }
    int deleteBeforeElement(int element)
    {
        int item;
        node *temp = head;
        node *preTemp = NULL;
        node *prePreTemp = NULL;
        if (head->value == element)
            throw("The element given is the first element, so cannot delete the element before it.");
        if(element == head->next->value)
        {
            delete temp;
            head = temp->next;
        }
        else
        {
            while (temp->value != element)
            {
                prePreTemp = preTemp;
                preTemp = temp;
                temp = temp->next;
            }
            prePreTemp->next = temp;
            item = preTemp->value;
            delete preTemp;
        }
        length--;
        cout << "Deleted " << item << " before the element " << element << endl;
        return item;
    }
    void display()
    {
        node *temp = head;
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
    LinkedList l;
    try
    {
        l.addAtEnd(1);
        l.addAtEnd(2);
        l.addAtEnd(3);
        l.addAtEnd(4);
        l.addAtEnd(5);
        l.addAtFront(6);
        l.addAtFront(7);
        l.addAtFront(8);
        l.addAtFront(9);
        l.addAtFront(10);
        l.display();

        l.addAtIndex(0, 11);
        l.addAfterElement(1, 12);
        l.addBeforeElement(5, 13);
        l.addAfterElement(5, 14);
        l.display();

        l.deleteFromFront();
        l.deleteFromEnd();
        l.deleteAtIndex(5);
        l.deleteAfterElement(2);
        l.deleteBeforeElement(7);
        l.display();
    }
    catch (const char *err)
    {
        cout << err << endl;
    }

    return 0;
}