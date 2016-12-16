#include<stdio.h>
int main()
{
	long long int t,a[100002],n,i,min,diff,current;
	scanf ("%lld",&t);
	while (t--)
	{
		scanf ("%lld",&n);
		for (i=0;i<n;i++)
			scanf("%lld",&a[i]);
		if (n<=1)printf ("0\n");
		else
		{
			min=a[0];
			diff=a[1]-a[0];
			for (i=0;i<n;i++)
			{
				if ((a[i]-min)>diff)
					diff=a[i]-min;
				if (a[i]<min)
					min=a[i];
			}
			printf ("%lld\n",diff);
		}
	}
	return 0;
}
