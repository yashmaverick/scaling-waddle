#include<stdio.h>
#include<stdlib.h>
long long int minimum(long long int a,long long int b)
{
	if(a>b)
		return b;
	else return a;
}
int main()
{
	long long int t,n,i,j,*a,*right,*left,k,partition;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		a=malloc(sizeof(long long int)*n);
		right=malloc(sizeof(long long int)*n);
		left=malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		partition=n-k+1;
		for(i=0;i<n;i++)
		{
			if(i%(k)==0)
			{
				left[i]=a[i];

			}
			else 
			{
				left[i]=minimum(a[i],left[i-1]);
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(i==n || i%(k)==0)
			{
				right[i]=a[i];

			}
			else
			{
				right[i]=minimum(a[i],right[i+1]);

			}
		}
		for(i=0;i<partition;i++)
		{
			if(i!=partition-1)
			printf("%lld ",minimum(right[i],left[i+k-1]));
			else
				printf("%lld\n",minimum(right[i],left[i+k-1]));
		}
		//printf("\n");
		free(a);
		free(right);
		free(left);

	}
	return 0;
}





