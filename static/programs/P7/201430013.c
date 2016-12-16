#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
long long int nC2(long long int n)
{
	return (n*(n-1))/2;
}
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		long long int n;
		scanf("%lld",&n);
		int *a;
		a=(int*)malloc(n*sizeof(int));
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),cmpfunc);
		long long int k=a[0];
		long long int count=0;
		long long int counta=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==k)
			{
				count++;
			}
			else
			{
				counta+=nC2(count+1);
				count=0;
				k=a[i];
			}
		}
		if(a[i-1]==a[i-2])
			counta+=nC2(count+1);
		printf("%lld\n",counta);
	}
	return 0;
}



