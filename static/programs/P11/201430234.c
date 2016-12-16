#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	long long int x[100005];
	long long int y1[100005];
	long long int c[100005],n,z,q,r,t,y,result;
	int value=0;
	int flag ;
	while(1)
	{
		value=0;
		flag = 1 ;
		value++;
		scanf("%lld",&n);
		result = 0 ;
		if(n==0)
		{
			value=0;
			return 0 ;
		}
		for(z=0;z<n;z++)
		{
			scanf("%lld",&x[z]);
		}
		y1[0] = -1 ;
		value++;
		for(z=1;z<n;z=z+1)
		{
			value++;
			q=z-1;
			while(q>=0 && flag==1)
			{
				value=0;
				if(x[q]>=x[z])
				{
					value++;
					q=y1[q];
				}
				else
				{ 
					value=0;
					flag = 0 ;
				}
			}
			flag = 1 ;
			y1[z]=q;
		}
		flag = 1 ;
		value++;
		c[n-1]=n;
		for(z=n-2;z>=0;z=z-1)
		{
			value=0;
			q = z+1;
			while(q<=n-1 && flag==1)
			{
				value++;
				if(x[q]>=x[z])
				{
					q=c[q];
				}
				else
				{
				 flag = 0 ;
				}
			}
			flag = 1 ;
			value=0;
			c[z]=q;
		}
		for(z=0;z<n;z++)
		{
			value++;
			if(((c[z]-1-y1[z])*x[z])>result)
			{
				value--;
				result=(c[z]-y1[z]-1)*x[z];
			}
		}
		printf("%lld\n",result);
	}
	return 0;
}
