#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	long long int *b;
	long long int sum;
	long long int m;
}list;

int cmpfunc(const void *a,const void *b)
{
	long long int l = ((list *)a)->sum;
	long long int r = ((list *)b)->sum;
	return (l-r);
}
int main()
{
	long long int n,mod,j,i,k;
	scanf("%lld%lld",&n,&mod);
	k=0;
	list *a;
	a=(list *)malloc(n*sizeof(list));
	while(k<n)
	{
		scanf("%lld",&a[k].m);
		a[k].b=(long long int *)malloc((a[k].m)*sizeof(long long int));
		for(i=0;i<a[k].m;i++)
		{
			scanf("%lld",&(a[k].b[i]));
			(a[k].sum)=((a[k].sum)%mod+(a[k].b[i]))%mod;
		}
		//	a[n].b[0]=m;
		//		printf("%lld\n",a[k].sum);
		k++;
	}
	qsort(a,n,sizeof(list),cmpfunc);
	//	printf("a\n");
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[i].sum);
		for(j=0;j<a[i].m;j++)
		{
			printf("%lld\n",a[i].b[j]);
		}
		printf("\n");
	}
	free(a);
	return 0;
}

