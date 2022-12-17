#include<iostream>
using namespace std;
const int MAX = 5;

class Deque
{
    private:
        int array[MAX];
        int front;
        int rear;

    public:
        Deque()
        {
            front = rear = -1;
        }
        bool isFull()
        {
            return((front==0 && rear==MAX-1) || front==rear+1);
        }
        bool isEmpty()
        {
            return(front==-1);
        }
        void insertrear(int item)
        {
            if(isFull())
                cout<<endl<<"Queue full, couldn't insert "<<item<<" at rear end.";
            else
            {
                if(front==-1)
                {
                    front = 0;
                    rear = 0;
                }
                else if(rear == MAX-1)
                    rear = 0;
                else
                    rear++;
                array[rear] = item;
                cout<<endl<<"Inserted "<<item<<" at the rear end. At index "<<rear<<".";
            }
        }
        void insertfront(int item)
        {
            if(isFull())
                cout<<endl<<"Queue full, couldn't insert "<<item<<" at front.";
            else
            {
                if(rear==-1)
                {
                    rear = 0;
                    front = 0;
                }
                else if(front == 0)
                    front = MAX -1;
                else
                    front--;
                array[front] = item;
                cout<<endl<<"Inserted "<<item<<" at the front. At index "<<front<<".";
            }
        }
        int deleterear()
        {
            int element;
            if(isEmpty())
            {
                cout<<endl<<"Queue empty, couldn't delete from rear end.";
                return -1;
            }
            else
            {
                element = array[rear];
                cout<<endl<<"Deleted "<<element<<" from rear end.";
                if(front==rear)
                {
                    front = rear = -1;//reset
                    cout<<endl<<"Deque reset."<<endl;
                }
                else
                {
                    if(rear == 0)
                        rear = MAX-1;
                    else
                        rear--;
                } //CIRCULAR
            }
            return element;
        }
        int deletefront()
        {
            int element;
            if(isEmpty())
            {
                cout<<endl<<"Queue empty, couldn't delete from front.";
                return -1;
            }
            else
            {
                element = array[front];
                cout<<endl<<"Deleted "<<element<<" from front.";
                if(front==rear)
                {
                    front = rear = -1;//reset
                    cout<<endl<<"Deque reset."<<endl;
                }
                else
                {
                    if(front == MAX-1)
                        front = 0;
                    else
                        front++;
                } //CIRCULAR
            }
            return element;
        }
        void display()
        {
            int i;
            for(int j=0; j<20; j++)
            {
                cout<<"__";
            }
            cout<<endl<<"Front: "<<front<<endl;;
            cout<<"Rear: "<<rear<<endl;
            cout<<"Queue elements.."<<endl;
            if(front!=-1)//don't display for empty deque
            {
                for(i=front; i!=rear; i=(i+1)%MAX)
                {
                    cout<<array[i]<<endl;
                }
            cout<<array[i]<<endl;//for rear
            }
            for(int j=0; j<20; j++)
            {
                cout<<"__";
            }
        }
};

int main()
{
    Deque d;
    d.insertrear(1);
    d.insertrear(2);
    d.insertrear(3);
    d.insertrear(4);
    d.insertrear(5);

    d.deletefront();
    d.insertfront(6);
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.deleterear();
    d.display();
    return 0;
}
