#include<stdio.h>
int main()
{
	int test,r;
	scanf("%d",&test);
	for(r=0;r<test;r++)
	{
	int n,i,p,k,t,j;
	long long int min,a[100001],l[100001];
	min=1000000001;
	scanf("%d %d",&n, &k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<k ;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			l[0]=i;
		}
	}
	p=0;
	t=0;
	i=k;
	while(i<n)	
	{
		if(l[t]<i-k+1)
		{
			min=1000000001;
			for(j=i;j>t;j--)
				{
					if(min>a[j])
					{
						min=a[j];
						l[t+1]=j;
					}
				}
		}
		else
		{
			if(min>a[i])
			{
			min=a[i];
		        l[t+1]=i;
			}
			else
			{
			l[t+1]=l[t];
			}
		}
		i++;
		t++;
	}
						
	 
	for(i=0;i<=n-k;i++)
	{
		printf("%lld",a[l[i]]);
		if(i<n-k)
		{
		printf(" ");
		}
	}
		printf("\n");
	}
	return 0;
}
