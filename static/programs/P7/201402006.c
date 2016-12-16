#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int comp (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,n,i,*a;
	long long int count=1;
	long long int k,s=0;
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		count=1;
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),comp);
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				count++;
			}
			if(a[i]!=a[i-1])
			{
				k=(count*(count-1))/2;
				s+=k;
				count=1;
			}
		}
		k=(count*(count-1))/2;
		s+=k;
		printf("%lld\n",s);
	}
	return 0;
}
