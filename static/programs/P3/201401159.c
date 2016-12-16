#include <stdio.h>

int main()
{
	int test,i,j,k,tmax,max,min,n;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d %d",&n,&min);
		max=0;tmax=0;
		for(j=0;j<n-1;j++)
		{
			scanf("%d",&k);
			if(k>min)
			{
				if(k>tmax)
				{
					tmax=k;
					if(tmax-min>max)
					max=tmax-min;
				}
			}
			else
			{
				min=k;
				tmax=0;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
