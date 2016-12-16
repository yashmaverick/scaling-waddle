#include<stdio.h>
int main()
{	
	int t,n,i,j;
	long int a[100001],d,l,max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%ld",&a[j]);
		l=a[0];
		max=0;
		for(j=0;j<n;j++)
		{
			if(a[j]<l)
				l=a[j];
			d=a[j]-l;
			if(max<d)
				max=d;
		}
		printf("%ld\n",max);
	}
	return 0;
}
