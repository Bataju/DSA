#include<iostream>
using namespace std;

const int MAX = 50;

struct nodename
{
    int data, next;
}node[MAX];

int avail = 0, list = -1;

void initialOrdering()
{
    int i;
    for(i=0; i<MAX-1; i++)
    {
        node[i].next = i+1;
    }
    node[MAX-1].next = -1;
}

int getNode(int value)
{
    if(avail == -1)
        throw("OVERFLOW");
    int index = avail;
    node[index].data = value;
    avail = node[index].next;
    return index;
}

void insertAtBeg(int value)
{
    int index = getNode(value);
    node[index].next = list;
    list = index;
    cout<<value<<" inserted at beginning at index "<<index<<endl;
}

void insertAtEnd(int value)
{
    if(list==-1)
        insertAtBeg(value);
    else
    {
        int index = getNode(value);
        int i = list;
        while(node[i].next!=-1)
        {
            i = node[i].next;
        }
        node[i].next = index;
        node[index].next = -1;
        cout<<value<<" inserted at the end at index "<<index<<endl;
    }
}

void insertAfter(int reference, int value)
{
    int index = getNode(value);
    int i = list, temp;
    while(node[i].data!=reference)
    {
        if(node[i].next == -1)
            throw("No such element in the list");
        i = node[i].next;
    }
    temp = node[i].next;
    node[i].next = index;
    node[index].next = temp;
    cout<<value<<" inserted after "<<reference<<" at index "<<index<<endl;
}

int freeNode(int index)
{
    node[index].next = avail;
    avail = index;
    return index;
}

int deleteAtBeg()
{
    if(list==-1)
        throw("UNDERFLOW");
    int delItem, temp;
    delItem = node[list].data;
    temp = node[list].next;
    freeNode(list);
    cout<<delItem<<" deleted from beginning from index "<<list<<endl;
    list = temp;
    return delItem;
}

int deleteAtEnd()
{
    if(list==-1)
        throw("UNDERFLOW");
    int delItem;
    int i = list;
    if(node[i].next == -1)
        delItem = deleteAtBeg();
    else
    {
        int preI=i;
        while(node[i].next != -1)
        {
            preI = i;
            i = node[i].next;
        }
        node[preI].next = -1;
        delItem = node[i].data;
        freeNode(i);
        cout<<delItem<<" deleted from the end from index "<<i<<endl;
    }
    return delItem;
}

int deleteAfter(int reference)
{
    if(list==-1)
        throw("UNDERFLOW");
    int delItem, delIndex;
    int i=list;
    while(node[i].data != reference)
    {
        if(node[i].next == -1)
            throw("No such element in the list");
        i = node[i].next;
    }
    delIndex = node[i].next;
    delItem = node[delIndex].data;
    node[i].next = node[delIndex].next;
    freeNode(delIndex);
    cout<<delItem<<" deleted after "<<reference<<" from index "<<delIndex<<endl;
    return delItem;
}

void display()
{
    int i = list;
    while(node[i].next != -1)
    {
        cout<<node[i].data<<endl;
        i = node[i].next;
    }
    cout<<node[i].data<<endl;
}

int main()
{
    try
    {
        initialOrdering();
        insertAtBeg(99);
        insertAtBeg(2);
        insertAtBeg(3);
        insertAtBeg(0);
        display();
        deleteAtBeg();
        deleteAtEnd();
        insertAfter(2, 4);
        insertAtEnd(5);
        insertAtEnd(6);
        display();

        deleteAtBeg();
        deleteAtEnd();
        deleteAfter(4);
        display();
    }
    catch(const char* err)
    {
        cout<<err<<endl;
    }
    return 0;
}
