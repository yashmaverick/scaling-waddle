#include<stdio.h>
int main()
{
	long long int a[100000],max;
	int count,i,L,T;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d",&count);
		for(i=0;i<count;i++)
		{
			scanf("%lld",&a[i]);
		}
		int min=a[0];
		for(i=0;i<count;i++)
		{
			if(a[i]>=min)
				a[i]-=min;
		
			else
			{
				L=min;
				min=a[i];
				a[i]-=min;
			}
		}
		max=a[0];
		for(i=1;i<count;i++)
		{
			if(a[i]>=max)
				max=a[i];
		}
		if(max>=0)
			printf("%lld\n",max);
		else
			printf("0\n");
		T--;
	}
	return 0;
}
