#include<stdio.h>
int main()
{

	long long int N,K,T,i,j,l;
	long long int a[100000];
	scanf("%lld",&T);
	for(i=0;i<T;i++)
	{

		long long int min;
		scanf("%lld%lld",&N,&K);
		for(l=0;l<N;l++)
			scanf("%lld",&a[l]);
		for(j=0;j<N-K+1;j++)
		{
			if(j==0||j>min)
			{
				long long int k;
				min=j;
				
				for(k=j;k<j+K;k++)
				{
					//printf("this is k %lld this is min %lld",k,min);
					if(a[k]<a[min])
						min=k;
				}
			}
			if(a[j+K-1]<a[min])
				min=j+K-1;
			printf("%lld",a[min]);
			if(j==(N-K))
				printf("\n");
			else printf(" ");
		}

	}

	return 0;

}
