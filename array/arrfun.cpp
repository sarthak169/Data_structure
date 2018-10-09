#include<iostream>
using namespace std;
class arr()
{
  int a[10];
  int size;
public:
  void read();
  void output();
  void insert();
  void delete();
  void search();

};
void arr::read()
{
  cout<<"Enter size of array";
  cin>>size;
  for(int i=0;i<size;i++)
  {
    cin>>a[i]
  }
}
void arr::output()
{
  for(int i=0;i<size;i++)
  {
    cout<<a[i]<<"\n";
  }
}
void arr::insert()
{
  int x;
  cout<<"How many elements do you wanna insert";
  cin>>x;
  while(x--)
  {
    int y,pos;
    cout<<"\n"<<"Enter the elements position and element";
    cin>>pos>>y;
    for(int i=size;i>=pos;i--)
      {
        a[i+1]=a[i];
      }
      a[pos]=y;
      size++;
  }
}
void arr::delete()
{
  int x;
  cout<<"How many elements fo you wanna delete?";
  cin>>x;
  while(x--)
    {
      cout<<"Enter the position of element";
      int pos;
      cin>>pos;
      for(int i=pos;i<size;i++)
        {
          a[i]=a[i+1];
        }
        size--;

    }
}
void arr::search()
{
  cout<<"Enter the element to be searched";
  int x,pos=-1;
  cin>>x;
  for(int i=0;i<size;i++)
  {
    if(a[i]==x)
    {
        pos=i;
        break;
    }
  }
  if(pos!=(-1))
  {
    cout<<"Yes the element is present at "<<pos<<" position";
  }
  else
  {
    cout<<"Element not found";
  }

}
int main()
{
  arr ob;
  int a,b;
  cout<<"Do you want to perform an operation ?\n press 1 for yes and 2 for no";
  cin>>a;
  if(a==1)
  {
    cout<<"Choose the operation\n1. Enter array\n2.output\n3.insert element\n4.delete\n5.search\n";
    cin>>b;
    switch(b)
    {
      case 1:
      ob.read();
      break;
      case 2:
      ob.output();
      break;
      case 3:
      ob.insert();
      break;
      case 4:
      ob.delete();
      break;
      case 5:
      ob.search();
      break;
      default:
      cout<<"Thankyou";
      break;
    }
  }
else if(a==2)
  {
    cout<<"Thankyou";
  }
  else()
  {
    cout<<"Invalid";
  }
  return 0;
}
