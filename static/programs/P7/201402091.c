#include<stdio.h>
int cmpf(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{       int i,n,j,t,m,a[1000007];
	long long int sum,c;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		qsort(a,n,sizeof(int),cmpf);
		sum=0;m=a[0];
		c=1;
//		for(j=0;j<n;j++)
//			printf("%d ",a[j]);
		
		for(j=1;j<n;j++)
		{
			if(a[j]==m)
				c++;
			else
			{
				m=a[j];
				sum+=((c*(c-1))/2);
				c=1;
			}
		}
		if(c!=1)
		sum+=((c*(c-1))/2);
		printf("%lld\n",sum);
	}
	return 0;
}
