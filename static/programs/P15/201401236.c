#include<stdio.h>
int main()
{
	long long int  test,a[100000],b[100000];
	scanf("%lld",&test);
	while(test--)
	{
		long long int n,k,i,start=0,j,h;
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			j=i-1;
			b[i]=a[i];
			if(i>=k)
				start++;
			while(j>=start)
			{
				if(b[j]>b[j+1])
				{
					b[j]=b[j+1];
					j--;
				}
				else
					break;
			}
		}
		for(h=0;h<n-k+1;h++)
			{
			if(h==(n-k))
			printf("%lld\n",b[h]);
			else
			printf("%lld ",b[h]);
		
			}
	}
	return 0;
}
























