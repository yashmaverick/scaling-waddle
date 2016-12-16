#include<stdio.h>
long long int s;
	long long int a[1000000];
	long long int b[1000000];
int main()
{
	long long int t,n,min,max,k,l,r,p;
	scanf("%lld",&t);
	for(k=0;k<t;k++)
	{
		s=0;
		min=20000000;
		max=-20000000;
		scanf("%lld",&n);
		for(l=0;l<1000000;l++)
		{
			b[l]=0;
		}
		for(l=0;l<n;l++)
		{
			scanf("%lld",&a[l]);
			if(a[l]>max)
				max=a[l];
			if(a[l]<min)
				min=a[l];
		}
//printf("%d\n",min);
		for(l=0;l<n;l++)
		{
			r=a[l]-min;
			b[r]++;
		}
/*		for(l=0;l<1000000;l++)
		{if(b[l]!=0)
			       printf("%d\n",b[l]);	}*/
		s=0;
		for(p=0;p<=max-min;p++)
		{
			if(b[p]>1)
			{
				s=s+((b[p]*(b[p]-1))/2);

			}
		}
		printf("%lld\n",s);
	}
	return 0;

}



