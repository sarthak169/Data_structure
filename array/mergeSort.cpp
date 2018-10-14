//divide and conquer (merging)
#include<iostream>
using namespace std;

void merging(int *a,int p,int q,int r)
{
	int lt[20],rt[20];
	int i,j;
	int n1=q-p+1;
	int n2=r-q;
	for(i=1;i<=n1;i++)
	{
		lt[i]=a[p+i-1];
	}
	for(j=1;j<=n2;j++)
	{
		rt[j]=a[q+j];
	}
	lt[n1+1]=9999;
	rt[n2+1]=9999;
	i=1;
	j=1;
	for(int k=p;k<=r;k++)
	{
		if (lt[i]<=rt[j])
		{
			a[k]=lt[i];
			i++;
		}
		else
		{
			a[k]=rt[j];
			j++;
		}
	}
}

void mergeSort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merging(a,p,q,r);
	}
}

int main()
{
	int a[20];
	int n,p,r,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	p=1;
	r=n;
	mergeSort(a,p,r);
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<"  ";
	}
}
