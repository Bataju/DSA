#include<iostream>
using namespace std;

struct node
{
    int value;
    node* next;
};

class LinkedList
{
    private:
        node* head;
        int length;
    public:
        LinkedList()
        {
            head = NULL;
            length=0;
        }
        int getLength()
        {
            return length;
        }
        void addAtEnd(int item)
        {
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->value = item;
            newNode->next = NULL;
            if(head==NULL)//1st element
                head = newNode;
            else
            {
                node* temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            length++;
            cout<<"Added "<<item<<" at the end."<<endl;
        }
        void addAtFront(int item)
        {
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->value = item;
            newNode->next = head;
            head = newNode;
            length++;
            cout<<"Added "<<item<<" at the front."<<endl;
        }

        int deleteFromEnd()
        {
            int item;
            if(head == NULL)
                throw("Couldn't delete from an empty list.");
            if(head->next == NULL)//only 1 element
            {
                item = head->value;
                head = NULL;
            }
            else
            {
                node* preRear = head;
                node* Rear = preRear->next;
                while(Rear->next != NULL)
                {
                    preRear = preRear->next;
                    Rear = Rear->next;
                }
                item = Rear->value;
                preRear->next = NULL;
            }
            cout<<"Deleted "<<item<<" from the end."<<endl;
            return item;
        }
        int deleteFromFront()
        {
            int item;
            if(head == NULL)
                throw("Couldn't delete from an empty list.");
            if(head->next==NULL)
            {
                item = head->value;
                head = NULL;
            }
            else
            {
                item = head->value;
                head = head->next;
            }
            cout<<"Deleted "<<item<<" from the front."<<endl;
            return item;
        }
        void addAtIndex(int index, int item)
        {
            if(index>length)
                throw("Couldn't insert item at the specified index because the list is not long enough to have that index.");
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->value = item;
            newNode->next = NULL;

            int i=0;
            node* temp = head;
            if(index==0)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                while(i!=index-1)
                {
                    i++;
                    temp= temp->next;
                }
                node* storeNext = temp->next;
                temp->next=newNode;
                newNode->next = storeNext;
            }
            length++;
            cout<<"Added "<<item<<" at the index "<<index<<"."<<endl;
        }
        void addAfterElement(int elem, int value)
        {
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->value = value;
            newNode->next = NULL;

            node* temp = head;
            while(temp->value != elem)
            {
                if(temp->next==NULL)//no such element
                    throw("No such element in the list ");
                temp = temp->next;
            }
            node* storeNext = temp->next;
            temp->next = newNode;
            newNode->next = storeNext;
            length++;
            cout<<"Added "<<value<<" after the element "<<elem<<"."<<endl;
        }
        void addBeforeElement(int elem, int value)
        {
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->value = value;
            newNode->next = NULL;

            node* pretemp = head;
            node* temp = pretemp->next;
            if(head->value==elem)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                while(temp->value != elem)
                {
                    if(temp->next==NULL)//reached the end but elem not found
                        throw("No such element in the list ");
                    pretemp=pretemp->next;
                    temp = pretemp->next;
                }
                pretemp->next = newNode;
                newNode->next = temp;
            }
            length++;
            cout<<"Added "<<value<<" before the element "<<elem<<"."<<endl;
        }
        void display()
        {
            node* temp = head;
            cout<<"List elements.."<<endl;
            if(head == NULL)
                cout<<"Empty"<<endl;
            else
            {
                while(temp->next != NULL)
                {
                    cout<<temp->value<<endl;
                    temp = temp->next;
                }
                cout<<temp->value<<endl;
            }
        }
};

int main()
{
    LinkedList l;
    try
    {
        l.addAtIndex(0, 4);
        l.addAtIndex(1, 8);

        l.addBeforeElement(4, 12);
        l.addAfterElement(8, 16);

        l.display();

        l.deleteFromEnd();
        l.deleteFromFront();

        l.display();

        l.addAtFront(99);
        l.addAtEnd(98);

        l.display();
    }
    catch(const char* err)
    {
        cout<<err<<endl;
    }
    
    return 0;
}