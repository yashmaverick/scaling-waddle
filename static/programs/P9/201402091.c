#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
	int m;
	int *warr;
	int total;
}bag;
bag *bags;
int cmpfunc(const void *p,const void *q)
{
	const int l=((bag*)p)->total;
	const int r=((bag*)q)->total;
	return l>r;
}
int main()
{
	int n,i,j,mod;
	scanf("%d %d",&n,&mod);
	bags = (bag*)malloc(n*sizeof(bag));
	for(i=0;i<n;i++)
	{	
		bags[i].total=0;
		scanf("%d",&bags[i].m);
		bags[i].warr=(int *)malloc(sizeof(int)*(bags[i].m));
		for(j=0;j<bags[i].m;j++)
		{
			scanf("%d",&bags[i].warr[j]);
			bags[i].total=(bags[i].total+bags[i].warr[j])%mod;
		}
	}
	qsort(bags,n,sizeof(bag),cmpfunc);
	for(i=0;i<n;i++)
	{	printf("%d\n",bags[i].total);
		for(j=0;j<bags[i].m;j++)
		{
			printf("%d\n",bags[i].warr[j]);
		}
		printf("\n");
	}
	free(bags);
	return 0;
}
