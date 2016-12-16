#include<stdio.h>
#include<stdlib.h>
struct wgt{
	int val;
	int index;
	//int a[1004];
	int size;
};
int cmpfunc (const void * a, const void * b)
{
	//return ( *(int*)a - *(int*)b );
//	const struct wgt wgt_a=a;
//	const struct wgt wgt_b=b;
	struct wgt *wgt_a, *wgt_b;
	wgt_a=(struct wgt*)a;
	wgt_b=(struct wgt*)b;
	if(wgt_a->val>wgt_b->val)
		return 1;
	if(wgt_a->val<wgt_b->val)
		return -1;
	if(wgt_a->val==wgt_b->val)
	{
		if(wgt_a->index>wgt_b->index)
			return 1;
		if(wgt_a->index<wgt_b->index)
			return -1;
	}
	return 0;
}
int main()
{
	struct wgt arr[1004];
	int j,s,i,n,mod,m,itm,k,c[1000000],q;
	/*for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			c[i][j]=0;
		}
	}*/
	scanf("%d %d",&n,&mod);
	q=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		arr[i].size=m;
		arr[i].index=q;
		s=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&itm);
			//arr[i].a[j]=itm;
			c[q++]=itm;
			s=s+itm;
			s=s%mod;
		}
		arr[i].val=s;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d %d\n",arr[i].val,arr[i].index);
	}*/
	qsort(arr,n,sizeof(struct wgt),cmpfunc);
	/*for(i=0;i<n;i++)
	{
		printf("%d %d %d\n",arr[i].val,arr[i].index,arr[i].size);
	
	}*/
	/*for(i=0;i<n;i++)
	{
		for(j=0;c[i][j]!=0;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}*/
	//printf("%d",q);
	/*k=0;
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i].val);
		printf("\n");
		for(j=k;j<(arr[i].size+k);j++)
		{
			printf("%d\n",c[j]);
		}
		k=arr[i].size+k;
		printf("\n");
	}*/
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i].val);
		printf("\n");
		for(j=arr[i].index;j<arr[i].size+arr[i].index;j++)
		{
			printf("%d\n",c[j]);
		}
		printf("\n");
	}
	







	return 0;
}
