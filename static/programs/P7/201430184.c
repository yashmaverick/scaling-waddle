#include<stdio.h>
long long int permutation(long long int a)
{
	long long int t;
	if(a>1)
	{
		t=(a*(a-1))/2;
	        return t;
	}
	else
		return 0;
}
int main()
{
	int test,count;
        scanf("%d",&test);
	for(count=0;count<test;count++)
	{
		long long int size,i,t=0,n,max,min;
		scanf("%lld",&size);min=10000000;max=-10000000;
		long long int a[size];
		for(i=0;i<size;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=max)
			{
				max=a[i];
			}
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		long long int arr[max-min+1];
		for(i=0;i<max-min+1;i++)
		{
			arr[i]=0;	
		}
		for(i=0;i<size;i++)
		{
		      arr[a[i]-min]++;
		}
		for(i=0;i<max-min+1;i++)
		{
			n=permutation(arr[i]);
			t=t+n;		
		}
		printf("%lld\n",t);
	}
	return 0;  
}
