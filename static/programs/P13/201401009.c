#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int v;
	int depth;
}node;
node a[100005];
int m,max;
int search(node *a,int b,int start,int end)
{
	int mid,y;
	mid=start+(end-start)/2;
	if(start>end)
		return 0;
	else if(start==end)
		return end;
	if(a[start].v>a[b].v)
		return start;
	else if(a[b].v>a[end].v)
		return end+1;
	if(a[b].v>a[mid].v)
	{
		if(a[b].v<a[mid+1].v)
			return mid+1;
		else
			y=search(a,b,mid+1,end);
	}
	else
	{
		if(a[b].v>a[mid-1].v)
			return mid;
		else
			y=search(a,b,start,mid);
	}
	return y;
}
int findroot(int start,int end,node *a,int lvl)
{
	if(start>end)
		return -1;
	if(start==end)
	{
		a[end].depth=lvl;
		return lvl;
	}
	int i;
	i=search(a,end,start,end-1);
	int ldepth,rdepth;
	ldepth=findroot(start,i-1,a,lvl+1);
	rdepth=findroot(i,end-1,a,lvl+1);
	if(ldepth>=rdepth)
		a[end].depth=ldepth-1;
	else
		a[end].depth=rdepth-1;
	return a[end].depth;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int i;
		max=0;
		scanf("%d",&m);
	//	node a[100005];
		for(i=0;i<m;i++)
			scanf("%d",&a[i].v);
		if(m==0)
		{
			printf("0 0\n");
		}
		else if(m==1)
		{
			printf("%d 0\n",a[0].v);

		}
		else
		{
			int e=findroot(0,m-1,a,0);
			int min=9999999;
			max=-1;
			for(i=0;i<m;i++)
			{
//				printf("%d ",a[i].depth);
				if(max<a[i].depth)
					max=a[i].depth;
			}
//			printf("\n%d\n",max);	
			for(i=0;i<m;i++)
			{
				if(a[i].depth==max && a[i].v<min)
					min=a[i].v;
			}
			printf("%d %d\n",min,max);
		}
	}
	return 0;
}
