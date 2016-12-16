#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct array
{
	long long int tw;int m,sn;
	int  *ptr;
};
struct array a[1000];
int compfunc(const void *a,const void *b)
{
struct array *c=(struct array*)a;
struct array *d=(struct array*)b;
if (c->tw == d->tw )
	return c->sn-d->sn;
else 
	return c->tw-d->tw;
}
int main()
{
	int n,mod,i,m,j;
	scanf("%d %d",&n,&mod);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[i].sn=i;
		a[i].ptr=(int *)malloc(sizeof(int)*m);
		a[i].m=m;
		int j;
		int no;long long int sum=0;
		for(j=0;j<m;j++)
		{
				scanf("%d",&no);
				sum=(sum+no)%mod;
				a[i].ptr[j]=no;
		}
		a[i].tw=sum;
	}
		qsort(a,n,sizeof(struct array),compfunc);		
	for(i=0;i<n;i++)
	{
		printf("%lld\n",a[i].tw);
		for(j=0;j<a[i].m;j++)
			printf("%d\n",a[i].ptr[j]);
		printf("\n");
		
	}	
		return 0;
}
