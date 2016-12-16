#include<stdio.h>
void push(long long int val,long long int stack[],long long int *last)
{
	stack[*last]=val;
	(*last)++;
}
long long int pop(long long int stack[],long long int *last)
{
	if(*last==0)
		return -1;
	else
	{
		(*last)--;
		return stack[*last];
	}
}
long long int top(long long int stack[],long long int *last)
{
	if(*last==0)
		return -1;
	else
		return stack[*last-1];
}
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int i,a[n],stack[n+1],last=0,k,p,area[n],area1[n],area2[n],b[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(i==0)
				push(i,stack,&last);
			else 
			{
				if(a[top(stack,&last)]<=a[i])
				{
					push(i,stack,&last);
				}
				else
				{
					k=top(stack,&last);
					while(a[top(stack,&last)]>a[i]&&top(stack,&last)!=-1)
					{
//					printf("f");
						p=pop(stack,&last);
						area1[p]=(k-p+1)*a[p];
//printf("%d ",area1[p]);			
					}
					push(i,stack,&last);
				}
			}
		}
		if(top(stack,&last)!=-1)
		{
			p=top(stack,&last);
			while(top(stack,&last)!=-1)
			{
				k=pop(stack,&last);
				area1[k]=(p-k+1)*a[k];
//printf("%d ",area1[p]);
			}
		}
//for(i=0;i<n;i++)
//printf("%d ",area1[i]);

		for(i=n-1;i>=0;i--)
			b[i]=a[n-i-1];
		for(i=0;i<n;i++)
		{
			if(i==0)
				push(i,stack,&last);
			else
			{
				if(b[top(stack,&last)]<=b[i])
				{
					push(i,stack,&last);
				}
				else
				{
					k=top(stack,&last);
					while(b[top(stack,&last)]>b[i]&&top(stack,&last)!=-1)
					{
						p=pop(stack,&last);
						area2[p]=(k-p)*b[p];
					}
					push(i,stack,&last);
				}
			}
		}
		if(top(stack,&last)!=-1)
		{
			p=top(stack,&last);
			while(top(stack,&last)!=-1)
			{
				k=pop(stack,&last);
				area2[k]=(p-k)*b[k];
			}
		}
//for(i=0;i<n;i++)
//printf("%d ",area2[i]);



		long long int max=0;
		for(i=0;i<n;i++)
		{
		area[i]=area1[i]+area2[n-i-1];
//		printf("%d ",area[i]);
		}
		for(i=0;i<n;i++)
		{
			if(area[i]>max)
				max=area[i];
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
