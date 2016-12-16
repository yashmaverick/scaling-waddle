#include<stdio.h>
int a[100100],b[100100],c[100100],end=0,max,maxv,y;
void push(int v)
{
	b[end]=v;
	end++;
}
void pop()
{
	if(end!=0)
		end--;
}
int top()
{
	if(end==0)
		return -1;
	return b[end-1];
}
void check(int n)
{
	int i,g;
	y=0;
	push(n-1);
	for(i=n-2;i>=0;i--)
	{
		g=top();
		while(g!=-1 && a[i]<a[g])
		{
			c[g]=i;
			pop();
			g=top();
			y=1;
		}
		push(i);
	}
	while((top())!=-1)
	{
		c[top()]=-1;
		pop();
	}
}
void recur(int start,int end1,int count)
{
	int min;
	if(start>end1)
		return;
	else if(start==end1)
	{
		min=a[start];
		if(count>=max)
		{
			if(maxv>min || count>max)
			{
				max=count;
				maxv=min;
			}
		}
		return;
	}
	else
	{
		recur(start,c[end1],count+1);
		if(c[end1]>=start)
			recur(c[end1]+1,end1-1,count+1);
		else
			recur(start,end1-1,count+1);
	}
}
int main()
{
	int t,n,j,i;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
	//	if(n=0)
	//	{
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			max=-1;
			maxv=0;
			end=0;
			check(n);
		//	for(i=0;i<n;i++)
		//		printf("%d ",c[i]);
		//	printf("\n");
			recur(0,n-1,0);
			printf("%d %d\n",maxv,max);
	//	}
	}
	return 0;
}
