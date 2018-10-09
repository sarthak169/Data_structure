/*#include<iostream>
using namespace std;
int fib(int n)
{
  if(n==1||n==0)
    return n;
  else
  {
    return(fib(n-1)+fib(n-2));
  }
}
int main()
{
  int n,i=0;
  cout<<"Enter number\n";
  cin>>n;
  while(i<n)
  {
    int h=fib(i);
    cout<<h<<endl;
    i++;
  }
return 0;
}

*/
#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

int main()
{
    int n,i=0,a=0,b=1,next=1;
    cout<<"how mamy numbers\n";
    cin>>n;

    while(i<n)
    {
      if(i<=1)
        next=i;
      else
      {
        next=b+a;
        b=next;
        a=b;
      }
      cout<<next<<endl;
      i++;
    }
    return 0;
}
