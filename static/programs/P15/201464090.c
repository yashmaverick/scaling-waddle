#include<stdio.h>
int c[10000],sz=0,start=0;
void push(int ele)
{
	c[sz]=ele;
	sz=sz+1;
	return;
}
int pop()
{
	sz=sz-1;
	c[sz]=0;
	return;
}
int top()
{
	int j;
	if(sz>0)
	j=c[sz-1];
	else
		j=0;
	return j;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		sz=0;start=0;
		int index,i,n,k,a[10000],j,poi=0,ind,p;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(k==1)
		{
			for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
			printf("%d\n",a[n-1]);
		}
		else
		{
		for(i=0;i<n;i++)
		{
			index=top();
			if(i==0)
				push(i);	
			else if(i<(k-1))
			{
				if(a[i]>=a[index])
					push(i);
				else if(a[i]<a[index])
				{
					while(a[i]<a[index] && sz>0)
					{
						pop();
						index=top();
					}
					push(i);
				}
			}
			if(i>=(k-1))
			{
				index=top();
				if(a[i]>=a[index])
					push(i);
				else if(a[i]<a[index])
				{
			        while(a[i]<a[index] && sz>start )
				{
						pop();
						index=top();
				}
				push(i);
				}
				ind=c[start];
				if(i==n-1)
					printf("%d\n",a[ind]);
				else
					printf("%d ",a[ind]);
				if(a[poi]==a[ind])
					start++;
				poi++;

			}
		}
		}
		for(i=0;i<n;i++)
		{
			a[i]=0;
			c[i]=0;
		}
	}
	return 0;
}

