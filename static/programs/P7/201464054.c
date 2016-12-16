#include<stdio.h>
#include<limits.h>
int main()
{
	int t,n,i,a[1000000],diff,min,max,b[1000000];
	unsigned long long int ct,p,q;
	//p=500000;	q=999999;
	//printf ("%llu %llu\n",ULLONG_MAX,p*q);
	scanf ("%d",&t);
	while (t--)
	{
		scanf ("%d",&n);
		ct=0;	min=INT_MAX;	max=INT_MIN;
		for (i=0;i<1000000;i++)
			b[i]=0;
		for (i=0;i<n;i++)
		{
			scanf ("%d",&a[i]);
			if (a[i]<min)
				min=a[i];
			else if (a[i]>max)
				max=a[i];
		}
		for (i=0;i<n;i++)
			b[a[i]-min]++;
		diff=max-min;
		for (i=0;i<=diff;i++)
		{
	//		printf ("bi=%d ",b[i]);
			if (b[i]>1)
			{
				if (b[i]%2==0)
				{
					p=b[i]/2;	q=b[i]-1;
					ct+=(p*q);
				}
				else	
				{
					p=(b[i]-1)/2;	q=b[i];
					ct+=(p*q);
				}
			}
		}
		printf ("%lld\n",ct);
	}
	return 0;
}
