#include<stdio.h>
#include<stdlib.h>
long long int a[1000000];
int main()
{
	long long int n;
	long long int k;
	long long int j,diff,iter=0;
	long long int min,max,minpos,maxpos,profit=0;
	scanf("%lld",&n);
	long long int i;
	for(i=0;i<n;i++)
	{
	diff=0; max=-100; profit=0; minpos=0; maxpos=0;iter=0;
		scanf("%lld",&k);
		for(j=0;j<k;j++)
		{
			scanf("%lld",&a[j]);
			if(iter==0)
			{
				min=a[j];
				iter++;
				continue;
			}
			if(a[j]<min)
			{
				if(j==(k-1))
					minpos=minpos;
				else{
				min=a[j];
				minpos=j;
				}
				

				//printf("%lld",minpos);
			}

			if(a[j]>max)
			{
				max=a[j];
				maxpos=j;
				//printf("%lld",maxpos);
			}

			if(minpos<maxpos)
			{
				diff=a[maxpos]-a[minpos];
				if(diff>profit)
					profit=diff;
			}
			else if(minpos>maxpos)
				max=-100;
		}

		if(minpos>maxpos)
		printf("%d\n",0);
		else 
			printf("%lld\n",profit);


	}
return 0;
}
