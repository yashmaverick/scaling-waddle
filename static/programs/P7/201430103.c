#include<stdio.h>
long long int ARR[1000000];
int main()
{
	long long int i,n,t,min,j,o,k,l,m,sum,arr[1000000],x;
	scanf("%lld",&t);
	while(t--)
	{
		int max=0;
		for(o=0;o<1000001;o++)
			ARR[o]=0;

		sum=0;

		scanf("%lld",&n);

		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		min=arr[0];

		for(j=0;j<n;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
			}
		}

		for(k=0;k<n;k++)
		{
			arr[k]=arr[k]-min;
			if(arr[k]>max)
			{
				max=arr[k];
			}
		}

		for(l=0;l<n;l++)
		{
			x=arr[l];
			ARR[x]=ARR[x]+1;
		}

		for(m=0;m<=max;m++)
		{
			if(ARR[m]>1)
				sum=sum+((ARR[m])*(ARR[m]-1))/2;
		}

		printf("%lld\n",sum);
	}
	return 0;
}
