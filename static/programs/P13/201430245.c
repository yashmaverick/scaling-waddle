#include<stdio.h>
int first,last,max=0,req;
void depth(int a[],int b[],int c[],int dep,int m)
{
	int li,ri;
	li=b[m];
	ri=m-1;
	if(c[m]==-1)
	{
		return;
	}
	else
	{
		c[m]=-1;
		if(dep>=max)
		{
			if(a[m]<req||dep>max)
			{
				req=a[m];
			}
			max=dep;
		}
		if(li>0)
		{
			depth(a,b,c,dep+1,li);
		}
		if(ri>0)
		{
			depth(a,b,c,dep+1,ri);
		}
	}

}
void push(int d[],int ele)
{
	if(first==0&&last==0)
	{
		first++;
		last++;
		d[first]=ele;
	}
	else
	{
		last++;
		d[last]=ele;
	}
}
void pop(int d[])
{
	if(first==last)
	{
		first=0;
		last=0;
	}
	else
	{
		last--;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	int i,j,k,l,a[100002],b[100002],c[100002],d[100002];
	while(t--)
	{
		int n;
		first=0;
		last=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=0;
		}
		b[1]=-1;
		push(d,1);
		for(i=2;i<=n;i++)
		{
			if(last==0||a[i]>=a[d[last]])
			{
				push(d,i);
			}
			else
			{
				while(last!=0&&a[i]<a[d[last]])
				{
					pop(d);
				}
				push(d,i);
			}
			if(last==1)
			{
				b[i]=-1;
			}
			else
			{
				b[i]=d[last-1];
			}
		}
		/*	for(i=1;i<=n;i++)
			{
			printf("%d ",b[i]);
			}*/
		max=0;
		req=a[n];
		depth(a,b,c,0,n);
		printf("%d %d\n",req,max);
	}
	return 0;
}
