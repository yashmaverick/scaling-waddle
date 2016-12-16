#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) 
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int i,t,a[1000000],u,e;
	scanf("%d",&e);

	for(u=0;u<e;u++)
	{
		scanf("%d",&t);
		for(i=0;i<t;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,t,sizeof(int),compare);
		/*for(i=0;i<t;i++)
		  {
		  printf("%d ",a[i]);
		  }
		  printf("\n");*/
		a[t]=-100000000;
		long long int sum=0;
		long long int count=1;
		for(i=0;i<t;i++)
		{
			if(a[i]==a[i+1])
			{
				count++;
			}
			else if(a[i]!=a[i+1])
			{
				sum=sum+(count*(count-1)/2);
				count=1;
			}
		}
		
		printf("%lld\n",sum);
	}
	return 0;
}
