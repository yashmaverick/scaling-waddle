#include<stdio.h>
int main()
{
	long long int i,count,j,n,k,test,t,min,p,q;
	scanf("%lld", &test);
	for(t=0;t<test;t++)
	{
		count=0;
		scanf("%lld %lld", &n, &k);
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld", &a[i]);
			if(i==0)
			{
				min=a[i];
			}
			else if(i<k)
			{
				if(a[i]<min)
				{
					min=a[i];
					j=i;
				}
			}
		}
		printf("%lld", min);
		if(n!=k)
		{
			printf(" ");
		}
		p=0;i=k;
		count=1;
		while(count<=n-k)
		{
			if(a[p]==min)
			{
				for(q=p+1;q<=i ;q++)
				{
					if(q==p+1)
					{
						min=a[q];
					}
					else if(a[q]<min)
					{
						min=a[q];
					}
				}
				printf("%lld", min);
				if(count<n-k)
				{
					printf(" ");
				}
				count++;i++;p++;
					if(p>=n||i>=n)
					{
						break;
					}
			}
			else
			{
				while(a[p]!=min)
				{
					if(a[i]<min)
					{
						min=a[i];
					}
					p++;i++;
					printf("%lld", min);
					if(p>=n||i>=n)
					{
						break;
					}
					if(count<n-k)
					{
						printf(" ");
					}
				count++;
				}
					if(p>=n||i>=n)
					{
						break;
					}

			}
		}		
		printf("\n");
	}
	return 0;
}


