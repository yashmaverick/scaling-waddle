#include<stdio.h>
long long int q[1000000];
int main()
{
	long long int head,tail,a[100000],n,k,i,t;
	scanf("%lld",&t);
	while(t--)
	{
		head=0;tail=-1;
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(tail==-1 || i<=k)
			{
				while( tail>=head && a[q[tail]]>a[i] )
					tail--;
				q[++tail]=i;
			}
			else
			{
				printf("%lld ",a[q[head]]);
				if(tail-head+1==k || (i-q[head])>=k)
					head++;
				if(a[q[tail]]<=a[i])
					q[++tail]=i;
				else
				{
					while( tail>=head && a[q[tail]]>a[i] )
						tail--;
					q[++tail]=i;
				}
			}
		}
		printf("%lld\n",a[q[head]]);
	}
	return 0;
}
