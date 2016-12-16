#include<stdio.h>

long long int poi;

void push(long long int a[],long long int value)
{
	a[poi]=value;
	poi++;
}

void pop(long long int a[])
{
	poi--;
}

int main()
{
	while(1)
	{
		long long int n,i,var,flag=0,top,ans=0,j;
		poi=0;
		scanf("%lld",&n);
		if(n==0)
		{
			break;
		}
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&var);
			if(poi==0)
			{
//				printf("Yes\n");
				push(a,var);
//				printf("%d\n",poi);
				continue;
			}
			if(a[poi-1]>=var)
			{
				push(a,var);
			}
			else
			{
				while(a[poi-1]<var)
				{
					ans=ans+(n-1)-i;
					pop(a);
					if(poi==0)
						break;
				}
				push(a,var);
			}
			if(poi>=3)
			{
				top=a[poi-1];
				for(j=poi-2;j>=0;j--)
				{
					if(a[j]>top)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				{
					ans=ans+j;
					flag=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


