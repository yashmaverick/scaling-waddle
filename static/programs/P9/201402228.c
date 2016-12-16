#include<stdio.h>
int first;
int after;
int sum=0;
typedef struct node{
	int val;
	int start;
	int last;
}node;
node a[1002];
int b[1000003];
void push(int w,int mod,int j)
{
		b[j]=w;
	        sum=(sum%mod+w%mod)%mod;
	return;
}
void selectionsort(int n)
{
	int i,j,swap1,swap2,swap3;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i].val)>(a[j].val))
			{
				swap1=a[i].val;
				swap2=a[i].start;
				swap3=a[i].last;
				a[i].val=a[j].val;
				a[i].start=a[j].start;
				a[i].last=a[j].last;
				a[j].val=swap1;
				a[j].start=swap2;
				a[j].last=swap3;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].val);
		for(j=(a[i].start);j<=(a[i].last);j++)
		{
			printf("%d\n",b[j]);
		}
		printf("\n");
	}
	return;
}
int main()
{
	int n,mod,m,i,j,w;
	scanf("%d%d",&n,&mod);
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%d",&m);
		if(i==0)
		{
			a[0].start=0;
			first=a[0].start;
			a[0].last=m-1;
			after=a[0].last;
		}
		if(i!=0)
		{
			first=after+1;
			after=first+m-1;
		}
		int j;
		int k=after; 
		for(j=first;j<=k;j++)
		{
			scanf("%d",&w);
			push(w,mod,j);
		}
		a[i].val=sum;
		a[i].start=first;
		a[i].last=after;
	}
	selectionsort(n);
	return 0;
}


