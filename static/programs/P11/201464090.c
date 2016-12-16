#include<stdio.h>
long long int a[100000],sz=0,e[100000],sz1=0;
void push(long long int ele)
{
	a[sz]=ele;
	sz=sz+1;
	return;
}
long long int pop()
{
	long long int f;
	sz=sz-1;
	f=a[sz];
	a[sz]=0;
	return f;
}
long long int top()
{
	long long int j;
	j=a[sz-1];
	return j;
}
void push1(long long int ele)
{
	e[sz1]=ele;
	sz1=sz1+1;
	return;
}
long long int pop1()
{
	long long int f;
	sz1=sz1-1;
	f=e[sz1];
	e[sz1]=0;
	return f;
}
long long int top1()
{
	long long int j;
	j=e[sz1-1];
	return j;
}
int main()
{
	long long int x,max=0,i,l,index,val,n,b[100000],c[100000],d[100000],index1,val1;
	scanf("%lld",&n);
	while(n!=0)
	{
		max=0;sz=0;sz1=0;
		for(i=0;i<n;i++)
			scanf("%lld",&c[i]);
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
				if(c[i]>c[index])
				{
					push(i);		
					b[i]=i-1;
				}
				else if(c[i]<=c[index])
				{
					while(c[i]<=c[index]  && sz>0)
					{
						val=pop();
						index=top();
					}
					b[i]=b[val];
					push(i);
				}
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(i==n-1)
			{
				push1(i);
				d[i]=n;	
			}
			else if(i<n-1)
			{
				index1=top1();
				if(c[i]>c[index1])
				{
					push1(i);		
					d[i]=i+1;
				}
				else if(c[i]<=c[index1])
				{
					while(c[i]<=c[index1]  && sz1>0)
					{
						val1=pop1();
						index1=top1();
					}
					d[i]=d[val1];
					push1(i);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			x= (c[i]) *((d[i]-b[i])-1);
//                        printf(" d[i]=%lld , b[i]=%lld\n",d[i],b[i]);
			if(x>max)
				max=x;
		}
		printf("%lld\n",max);

		for(i=0;i<n;i++)
		{    a[i]=0;
			e[i]=0;
		}
		scanf("%lld",&n);
	}
	return 0;
}
