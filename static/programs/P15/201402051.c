#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int find_minimum(long int a[] , int i,int n);
long int min=10000000;
int var=0;


int main()
{
	 int tn,r=0;
	scanf("%d",&tn);
	while(r<tn)
	{
		min = 1000000;
		var = 0;
		int n,k,m,i,j,d=0;
		scanf("%d %d",&n,&k);
		long int a[n+1];
		a[0] = 0;
		d=d+1;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&a[i]);
		}
		d=d+1;
		for(i=1;i<=n-k+1;i++)
		{
			d=d+1;
			if(var ==i-1)
			{
				d=d+1;
				m =find_minimum(a,i,i+k-1);
			}
			else
			{
				d=d+1;
				if(min >= a[i+k-1])
				{
					d=d+1;
				 	m = a[i+k-1];
				 	min=a[i+k-1];
				 	var = i+k-1;
				 	d=d+1;
				 } 
			}
			if(i<n-k+1)
			{
				d=d+1;
				printf("%ld ",m);
			}
			if(i==n-k+1)
			{
				printf("%ld\n",m);
			}
		}
		r++;
	}
	return 0;
}

long int find_minimum(long int a[] , int i,int n)
{
	long int min2=10000000;
	int j,r=0;
	r=r+1;
	for(j=i;j<= n;j++)
	{
		r=r+1;
		if(min2>=a[j])
		{
			min2 = a[j];
			var = j;
		}
	}
	min = min2;
return min;
}