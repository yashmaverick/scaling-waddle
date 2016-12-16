#include<stdio.h>
#include<stdlib.h>
long long int findpairs(long long int a[],long long int n)
{
	long long int i,j,max,count=0;
		for(i=0;i<n;i++)
		{
			max=a[i+1];
			for(j=i+1;j<n;j++)
			{
				if(a[j]<max)
					count++;
				if(a[j]>a[i])
				{
					count+=(n-1-j);
					break;
				}
				if(a[j]>max)
					max=a[j];
			}
		}
		return count;
}
int main()
{
	long long int n,i,j,max,count;
	while(1)
	{
		long long int *a;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		count=0;
		a=malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		printf("%lld\n",findpairs(a,n));
		free(a);
	}
}




	
