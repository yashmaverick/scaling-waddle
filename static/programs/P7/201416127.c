#include<stdio.h>
#include<stdlib.h>
long long int per(long long int n);
void bucketsort(long long int a[],int n)
{
	long long int *b;long long int sum=0;
	b=(long long int *)malloc(sizeof(long long int)*1000000);
	int i;
	for(i=0;i<1000000;i++)
		b[i]=0;
	for(i=0;i<n;i++)
		(b[a[i]])++;
	for(i=0;i<1000000;i++)
		sum=sum+per(b[i]);
	printf("%lld\n",sum);
}
long long int per(long long int n)
{
	return n*(n-1)/2;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;long long int min=10000000;
		scanf("%d",&n);
		long long int a[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			if(a[j]<min)
				min=a[j];
		}
		//bucketsort(a,n);
		for(j=0;j<n;j++)
			a[j]=a[j]-min;
		bucketsort(a,n);
	}
	return 0;
}

