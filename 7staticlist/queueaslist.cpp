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
    node[index].next = -1;
    return index;
}

void enqueue(int value)
{
    int index = getNode(value);
    if(list==-1)
    {
        node[index].next = list;
        list = index;
    }
    else
    {
        int i = list;
        while(node[i].next!=-1)
        {
            i = node[i].next;
        }
        node[i].next = index;
        node[index].next = -1;
    }
    cout<<value<<" enqueued."<<endl;
}

int freeNode(int index)
{
    node[index].next = avail;
    avail = index;
    return index;
}

int dequeue()
{
    if(list==-1)
        throw("UNDERFLOW.");
    int delItem, temp;
    delItem = node[list].data;
    temp = node[list].next;
    freeNode(list);
    list = temp;
    cout<<delItem<<" dequeued."<<endl;
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
        enqueue(1);
        enqueue(2);
        enqueue(3);
        display();
        dequeue();
        dequeue();
        display();
    }
    catch(const char* err)
    {
        cout<<err<<endl;
    }
    return 0;
}