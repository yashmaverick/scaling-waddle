#include<stdio.h>
long long int maxarea(long long int a[],long long int n)
{
	long long int stack[n];
	long long int nis=0,max=0,tp,awt,i=0,k;
	while(i<n)
	{
		if(nis==0||a[stack[nis-1]]<=a[i])
		{
			stack[nis]=i;
			nis++;
			i++;
		}
		else
		{
			tp=stack[nis-1];
			nis--;
			if(nis==0)
			{
				k=i;
			}
			else if(nis!=0)
			{
				k=i-stack[nis-1]-1;
			}
			awt=a[tp]*k;
			if(max<awt)
			{
				max=awt;
			}
		}
	}
	while(nis!=0)
	{
		tp=stack[nis-1];
		nis--;
		if(nis==0)
		{
			k=i;
		}
		else if(nis!=0)
		{
			k=i-stack[nis-1]-1;
		}
		awt=a[tp]*k;
		if(max<awt)
		{
			max=awt;
		}
	}
	return max;
}
int main()
{
	long long int n,t,i;
	t=1;
	while(t!=0)
	{
	        scanf("%lld",&n);
		if(n==0)
		{
			break;

		}
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",maxarea(a,n));
	}
	return 0;
}
