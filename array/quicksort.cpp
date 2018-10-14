#include<iostream>
using namespace std;
int part(int *a,int p,int r)
{
  int piv=a[r];
  int i,j=p-1,temp;
  for(i=p;i<r;i++)
  {
    if(a[i]<=piv)
    {
      j++;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  temp=a[r];
  a[r]=a[j+1];
  a[j+1]=temp;
  return j+1;
};

void quick(int *a,int p,int r)
{
  int q;
  if(p<r)
  {
    q=part(a,p,r);
    quick(a,p,q-1);
    quick(a,q+1,r);
  }
};
void display(int *a,int r)
{
  for (int i=0;i<r;i++)
    cout<<a[i]<<endl;
}
int main()
{
  int n;
  cout<<"Enter size of array\n";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter elements of array\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  quick(a,0,n-1);
  display(a,n);
}
