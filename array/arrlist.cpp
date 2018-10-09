#include<iostream>
using namespace std;
class list
{
    struct node
    {
        struct node *next;
        int value;

    };
    struct node* start[2];
    struct node* ptr;
    struct node* last;
    struct node *new_node;


  public:
    list()
    {
      start[0]=NULL;
      start[1]=NULL;

    }
  //  int i;

    void create()
    {


      int i=0,x=0;
      for(i=0;i<2;i++)
      {

        cout<<"enter the element for linked list"<<i+1;
        cin>>x;

      while(x!=-1)
      {


      new_node=new node;
      if(start[i]==NULL)
      {
        new_node->value=x;
        new_node->next=NULL;
        start[i]=new_node;
        last=new_node;
      }
      else{
      new_node = new node;
      new_node->value = x;
      new_node->next = start[i];
      start[i] = new_node;
    }
      cin>>x;

    }
  }
    }

  /*  void beg(int x)
    {
      if(start[i] == NULL)
      {
        create(x);
        return;
      }
      new_node = new node;
      new_node->value = x;
      new_node->next = start->next;
      start[i]->next = new_node;

    }
    void end(int x)
    {
      if(start[i] == NULL)
      {
        create(x);
        return;
      }
      new_node=new node;
      new_node->value = x;
      new_node->next = NULL;
      last->next = new_node;
      last=new_node;
    }*/
    void disp()
    {
      int i = 0;
      for(i=0;i<2;i++)
      {
        cout<<"Elements of linked list "<<i+1<<"are:\n";
      ptr=start[i];
      while(ptr!=NULL)
      {
        cout<<ptr->value<<endl;
        ptr = ptr->next;
      }
    }
    }


};
int main()
{
  int x;
  list ob;
  int c;
  cout<<"Enter The Choice \n1.Create The List\n2.Insert At BEGINING\n3.Insert At END\n4.Display\n";
  cin>>c;
  while(1)
  {
  switch(c)
  {
    case 1:

      ob.create();
      break;
  /*  case 2:
      cout<<"enter the element\n";
      cin>>x;
      ob.beg(x);
      break;
   case 3:
      cout<<"enter the element\n";
      cin>>x;
      ob.end(x);
      break;*/
    case 4:
      ob.disp();
      break;
    default:
        cout<<"Enter Valid Number\n";
        break;
  }
  cout<<"Enter The Choice \n1.Create The List\n2.Insert At BEGINING\n3.Insert At END\n4.Display\n";
  cin>>c;
}
return 0;
}
