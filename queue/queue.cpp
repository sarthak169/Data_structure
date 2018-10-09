#include<iostream>
using namespace std;
class q
{
    int arr[50];
    int rear;
    int front;
    int max;
public:
    q()
    {
        rear=-1;
        front=-1;
        max=5;
    }
    void enq();
    void deq();
    void display();
};
void q::enq()
{
    if(rear==max-1)
        cout<<"Overflow"<<endl;
    else if(rear==-1&&front==-1)
    {
        cout<<"Enter element: ";
        int ele;
        cin>>ele;
        ++rear;
        ++front;
        arr[rear]=ele;
    }
    else
    {
        cout<<"Enter element: ";
        int ele;
        cin>>ele;
        ++rear;
        arr[rear]=ele;
    }
}
void q::deq()
{
    if(rear==-1&&front==-1)
        cout<<"Underflow"<<endl;
    else if(front==rear)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        ++front;
    }
}
void q::display()
{
    if(rear==-1&&front==-1)
        cout<<"Empty q"<<endl;
    else
       cout<<arr[front]<<endl;
}
int main()
{
    q obj;
    int ch;
    do
    {
        cout<<"Enter 1 to enq,2 to deq,3to display,0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.enq();
            break;
        case 2:
            obj.deq();
            break;
        case 3:
            obj.display();
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
