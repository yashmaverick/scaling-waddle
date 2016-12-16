#include<stdio.h>
#include<stdlib.h>
struct node {
	int ind;
	int tot;
	int *a;
};
void merge(int a[][2],int lo,int mi,int hi)
{
	int i,j;
	int c,b;
	c=mi-lo+1;
	b=hi-mi;
	int left[c][2],right[b][2];
	for(i=0;i<c;i++)
	{
		left[i][0]=a[lo+i][0];
		left[i][1]=a[lo+i][1];
	}
	for(i=0;i<b;i++)
	{
		right[i][0]=a[mi+i+1][0];
		right[i][1]=a[mi+i+1][1];
	}
	for(i=0,j=0;i<c && j<b;)
	{
		if(left[i][0]<=right[j][0])
		{
			a[lo+i+j][0]=left[i][0];
			a[lo+i+j][1]=left[i][1];
			i++;
		}
		else
		{
			a[lo+i+j][0]=right[j][0];
			a[lo+i+j][1]=right[j][1];
			j++;
		}
	}
	while(i!=c)
	{
		a[lo+i+j][0]=left[i][0];
		a[lo+i+j][1]=left[i][1];
		i++;
	}
	while(j!=b)
	{
		a[lo+i+j][0]=right[j][0];
		a[lo+i+j][1]=right[j][1];
		j++;
	}
	return;
}
void mergesort(int a[][2],int lo,int hi)
{
	if(lo>=hi)
		return;
	int mi=(lo+hi)/2;
	mergesort(a,lo,mi);
	mergesort(a,mi+1,hi);
	merge(a,lo,mi,hi);
	return;
}
typedef struct node node;
int main()
{
	int n;
	int mod;
	scanf("%d %d",&n,&mod);
	int i,j,aa[n][2];
	node head[n];
	for(i=0;i<n;i++)
	{
		aa[i][0]=0;
		scanf("%d",&head[i].tot);
		//printf("%d",head[i].tot);
		head[i].a=(int*)malloc(sizeof(int)*head[i].tot);
		for(j=0;j<head[i].tot;j++)
		{
			scanf("%d",&head[i].a[j]);
			aa[i][0]+=head[i].a[j];
			aa[i][0]%=mod;
		}
		aa[i][1]=head[i].ind=i;
	}
//	for(i=0;i<n;i++)
//		printf("%d ",aa[i][0]);
//	printf("\n");
	mergesort(aa,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",aa[i][0]);
		for(j=0;j<head[aa[i][1]].tot;j++)
			printf("%d\n",head[aa[i][1]].a[j]);
		printf("\n");
	}
	return 0;
}
