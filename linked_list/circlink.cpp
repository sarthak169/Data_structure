#include<iostream>
using namespace std;
class circ
{
	struct node
	{
		int value;
		struct node*next;
	};
	int num;
	struct node*start;
	struct node*save;
	struct node*new_node;
	struct node*ptr;
	public:
	circ()
	{
		start=NULL;
	}
	void create(int x)
	{
		num=x;
		while(num!=-1)
		{
			new_node=new node;
			new_node->value=num;
			new_node->next=start;
			start=new_node;
			cout<<"Element";
			cin>>num;
		}

	}
	void beg_insert(int a)
	{
		num=a;
		ptr=start;
		do
		{
			if(ptr->next=start)
			{
			break;}
			ptr=ptr->next;
		}
			while(ptr!=start);
			new_node=new node;
			new_node->value=num;
			new_node->next=start;
			start->next=new_node;
			ptr->next=new_node;

	}
	void end_insert(int a)
	{
		num=a;
		ptr=start;
		do{
			if(ptr->next==start)
			{
				break;
			}
			ptr=ptr->next;
		  }
		  while(ptr!=start);
		  new_node =new node;
		  new_node->value;
		  new_node->next=start;
		  ptr->next=new_node;
		  save=new_node;
		cout<<"element";
		cin>>num;

	}
	void disp()
	{
		ptr=start;
		cout<<ptr->value<<"\n";
		ptr=ptr->next;
		while(ptr!=start)
		{
			cout<<ptr->value<<"\n";
			ptr=ptr->next;
		}
	}
	void del(int x)
	{
		ptr=last->next;
		struct node* copy;
		int flag=0;
		do
	  {
				if(ptr->value==x)
				{
					flag=1;
					break;
				}
				copy=ptr;
				ptr=ptr->next;
		} while(ptr!=last->next);
		if(ptr==last)
		{
			copy->next=last->next;
			last=copy;
		}
		else if(ptr==last->next)
		{
			last->next=ptr->next;
		}
		else
		{
			copy->next=ptr->next;
		}

	}
};
int main()
{
	circ ob;
	int x,y;
	cout<<"Where do you want to insert element\n1. Begg\n2.End\n3.display\n4.create\n5.Delete";
	cin>>y;
	while(y<6&&y>0)
	{

	if(y==1)
	{
			cout<<"Enter Element\n";
	cin>>x;
	while(x!=-1)
	{

		ob.beg_insert(x);
	cout<<"number";
	cin>>x;
	}
	}
	else if(y==2)
	{
			cout<<"Enter Element\n";
	cin>>x;
		ob.end_insert(x);
	}
	else if(y==3)
	{
		ob.disp();
	}
	else if(y==4)
	{
		cout<<"Enter Element\n";
	cin>>x;
		ob.create(x);
	}
	else if(y==5)
	{
		cout<<"Enter Element You Want To Delete\n";
		cin>>x;
		ob.del(x);
	}
	cout<<"Where do you want to insert element\n1. Begg\n2.End\n3.display\n4.create\n5.Delete";
	cin>>y;
}
	return 0;
}
