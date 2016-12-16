#include<stdio.h>
#include<string.h>
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		char s[100000];
		long long i,j,a,b,c,d;
		a=1001;
		b=-1003;
		c=2;
		scanf("%s",s);
		d=strlen(s);
		long long e[d+1];
		e[0]=0;
		for(i=0;i<d;i++)
		{
			if(s[i]=='J')
				e[i+1]=e[i]+a;
			else if(s[i]=='M')
				e[i+1]=e[i]+b;
			else
				e[i+1]=e[i]+c;
		}
//		for(i=0;i<=d;i++)
//		{
//			printf("%lld\n",e[i]);
//		}

		long long min=10000000, max=-10000000;
		long long sum=0,z;
		long long y[1000000]={0};
		for(i=0;i<=d;i++)
		{
			if(e[i]<min)
				min=e[i];
			if(e[i]>max)
				max=e[i];
		}
		for(j=0;j<=d;j++)
		{
			z=e[j]-min;
			y[z]++;
		}
		for(j=0;j<=max-min;j++)
		{
			sum+=(y[j]*(y[j]-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
