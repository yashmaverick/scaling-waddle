#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
long long int  t,n,a[1000000],i,ans,b[1000000],min,z,max;
long long count;
scanf("%lld",&t);

while(t--)
	{
	count=0;
	scanf("%lld",&n);

	
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	min=max=a[0];
	

	for(i=0;i<n;i++)
		{
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
		}
		
//	printf("%d %d\n",min,max);
		
	for(i=0;i<n;i++)
		{
		 z=a[i]-min;
		b[z]++;
		}

//	for(i=0;i<max-min+1;i++)
//		printf("%d ",b[i]);

	for(i=0;i<1000000;i++)
		if(b[i]>1)
			count+=b[i]*(b[i]-1)/2;
				
	printf("%lld\n",count);	

			
	for(i=0;i<1000000;i++)
		b[i]=0;
	}

return 0;
}
