#include<stdio.h>
long long int a[500005];
int main()
{
	long long int n,l,k,j,i;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int num=0;
		for(i=0;i<n-1;i++)
		{
			long long int h=0;
			for(j=i+1;j<n;j++)
			{
				if(a[j]>a[i])
				{
					num=num+n-j-1;
					break;
				}
				else if(a[j]>=h && a[j]<=a[i])
					h=a[j];
				else
					num++;
				
			}
		}
		printf("%lld\n",num);
	}
	return 0;
}
