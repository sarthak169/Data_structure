#include<iostream>
using namespace std;
class link
{
	struct node
	{
		int value;
		struct node*next;
	};
	int num,h=0;
	struct node*start;
	struct node*save;
	struct node*new_node;
	public:
		link()
		{
			start=NULL;
		}
	void create(int x)
	{
		if(start==NULL)
		{
			new_node=new node;
			new_node->value=x;
			start=new_node;
			new_node->next=NULL;
			save=new_node;
		}
	}

	void beg_insert(int x)
	{
	    num=x;
	    while(num>=0)
        {
					if(start==NULL)
					{
						create(x);
						return;
					}

				 	new_node=new node;
					new_node->value=num;
					new_node->next=start;
					start=new_node;
					cin>>num;
        }
	}
	void end_insert(int x)
	{

	    num=x;
	    	while(num>=1)
			{
				new_node=new node;
				new_node->value=num;
				new_node->next=NULL;
				save->next=new_node;
				save=new_node;
			cout<<"Enter Element\n";
			cin>>num;
      }
	}

		void display()
		{
			struct node *ptr;
			ptr=start;
			cout<<"Elements in list are:-\n";
			while(ptr!=NULL)
			{
				cout<<ptr->value<<"\n";
				ptr=ptr->next;
			}
		//	cout<<"jhjhkn";
		}
		void insert_next(int x)
		{
			num=x;
			while(num>=1)
			{
			int k;
			cout<<"After which element?";
			cin>>k;
			struct node*ptr;
			ptr=start;
			while(ptr!=NULL)
			{
				if(ptr->value==k)
				{
					break;
				}
				ptr=ptr->next;
			}
			new_node=new node;
			new_node->value=num;
			new_node->next=ptr->next;
			ptr->next=new_node;
			cout<<"Enter element";
			cin>>num;
			}
		}
		void insert_back(int x)
		{
			num=x;
			while(num>=1)
			{
			struct node*copy;
			copy=NULL;
			cout<<"Before which element";
			int k;
			cin>>k;
			struct node*ptr;
			ptr=start;
			while(ptr!=NULL)
			{
				if(ptr->value==k)
				{
					break;
				}
				copy=ptr;
				ptr=ptr->next;
			}
			if(copy==NULL)
			{
				beg_insert(num);
				break;
			}
			new_node=new node;
			new_node->value=num;
			new_node->next=ptr;
			copy->next=new_node;
			cout<<"Enter element";
			cin>>num;
		}
		}
		void del(int x)
		{
			int flag=0;
			struct node* copy;
			struct node* ptr;
			ptr=start;
			while(ptr!=NULL)
			{
				if(ptr->value==x)
				{
					flag=1;
					break;
				}
				copy=ptr;
				ptr=ptr->next;
			}
			if(flag==1)
			{
			if(ptr->next==NULL)
			{
				copy->next=NULL;
				return;
			}
			else if(ptr==start)
				start=ptr->next;
			else
				copy->next=ptr->next;
		}
		else
			cout<<"Element not found";
	}

};
int main()
{
	link obj;
	int x,h;
	cout<<"Enter element at begining or end?\n1.Begining\n2.End.\n3.Next\n4.Before\n5.Display\n6.delete\n7.create\n";
	cin>>h;
	while(h<8)
	{

	if(h==1)
	{
		cout<<"Enter element\n";
	cin>>x;
	obj.beg_insert(x);
	}
	else if(h==2)
	{
		cout<<"Enter element\n";
		cin>>x;
		obj.end_insert(x);
	}
	else if(h==3)
	{
		cout<<"Enter Element\n";
		cin>>x;
		obj.insert_next(x);

	}
	else if(h==4)
	{
		cout<<"Enter Element";
		cin>>x;
		obj.insert_back(x);
	}
	else if(h==5)
	{
		obj.display();
	}
	else if(h==6)
	{
		cout<<"Enter Element You Want To Delete\n";
		cin>>x;
		obj.del(x);
	}
	else if(h==7)
	{
		cout<<"Enter Element";
		cin>>x;
		obj.create(x);
	}

	cout<<"Enter element at begining or end?\n1.Begining\n2.End.\n3.Next\n4.Before\n5.Display\n6.delete\n7.create\n";
	cin>>h;

	}
	obj.display();
	return 0;
}
