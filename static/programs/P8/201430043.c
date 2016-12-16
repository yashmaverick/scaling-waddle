#include<stdio.h>
#include<string.h>
#define max 1000000007
long long int n;

long long int Power(long long int x,long long int y)
{
	long long int temp;
	if(y==0)
		return 1;
	temp=Power(x,y/2)%n;
	if(y%2==0)
		return (temp*temp)%n;
	else
		return (((x*temp)%n)*temp)%n;
}

int main()
{
	long long int T,u,d,m,i,j,k,p;
	long long count,count1,count2,count3,tot,countt;
	scanf("%lld",&T);
	for(p=0;p<T;p++)
	{
		countt=count=count2=count3=count1=0;
		scanf("%lld",&u/*,&d,&m,&n*/);
		scanf("%lld",&d);
		scanf("%lld",&m);
		scanf("%lld",&n);
		long long int l=n,z=0;
		if(u<n)
			l=u+1;
		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				for(k=0;k<l;k++)
				{

					tot=((Power(i,d)%n+Power(j,d)%n)%n+Power(k,d)%n)%n;
					if(tot==m)
					{
						z++;
						count1=((u-i)/n) +1; 
						count2=((u-j)/n) +1;
						count3=((u-k)/n) +1;
						countt=((count1*count2)%max * count3)%max;
						count=(countt+count)%max;
					}
				}
			}
		}
		if(u<n)
			count=z;
		printf("%lld\n",count);
	}
	return 0;
}
