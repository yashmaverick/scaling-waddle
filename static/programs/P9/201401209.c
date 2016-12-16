#include<stdio.h>
#include<stdlib.h>
int cfun(const void* a,const void* b)
{
	return (*(long long int*)a-*(long long int*)b);
}
long long int mod;

typedef struct bag
{
	int flag;
	long int items;
	long int finalweight;
	long int* weights;
}bag;
int main()
{
	int n,i,j,k;
	scanf("%d %lld",&n,&mod);
	bag* a=malloc(sizeof(bag)*n);
	long long int sortarr[n];
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i].items);
		a[i].weights=(long int*)malloc(sizeof(long int)*a[i].items);
		a[i].finalweight=0;
		a[i].flag=0;
		for(j=0;j<a[i].items;j++)
		{
			scanf("%ld",&a[i].weights[j]);
			a[i].finalweight=(a[i].finalweight+a[i].weights[j])%mod;
		}
		sortarr[i]=a[i].finalweight;
	}
	qsort(sortarr,n,sizeof(long long int),cfun);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j].finalweight==sortarr[i] && a[j].flag==0)
			{
//				printf("%lld",sortarr[i]);
				a[j].flag=1;
				printf("%ld\n",a[j].finalweight);
				for(k=0;k<a[j].items;k++)
				{
					printf("%ld\n",a[j].weights[k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
