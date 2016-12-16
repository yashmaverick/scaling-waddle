#include<stdio.h>
int level=0;
int ind;
int b[100001];
void f(int a[],int n)
{
	int c[1000001],i,top;
	i=n-1;
	top=-1;
	while(i>=0)
	{
		if(top==-1||a[i]>=a[c[top]])
		{
			top++;
			c[top]=i;
			i--;
		}
		else
		{
			while(a[i]<a[c[top]])
			{
				b[c[top]]=i;
				top--;
				if(top==-1)
					break;
			}
		}
	}
}
void func(int a[],int start,int end)
{
	int temp1,temp2,temp3,i;
	if(end==start)
		ind=start;
	else if(end>start)
	{
	//	for(i=end-1;a[i]>a[end] && i>=start;i--);
		level++;
		temp1=level;
		if(b[end]+1<=end-1)
		func(a,b[end]+1,end-1);
		temp2=level;
		temp3=ind;
		level=temp1;
		if(b[end]>=start)
		func(a,start,b[end]);
		if(level<temp2)
		{
			level=temp2;
			ind=temp3;
		}
	}
}
int main()
{
	int a[100021],i,j,n,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		f(a,n);
		func(a,0,n-1);
		printf("%d %d\n",a[ind],level);
		level=0;
		ind=0;
	}
	return 0;
}
