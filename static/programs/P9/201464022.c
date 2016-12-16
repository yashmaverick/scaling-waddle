#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int *array;
	long long int sum;
	int numvalues;
}node;
node *a;
int cmpfunc(const void *a,const void *b)
{
	const node *p=a;
	const node *q=b;
	if(p->sum > q->sum)
		return 1;
	else if(p->sum < q->sum)
		return -1;
	else return 0;
}
	
int main()
{
	int n,w,i,m,j;
	long long int tsum=0,M;
	scanf("%d%lld",&n,&M);
	a=malloc(sizeof(node)*n);
	for(i=0;i<n;i++)
	{
		tsum=0;
		scanf("%d",&m);
		a[i].numvalues=m;
		a[i].array=malloc(sizeof(int)*m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i].array[j]);
			tsum=((tsum%M)+a[i].array[j])%M;
		}
		a[i].sum=tsum%M;
	}
	qsort(a,n,sizeof(node),cmpfunc);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[i].sum);
		for(j=0;j<a[i].numvalues;j++)
			printf("%d\n",a[i].array[j]);
		printf("\n");
	}
	free(a);
	return 0;
}


