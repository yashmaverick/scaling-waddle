#include<stdio.h>

int main()
{

	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,pbig=0,psmall=0;
		long long int a[n],big,small,diff;
		scanf("%lld",&a[0]);
		big=a[0];
		small=a[0];
		diff=big-small;

		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>big)
			{
				big=a[i];
				pbig=i;
			}
			else
			if(a[i]<small)
			{
				small=a[i];
				psmall=i;
			}
			if(psmall<pbig)
			{
				if(diff<(a[pbig]-a[psmall]))
				diff=a[pbig]-a[psmall];
			}
			if(pbig<psmall)
			{
				pbig=psmall;
				big=a[pbig];
			}

			
		}

		if(pbig>=psmall)
			printf("%lld\n",diff);
		if(psmall>pbig)
			printf("0\n");
	}
	return 0;
}






		


