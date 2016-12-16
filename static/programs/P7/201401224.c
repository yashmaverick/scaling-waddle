#include<stdio.h>
int main()
{
	long int g,i;
	scanf("%ld",&g);
	for(i=0;i<g;i++)
	{
		long int j,n,x,y,s;
		s=0;
		scanf("%ld",&n);
		long int a[n];
		scanf("%ld",&a[0]);
		x=a[0];
		y=a[0];
		for(j=1;j<n;j++)
		{
			scanf("%ld",&a[j]);
			if(a[j]<x)
				x=a[j];
			if(a[j]>y)
				y=a[j];
		}
		long int b[y-x+1];
		for(j=0;j<=(y-x);j++)
			b[j]=0;
		for(j=0;j<n;j++)
			b[a[j]-x]++;
		for(j=0;j<=(y-x);j++)
		{
			if(b[j]>1)
				s=s+(b[j]*(b[j]-1))/2;
		}
		printf("%ld\n",s);
	}
	return 0;
}
