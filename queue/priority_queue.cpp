#include<iostream>
#include<algorithm>
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
    void priority_queue_(int);
    void display();
};
void q::priority_queue_(int ele)
{
    int k=rear;
    for(k=rear;k>=front&&ele>arr[k];--k)
    {
        arr[k+1]=arr[k];
    }
    arr[k+1]=ele;
    ++rear;

}
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
        priority_queue_(ele);
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
    /*else                                      //to display whole queue
        for(int i=front;i<=rear;++i)
        cout<<arr[i]<<" ";*/
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

