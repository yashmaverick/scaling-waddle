#include<stdio.h>
int a[100000],maxdepth=-1,min=1000000000,b[100000],c[100000],sz=0;
void push(int ele)
{
	c[sz]=ele;
	sz=sz+1;
	return;
}
int pop()
{
	int f;
        sz=sz-1;
	f=c[sz];
	c[sz]=0;
	return f;
}
int top()
{
	int j;
	j=c[sz-1];
	return j;
}

void func(int i,int j,int depth)
{
	if(i<j)
		return;
	if(i==j)
	{
		if(maxdepth<depth)
		{
			min=a[i];
			maxdepth=depth;
		}
		else if(maxdepth==depth)
		{
			if(min>a[i])
				min=a[i];
		}
		return;
	}
	if(b[i]==-1)
	func(i-1,j,depth+1);
	else
	{
	        func(b[i],j,depth+1);
		func(i-1,b[i]+1,depth+1);
	}
}
int main()
{
	int t,n,i,index,val;
	scanf("%d",&t);
	while(t--)
	{	
		sz=0;
		min=1000000000;
		maxdepth=-1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(n==1)
			printf("%d 0\n",a[0]);
		else
		{
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				push(i);
				b[i]=-1;
			}
			else if(i>0)
			{
				index=top();
				if(a[i]>a[index])
				{
					push(i);
					b[i]=i-1;
				}
				else if(a[i]<=a[index])
				{
					while(a[i]<=a[index]  && sz>0)
					{
						val=pop();
						index=top();
					}
					b[i]=b[val];
					push(i);
				}
			}
		}
		if(b[n-1]==-1)
			func(n-2,0,1);
		else
		{
		func(b[n-1],0,1);
		func(n-2,b[n-1]+1,1);
		}
		printf("%d %d\n",min,maxdepth);
		}
		for(i=0;i<n;i++)
		{
			b[i]=0;
		        c[i]=0;
		}
	}
	return 0;
}                
