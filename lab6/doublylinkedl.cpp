#include<iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

class DoublyLinkedList
{
    private:
        node* head;
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
        node* createNewNode(int item)
        {
            node* newNode = new node;
            if(newNode == NULL)
                throw("Couldn't allocate space for new node.");
            newNode->data = item;
            newNode->prev = NULL;
            newNode->next = NULL;
            return newNode;
        }
        void addAtFront(int item)
        {
            node* newNode = createNewNode(item);
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            cout<<"Added "<<item<<" at the front."<<endl;
        }
        void addAtEnd(int item)
        {
            node* newNode = createNewNode(item);
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                node* temp = head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                newNode->prev = temp;
                temp->next = newNode;
            }
            cout<<"Added "<<item<<" at the end."<<endl;
        }
        void addAfterElement(int reference, int item)
        {
            node* newNode = createNewNode(item);
            node* temp = head;
            node* posttemp = NULL;
            while(temp->data!=reference)
            {
                if(temp->next==NULL)
                    throw("No such element in the list");
                temp  = temp->next;
            }
            posttemp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = posttemp;
            posttemp->prev = newNode;
            cout<<"Added "<<item<<" after the element "<<reference<<"."<<endl;
        }
        void addBeforeElement(int reference, int item)
        {
            node* newNode = createNewNode(item);
            if(head->data == reference)
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else
            {
                node* temp = head;
                node* pretemp = temp;
                while(temp->data!=reference)
                {
                    if(temp->next==NULL)
                        throw("No such element in the list");
                    pretemp = temp;
                    temp  = temp->next;
                }
                newNode->prev = pretemp;
                newNode->next = temp;
                pretemp->next = newNode;
                temp->prev = newNode;
                }
            cout<<"Added "<<item<<" before the element "<<reference<<"."<<endl;
        }
        int deleteAtFront()
        {
            int item;
            node* temp=head->next;
            item=head->data;
            temp->prev = NULL;
            delete head;
            head=temp;
            cout<<"Deleted "<<item<<" from the front."<<endl;
            return item;
        }
        int deleteAtEnd()
        {
            int item;
            node* temp=head;
            node* pretemp=temp;
            while(temp->next!=NULL)
            {
                pretemp = temp;
                temp=temp->next;
            }
            item=temp->data;
            pretemp->next=NULL;
            delete temp;
            cout<<"Deleted "<<item<<" from the end."<<endl;
            return item;
        }
        int deleteAfterElement(int reference)
        {
            int item;
            node* temp=head;
            node* store=NULL;
            while(temp->data!=reference)
            {
                if(temp->next==NULL)
                    throw("Can't perform deletion because no such element exists in the list.");
                temp=temp->next;
            }
            if(temp->next == NULL)
                throw("Can't perform deletion (deleteAfterElement) because the given element is the last element.");
            store = temp->next; //node to be deleted
            item = store->data;
            temp->next = store->next;
            store->next->prev = temp;
            delete store;
            cout<<"Deleted "<<item<<" after the element "<<reference<<"."<<endl;
            return item;
        }
        int deleteBeforeElement(int reference)
        {
            int item;
            if (head->data == reference)
                throw("Can't perform deletion (deleteBeforeElement) because the given element is the first element.");
            if(head->next->data == reference)
            {
                item = head->data;
                node* temp = head->next;
                temp->prev = NULL;
                delete head;
                head = temp;
            }
            else
            {
                node* pretemp=head;
                node* temp=pretemp;
                node* posttemp=temp;
                while(posttemp->data!=reference)
                {
                    if(posttemp->next==NULL)
                        throw("Can't perform deletion because no such element exists in the list.");
                    pretemp=temp;
                    temp=posttemp;
                    posttemp=posttemp->next;
                }
                item = temp->data;
                pretemp->next = posttemp;
                posttemp->prev = pretemp;
                delete temp;
            }
            cout<<"Deleted "<<item<<" before the element "<<reference<<"."<<endl;
            return item;
        }
        void display()
        {
            node* temp = head;
            cout<<"Elements.."<<endl;
            while(temp->next!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
        void displayReverse()
        {
            node* temp = head;
            while(temp->next!=NULL)
                temp=temp->next;
            cout<<"Elements in reverse order.."<<endl;
            while(temp->prev!=NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->prev;
            }
            cout<<temp->data<<endl;
        }
};

int main()
{
    DoublyLinkedList d;
    try
    {   
        d.addAtFront(1);
        d.addAtFront(2);
        d.addAtEnd(3);
        d.addAtEnd(4);
        d.addAfterElement(1, 5);
        d.addBeforeElement(1, 6);
        d.display();

        d.deleteAtFront();
        d.deleteAtEnd();
        d.display();
        
        d.deleteAfterElement(6);
        d.deleteBeforeElement(3);

        d.display();
        d.displayReverse();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    return 0;
}
