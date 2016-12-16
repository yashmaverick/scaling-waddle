#include<stdio.h>

struct bag
{
	int w;
	int start;
	int end;
};

int compare(struct bag *A, struct bag *B)
{
	if (A->w == B->w)
		return A->start - B->start;
	return A->w - B->w;
}

int main()
{
	int i,j;
	int a[1000000],m,k=0,n,MOD;
	
	scanf("%d %d",&n,&MOD);
	struct bag b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		b[i].start=k;
		b[i].w=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[k]);
			b[i].w+=a[k];
			k++;			
			b[i].w%=MOD;
		}
		b[i].end=k-1;
		//printf("%d %d %d\n",b[i].start,b[i].end,b[i].w);		
	}
	qsort(b,n,sizeof(b[0]),compare);
	for(j=0;j<n;j++)
	{
		printf("%d\n",b[j].w);
		for(i=b[j].start;i<=b[j].end;i++)
		{
			printf("%d\n",a[i]);
		}
		printf("\n");
	}
	return 0;
}
