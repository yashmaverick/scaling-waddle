#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int a[n],top,area,i,max;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int stac[n];
		
		top=-1;
		i=0;
		//stac[0]=0;
		max=0;
		while(i<n)
		{
			//printf("topp%d\n",top);
			if(top==-1 ||a[stac[top]]<=a[i] )
			{top++;
				stac[top]=i++;
				
			}
			else
			{
				if((top)<1)
					area=a[stac[top]]*i;
				else
					area=a[stac[top]]*(i-stac[top-1]-1);
				if(max<area)
					max=area;
				top--;
			//printf("ttttopp%d\n",top);
			}

		}
		while(top>-1)
		{
			//top--;
			if((top-1)<0)
				area=a[stac[top]]*i;
			else
				area=a[stac[top]]*(i-stac[top-1]-1);
			top--;
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
