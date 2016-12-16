// Rounak Mundra
#include<stdio.h>
#include<stdlib.h>
#define max 99999
#define gi(x) scanf("%lld",&x);
typedef long long int ll;
ll distance[10005];
ll prime_storage[10200];
ll four_digits[4];
void seive()
{
	ll i,j;
	prime_storage[0]=1;
	prime_storage[1]=1;
	for(i=2;i<=10000;i++)
	{
		if(prime_storage[i]==0)
		{
			for(j=2*i;j<=10000;j=j+i)
			{
				prime_storage[j]=1;
			}
		}
	}
}
int main()
{
	ll test,i,j,k,g;
	/*prime_storage[0]=1;
	prime_storage[1]=1;
	for(i=2;i<=10000;i++)
	{
		if(prime_storage[i]==0)
		{
			for(j=2*i;j<=10000;j=j+i)
			{
				prime_storage[j]=1;
			}
		}
	}*/
		seive();
	/*for(i=2;i<10000;i++)
	{
		if(prime_storage[i]==0)
			printf("%lld ",i);
	}*/
	gi(test);
	for(g=0;g<test;g++)
	{
		ll a,b;
		gi(a);
		gi(b);
		ll flag=0;
		for(i=0;i<=10000;i++)
		{
			distance[i]=-max;
		}
		ll front=0;
		ll rear=0;
		ll queue[10005];
		distance[a]=0;
		queue[rear++]=a;
		while(front < rear)
		{
			ll n = queue[front];
			for(i=3;i>=0;i--)
			{
				ll fd=n;
				four_digits[3]=fd%10;
				fd/=10;

				four_digits[2]=fd%10;
				fd/=10;

				four_digits[1]=fd%10;
				fd/=10;

				four_digits[0]=fd%10;
				for(j=0;j<=9;j++)
				{
					if(i==0)
					{
						if(j==0)
						{
							j++;
						}
					}
						//j++;
					four_digits[i]=j;
					ll hello=four_digits[0]*1000 + four_digits[1]*100+four_digits[2]*10 + four_digits[3];
					if(hello>=1000 && hello<=10000)
					{
						if(prime_storage[hello]==0)
						{
							if(distance[hello]==-max)
							{
								distance[hello]=distance[n]+1;
								queue[rear++]=hello;
								if(hello==b)
								{
									flag=1;
									break;
								}
							}
						}
					}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
			front++;
		}
		if(distance[b]==-max)
		{
			printf("Impossible\n");
		}
		else
			printf("%lld\n",distance[b]);
	}
	return 0;
}	