#include<stdio.h>

int main()
{
	long long int n,i,j,x;
	scanf("%lld",&n);
	while(1)
	{
		long long int arr[n],ind1[n],ind2[n];
		scanf("%lld",&arr[0]);
		ind1[0]=-1;
		ind2[n-1]=-1;
		for(i=1;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			x=i-1;
			if(arr[i]>arr[x])
				ind1[i]=x;
			else
			{
				do
				{
					x=ind1[x];
					if(x==-1)
					{
						ind1[i]=-1;
						break;
					}
					if(arr[i]>arr[x])
					{
						ind1[i]=x;
						break;
					}
				}while(x!=-1);
			}
		}

		for(i=n-2;i>=0;i--)
		{
			x=i+1;
			if(arr[i]>arr[x])
				ind2[i]=x;
			else
			{
				do
				{
					x=ind2[x];
					if(x==-1)
					{
						ind2[i]=-1;
						break;
					}
					if(arr[i]>arr[x])
					{
						ind2[i]=x;
						break;
					}
				}while(x!=-1);
			}
		}
		long long int len;
		long long int max=0,cur;
		for(i=0;i<n;i++)
		{
			if(ind2[i]==-1)
				ind2[i]=n;
			len=ind2[i]-ind1[i]-1;
			cur=len*arr[i];
			if(cur>max)
				max=cur;
		}
		//for(i=0;i<n;i++)
		//	printf("%d ",ind1[i]);
		//printf("\n");
		//for(i=0;i<n;i++)
		//	printf("%d ",ind2[i]);
		//printf("\n");
		printf("%lld\n",max);
		scanf("%lld",&n);
		if(n==0)
			break;
	}
	return 0;
}




