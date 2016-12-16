#include<stdio.h>
int a[100007],b[100007],stack[100007];
int depth,value;
void find(int start,int end,int count)
{
	if(start==end)
	{
		if(count>depth)
		{
			depth=count;
			value=a[start];
			return;
		}
		else if(count==depth&&a[start]<value)
		{
			value=a[start];
			return;
		}
	}
	else
	{
		int m=b[end];
		if(m==-1||m<start)
			find(start,end-1,count+1);
		else
		{
			find(start,m,count+1);
			if(m<end-1&&m>=start)
				find(m+1,end-1,count+1);
		}
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		depth=-1;
		value=1000009;
		int n,i,top=-1,inter;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		i=n-1;
		while(i>=0)
		{
			if(top==-1)
			{
				stack[++top]=i;
				i--;
			}
			else if(a[i]>=a[stack[top]])
			{
				stack[++top]=i;
				i--;
			}
			else
			{
				b[stack[top]]=i;
				top--;
				//	i++;
			}
		}
		while(top!=-1)
		{
			b[stack[top]]=-1;
			top--;
		}
		find(0,n-1,0);
		printf("%d %d\n",value,depth);
	}
	return 0;
}
