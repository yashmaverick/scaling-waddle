#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i,j;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		/* long long int temp,max=0;
		  for(i=1;i<n;i++)
		  {
		  temp=a[i]-a[i-1];
		  if(temp>max)
		  max=temp;
		  }
		 */
		long long int temp,max=0,min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
				min=a[i];
			temp=a[i]-min;
			if(temp>max)
				max=temp;
		}
			printf("%lld\n",max);
		
	}	
		return 0;
	}	

