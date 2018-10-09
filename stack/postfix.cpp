#include <iostream>
#include <stack>
#include <string>
#include<stdio.h>
#include <ctype.h>
using namespace std;

int priority(char a) {
    int temp;
    if (a == '^')
        temp = 3;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 1;
    else
    return -1;

	return temp;
}
int main()
{
	stack<char> postfix;
	stack<char> infix;
	infix.push('E');
	postfix.push('E');
	char arr[50];

	string inf;
	cout<<"Enter the INFIX operation\n";
	cin>>inf;
	int i,l=inf.length();
	char n;
//	cout<<l;
	for(i=0;i<l;i++)
	{
	//	if((inf[i]>='a'&& inf[i]<='z')||(inf[i]>='A'&&inf[i]<='Z'||(inf[i]>=g&&inf[i]<=h)))
		if((inf[i] >= 'a' && inf[i] <= 'z')||(inf[i] >= 'A' && inf[i] <= 'Z'))
				postfix.push(inf[i]);

		else if(inf[i]=='(')

			infix.push('(');

		else if(inf[i] == ')')
		{
			while(infix.top()!='E'&&infix.top()!='(')
			{
				n=infix.top();
				infix.pop();
				postfix.push(n);
			//	infix.pop();
			}
			if(infix.top()=='(')
				{
					n=infix.top();
					infix.pop();
				}
		}
		else
		{
			while(infix.top()!='E' && priority(inf[i]) <=priority(infix.top()))
			{
				n=infix.top();
				infix.pop();
				postfix.push(n);
			}

			if(inf[i]!='('&&inf[i]!=')')
				infix.push(inf[i]);
		}
	}
	while(infix.top()!='E')
	{
		n=infix.top();
		infix.pop();
		postfix.push(n);
	}
	i=0;
	while(postfix.top()!='E')
	{
		//cout<<postfix.top();
		arr[i]=postfix.top();
		i++;
		postfix.pop();
	}
	int j;
	for(j=i-1;j>=0;j--)
	cout<<arr[j];
	return 0;

}
