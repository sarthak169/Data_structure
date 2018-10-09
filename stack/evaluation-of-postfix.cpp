#include<iostream>
#include<string.h>
using namespace std;

int stk[20],top=-1;
void push(int n)
{
    top=top+1;
    stk[top]=n;
}
int pop()
{
    int c;
    c=stk[top];
    top=top-1;
    return c;
}
main()
{
    char exp[20],*e;
    int num,n1,n2,n3;
cout<<"Enter the string";
cin>>exp;
e=exp;

while(*e!='\0')
{
    if(isdigit(*e))
    {
        num=*e-48;
        cout<<num;
        push(num);
    }
    else
    {
        n1=pop();
        n2=pop();
        switch(*e)
            {
            case '+':
                n3=n1+n2;
                break;
            case '-':
                n3=n1-n2;
                break;
            case '*':
                n3=n1*n2;
                break;
            case '/':
                n3=n1/n2;
                break;
            }
            push(n3);
    }
e++;

}

cout<<pop();


}
