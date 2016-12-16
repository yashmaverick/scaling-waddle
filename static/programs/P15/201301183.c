#include <stdio.h>
int ind=0;
long int min=10000000;
long int findmin(long int a[] , int i,int n)
{
	int j;
	long int min2=10000000;
	for(j=i;j<=n;j++)
	{
		if(min2>=a[j])
		{
			min2 = a[j];
			ind = j;
		}
	}
	min = min2;
return min;
}
int main()
{
	 int tn,ti;
	scanf("%d",&tn);
	for(ti=0;ti<tn;ti++)
	{
		min = 1000000;
		ind = 0;
		 int n,k,d=0,m,i,j;
		scanf("%d %d",&n,&k);
		long int a[n+1];
		a[0] = 0;
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=n-k+1;i++)
		{
			if(ind==i-1)
				m =findmin(a,i,i+k-1);
			else
			{
				if(min >= a[i+k-1])
				{
				 	m = a[i+k-1];
				 	min=a[i+k-1];
				 	ind = i+k-1;
				 } 
			}
			if(i<n-k+1)
				printf("%ld ",m);
			if(i==n-k+1)
				printf("%ld\n",m);
		}
	}
	return 0;
}
