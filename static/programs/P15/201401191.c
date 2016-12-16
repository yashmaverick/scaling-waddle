#include<stdio.h>
typedef long long int ll;
int main()
{
	int tes;
	scanf("%d",&tes);
	while(tes--)
	{
		ll a[10110],n,k,j,i,min;
		scanf("%Ld %Ld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%Ld",a+i);
		}
		ll tmp=0;
		min=a[0];
		for(i=0;i<k;i++)
		{
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		if(k==n)
		{
		printf("%Ld",min);
		}
		else
		{
			printf("%Ld ",min);
		}
		for(i=k;i<n;i++)
		{
			if(min==a[tmp]&&a[i]>=min)
			{
				min=a[i];
				for(j=tmp+1;j<=i;j++)
				{
					if(a[j]<min)
					{
						min=a[j];
					}
				}
				if(i==n-1)
				{
					printf("%Ld",min);
				}
				else
				{
					printf("%Ld ",min);
				}
			}
			else if(a[i]<min)
			{
				min=a[i];
				if(i==n-1)
				{
					printf("%Ld",min);
				}
				else
				{
					printf("%Ld ",min);
				}

			}
			else
			{
				if(i==n-1)
				{
					printf("%Ld",min);
				}
				else
				{
					printf("%Ld ",min);
				}
			}
			tmp++;
		}
		printf("\n");
	}
}
