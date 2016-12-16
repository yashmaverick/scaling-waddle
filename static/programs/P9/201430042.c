#include<stdio.h>
int n,w[1000007];
typedef struct node
{
	int data;
	int start;
	int end;
}node;
node a[1003];
void insert(int sum,int first,int last,int index)
{
	a[index].data=sum;
	a[index].start=first;
	a[index].end=last;
	return;
}
void sw(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return;
}
void sort()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
		{
			if(a[j].data>a[j+1].data)
			{
				sw(&a[j].data,&a[j+1].data);
				sw(&a[j].start,&a[j+1].start);
				sw(&a[j].end,&a[j+1].end);
			}
		}
	return;
}
void print()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].data);
		k=a[i].start;
		for(j=k;j<=a[i].end;j++)
			printf("%d\n",w[j]);
		printf("\n");
	}
	return;
}
int main()
{
	int c,i,j=0,m[1003],s=0,e;
	long long  int mod;
	scanf("%d%lld",&n,&mod);
	for(i=0;i<n;i++)
	{
		c=0;
		scanf("%d",&m[i]);
		for(j=j;j<m[i]+s;j++)
		{
			scanf("%d",&w[j]);
			c=c+w[j];
			c=(c%mod);
		}
		e=s+m[i]-1;
		insert(c,s,e,i);
		s=e+1;
	}
	sort();
	print();	
	return 0;
}
