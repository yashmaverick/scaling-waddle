#include<stdio.h>
int n;
long long int po(long long int ba,long long int ex);
int main()
{
	long long int p,q,r,u,d,count=0,c1=0,c2=0,c3=0;
	int l,t,m;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%lld%lld%d%d",&u,&d,&m,&n);
		count=0;
		int flag=0;
		if(u<=n)
		{
			flag=1;
		}
		if(flag==1)
		{
		for(p=0;p<=u;p++)
			{
				for(q=0;q<=u;q++)
				{
					for(r=0;r<=u;r++)
					{
						if(((((po(p,d))%n)+((po(q,d))%n)+((po(r,d))%n))%n)==m)
							count++;
					}
				}
			}
		}
		else
		{
			for(p=0;p<n;p++)
			{
				for(q=0;q<n;q++)
				{
					for(r=0;r<n;r++)
					{
						c1=((u-p+n)/n)%1000000007;
						c2=((u-q+n)/n)%1000000007;
						c3=((u-r+n)/n)%1000000007;
						if(((((po(p,d))%n)+((po(q,d))%n)+((po(r,d))%n))%n)==m)
							count=((count%1000000007)+((((c1*c2)%1000000007)*c3)%1000000007)%1000000007);
					}
				}
			}
		}
		printf("%lld\n",count%1000000007);
	}
	return 0;
}
long long int po(long long int ba,long long int ex)
{
	long long int x;
	if(ba==0 && ex==0)
		return 1;
	if(ex==0)
		return 1;
	x=po(ba,ex/2)%n;
	if(ex%2==0)
		return (x%n*x%n)%n;
	else
		return ((ba%n*x%n)%n*x%n)%n;
}

