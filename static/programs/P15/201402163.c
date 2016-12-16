#include<stdio.h>
int main()
{
	long long int m,n,q,i,j,l,a[100000],o,k,x;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",&m,&q);
		i=0;
		while(i<m)
		{
			scanf("%lld",&a[i]);
			i++;
		}
		if(m==1)
		{
			printf("%lld\n",a[0]);
			continue;
		}
		i=1;
		j=a[0];
		k=0;
		x=0;
		while(i<m)
		{
			while(i<q)
			{
				if(a[i]<j)
				{
					j=a[i];
					k=i;
				}
				i++;

			}
			if((i==q)&&(x==0))
			{
				x=1;
				if(i!=m)
				{
				printf("%lld ",a[k]);
				}
				else
				{
					if(m-1==q)
					{
				         printf("%lld ",a[k]);
					}
					else
					{	
						printf("%lld",a[k]);
					}
				}
				continue;
			}
			if(a[i]<=a[k])
			{
				if(i==m-1)
				{
					printf("%lld",a[i]);
				}
				else
				{
					printf("%lld ",a[i]);
				}
				j=a[i];
				k=i;

			}
			else if(k==i-q)
			{
				o=k+1;
				j=a[o];
				k=o;
				o++;
				while(o<=i)
				{
					if(a[o]<j)
					{
						j=a[o];
						k=o;
					}
					o++;
				}
				if(i!=m-1)
				{

				printf("%lld ",j);
				}
				else
				{
				printf("%lld",j);
				}


			}
			else
			{
				if(i!=m-1)
				{
				printf("%lld ",j);
				}
				else
				{
				printf("%lld",j);
				}
			}

			i++;

		}
		printf("\n");
	}
	return 0;
}
