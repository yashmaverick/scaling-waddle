#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int a[100000],b[100000],c[100000],i,j,t,val,p,q;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
		c[b[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		a[i]=c[a[i]];
	}

	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&p,&q);	
		p=c[p];
		q=c[q];
		for(i=0;i<n;i++)
		{
			if((q>a[i]&&p<a[i]) || (q<a[i]&&p>a[i]))
			{
				val=a[i];
				break;
			}
			if(q == a[i])
			{
				val=a[i];
				break;
			}
			if(p == a[i])
			{
				val=a[i];
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(c[b[i]]==val)
			{
				printf("%lld\n",b[i]);
				break;
			}
		}
	}
	return 0;
}
