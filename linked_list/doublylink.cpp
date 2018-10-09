#include<iostream>
using namespace std;
class list
{
	struct node
	{
		int value;
		struct node* next;
		struct node* prev;
	};
	//struct node* prev;
	struct node* start;
	struct node* last;
	struct node* new_node;
	struct node* ptr;
	struct node* copy;
	int num;
	public:
		list()
		{
			start=NULL;
		//	prev=NULL;

		}

		void create(int x)
		{
			if(start==NULL)
			{
				new_node=new node;
				new_node->value=x;
				start=new_node;
				new_node->next=NULL;
				new_node->prev=NULL;
				last=start;
			}
			else
				beg(x);
		}

		void beg(int x)
		{
			ptr=start;
			new_node=new node;
			new_node->value=x;
			new_node->next=start;
			ptr->prev=new_node;
			start=new_node;
		}

		void end(int x)
		{
//			ptr=start;
//			while(ptr->next!=NULL)
//			{
//				ptr=ptr->next;
//			}
//			new_node =new node;
//			new_node->value=x;
//			new_node->next=NULL;
//			new_node->prev=ptr;
//			ptr->next=new_node;
			new_node = new node;
			new_node->value = x;
			new_node->next = NULL;
			new_node->prev = last;
			last->next = new_node;
			last = new_node;
		}

		void disp()
		{
			cout<<"List Is:"<<endl;
			ptr=start;
			while(ptr!=NULL)
			{
				cout<<ptr->value<<endl;
				ptr=ptr->next;
			}
		}

		void after(int x,int pos)
		{
			ptr=start;
			int flag=0;
			while(ptr!=NULL)
			{
				if(ptr->value==pos)
				{
					flag=1;
					break;
				}
				ptr=ptr->next;
			}

			if(flag==1)
			{
				if(ptr->next==NULL)
				{
					new_node=new node;
					new_node->value=x;
					new_node->next=NULL;
					new_node->prev=ptr;
					ptr->next=new_node;
					last=new_node;
					return ;
				}
				new_node=new node;
				new_node->value=x;
				new_node->next=ptr->next;
				new_node->prev=ptr;
				ptr->next=new_node;
			}
			else
			{
				cout<<"Element not found\n";
				return;
			}
		}
		void del(int x)
		{
			ptr=start;
			int flag=0;
			while(ptr!=NULL)
			{
				if(ptr->value==x)
					{	flag=1;
						break;
					}
					copy=ptr;
				ptr=ptr->next;
			}
			if(flag==0)
			{
				cout<<"Element Not Found";
				return;
			}
			if(ptr->next==NULL&&ptr->prev==NULL)
			{
				start=NULL;
				delete ptr;
				return;
			}
			{
				if(ptr->next==NULL)
				{
					copy->next=NULL;
					return;
				}
				else if(ptr==start)
				{
					start=ptr->next;
					ptr->next->prev=NULL;
				}
				else
				{
				ptr->next->prev=copy;
				copy->next=ptr->next;
				}
			}
		}
/*		void ins_bef(int x,int pos)
		{
			int flag=0;
			ptr=start;
			//int flag=0;
			while(ptr!=NULL)
			{
				if(ptr->value==pos)
				{
					flag=1;
					break;
				}
				ptr=ptr->next;
			}
			if(flag==0)
			{
				cout<<"Element not found\n";
				return;
			}
			else
			{
				if(ptr->prev==NULL)

			}
		}
		*/
};

int main()
{
	list ob;
	cout<<"Which operation do you want to perform?\n1.Create list\n2.Enter at begining\n3.Insert at End\n4.Display list\n5.Insert After\n6.Delete\n";
	int a,x,y;
	cin>>a;
	while(1)
	{
		switch(a)
		{
		 	case 1:
		 		cout<<"Enter The Element You Want To Enter\n";
			 	cin>>x;
			 	ob.create(x);
		 		break;
		 	case 2:
			 	cout<<"Enter The Element You Want To Enter\n";
			 	cin>>x;
			 	ob.beg(x);
				break;
			case 3:
				cout<<"Enter The Element You Want To Enter\n";
			 	cin>>x;
			 	ob.end(x);
			 	break;
			case 4:
				ob.disp();
				break;
			case 5:
				cout<<"Enter The Element You Want To Enter\n";
			 	cin>>x;
			 	cout<<"Enter Element After Which you Want To insert\n";
			 	cin>>y;
			 	ob.after(x,y);
			 	break;
			case 6:
				cout<<"Enter Element You Want To Delete\n";
				cin>>x;
				ob.del(x);
				break;

			default:
			cout<<"Enter Valid Input\n";
			break;

		}
	cout<<"Which operation do you want to perform?\n1.Create list\n2.Enter at begining\n3.Insert at End\n4.Display list\n5.Insert After\n6.Delete\n";
				cin>>a;

	}
	return 0;

}
