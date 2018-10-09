#include<iostream>
using namespace std;
class queue_ll
{
    struct node
    {
        int data;
        node *next;
    };
    node *rear;
    node *front;
    node *new_node;
    node *save_node;
    node *ptr;
public:
    queue_ll()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue();
    void dequeue();
    void display();
};
void queue_ll::enqueue()
{
    rear=NULL;
    front=NULL;
    cout<<"Enter element to be inserted(-1 to terminate): ";
    int ele;
    cin>>ele;
    while(ele!=-1)
    {
        if(rear==NULL)
        {
            new_node=new node;
            new_node->data=ele;
            new_node->next=rear;
            rear=new_node;
            front=new_node;
            save_node=new_node;
        }
        else
        {
            new_node=new node;
            new_node->data=ele;
            new_node->next=save_node->next;
            rear=new_node;
            save_node->next=new_node;
            save_node=new_node;
        }
        cout<<"Enter element to be inserted(-1 to terminate): ";
        cin>>ele;
    }
}
void queue_ll::dequeue()
{
    if(front==NULL)
        cout<<"Underflow"<<endl;
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
        cout<<"Element removed"<<endl;
    }
    else
    {
        front=front->next;
        cout<<"Element removed"<<endl;
    }
}
void queue_ll::display()
{
    if(front==NULL)
        cout<<"Empty Queue"<<endl;
    else
        cout<<front->data<<endl;
}
int main()
{
    queue_ll obj;
    int ch;
    do
    {
        cout<<"Enter 1 to enq,2 to deq,3to display,0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.enqueue();
            break;
        case 2:
            obj.dequeue();
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
