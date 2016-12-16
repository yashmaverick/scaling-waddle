#include<stdio.h>

int a[100000],ar[100000],stack[100000],max,node=0;
void divide(int beg,int end,int root,int sum)
{
	if(beg==end)
	{
		sum+=1;
		if(sum>max)
		{
			max=sum;
			node=a[beg];
		}
		return;
	}
	else if(beg>end)
	{
		if(sum>max)
		{
			max=sum;
			node=a[beg];
		}
	}
	else
	{
	//	printf("%d %d %d %d\n",beg,ar[root]-1,ar[root],sum+1);
		divide(beg,ar[root]-1,ar[root],sum+1);
	//	printf("%d %d %d %d\n",ar[root]+1,root-2,root-1,sum+1);
		divide(ar[root]+1,root-2,root-1,sum+1);
	}
}

int main()
{
	//create stack
	int i,n,t,pos;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n==1)
		{
			printf("%d 0\n",a[0]);
			continue;
		}
		pos=0;
		for(i=n-1;i>=0;i--)
		{
			if(pos==0||a[i]>=a[stack[pos-1]])
				stack[pos++]=i;
			else
			{
				while(pos>0&&a[stack[pos-1]]>a[i])
				{
					pos--;
					ar[stack[pos]]=i;
				}
				stack[pos++]=i;
			}
		}
		while(pos>0)
		{
			pos--;
			ar[stack[pos]]=stack[pos]-1;
		}
		divide(0,n-2,n-1,0);
	/*	for(i=0;i<n;i++)
			printf("%d ",ar[i]);
		printf("\n");*/
		printf("%d %d\n",node,max);
	}
	return 0;
}
