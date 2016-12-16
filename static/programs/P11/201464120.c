#include<stdio.h>
#include<stdlib.h>
#define gi(x) scanf("%lld",&x);
#define FOR(i,n) for(i=0;i<n;i++)
#define he(i,n)	 for(i=n-1;i>=0;i--)
int main()
{
	while(1)
	{
		long long int n;
		gi(n);
		if(n==0)
			break;
		long long int i;
		long long int *a,*stack,*cat;
		a=(long long int *)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		stack=(long long int *)malloc(n*sizeof(long long int));
		cat=(long long int *)malloc(n*sizeof(long long int));
		long long int top=-1,t;
	    FOR(i,n)
		{
			while(top!=-1)
			{
				if(a[i] <= a[stack[top]])
				{
					top--;
				}
				else
					break;
			}
			long long int t;
			if(top==-1)
				t=-1;
			else
				t=stack[top];
			cat[i]=i-t-1;
			stack[++top]=i;
		}
		while(top!=-1)
			top--;
		he(i,n)
		{
			while(top!=-1)
			{
				if(a[i]<=a[stack[top]])
					top--;
				else
					break;
			}
			if(top==-1)
				t=n;
			else
				t=stack[top];
			cat[i]+=t-i-1;
			stack[++top]=i;
		}
		long long int max=0;
		FOR(i,n)
		{
			cat[i]=a[i]*(cat[i]+1);
			if(cat[i]>max)
				max=cat[i];
		}
		printf("%lld\n",max);
	}
	return 0;
}