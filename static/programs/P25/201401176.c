#include<stdio.h>
typedef struct node
{
	int src,des,weight;
}node;
node te[100005];
node a[1000005];
int rank[100005],cnt[100005],parent[100005];
void mergesort(node arr[],int low,int mid,int high)
{
	int i,m,k,l;l=low;i=low;m=mid+1;
	while((l<=mid)&&(m<=high))
	{if(arr[l].weight<=arr[m].weight)
		{te[i].weight=arr[l].weight;
			te[i].src=arr[l].src;
			te[i].des=arr[l].des;
			l++;}
		else
		{te[i].weight=arr[m].weight;
		te[i].src=arr[m].src;
		te[i].des=arr[m].des;
		m++;}
		i++;
	}
	if(l>mid)
	{for(k=m;k<=high;k++){te[i].weight=arr[k].weight;
				     te[i].src=arr[k].src;
				     te[i].des=arr[k].des;
				     i++;}}
	else
	{for(k=l;k<=mid;k++){te[i].weight=arr[k].weight;
				     te[i].src=arr[k].src;
				     te[i].des=arr[k].des;
	i++;}}
	for(k=low;k<=high;k++){arr[k].weight=te[k].weight;
				     arr[k].src=te[k].src;
				     arr[k].des=te[k].des;
	}
}
void sortmerge(node arr[],int low,int high)
{
	int mid;
	if(low<high)
	{mid=(low+high)/2;sortmerge(arr,low,mid);sortmerge(arr,mid+1,high);mergesort(arr,low,mid,high);}
}
int representative(int x,int y)
{
	int i,j;
	i=parent[x];
	j=parent[y];
	while(parent[i]!=i)
		i=parent[i];
	while(parent[j]!=j)
		j=parent[j];
	if(i!=j)
		return 1;
	else
		return -1;
}
void merge(int x,int y)
{
	int i,j;
	i=parent[x];
	j=parent[y];
	while(parent[i]!=i)
		i=parent[i];
	while(parent[j]!=j)
		j=parent[j];
	if(rank[i]<rank[j])
	{
		parent[i]=j;
		cnt[j]+=cnt[i];
	}
	else if(rank[i]>rank[j])
	{
		parent[j]=i;
		cnt[i]+=cnt[j];
	}
	else
	{
		parent[j]=i;
		rank[i]+=1;
		cnt[i]+=cnt[j];
	}
}
int main()
{
	int i,n,m,p,x=0,ans=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		rank[i]=0;
		cnt[i]=1;
		parent[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].src,&a[i].des,&a[i].weight);
	}
	if(m<n-1)
		printf("-1\n");
	else
	{
		sortmerge(a,1,m);
		/*for(i=1;i<=m;i++)
			printf("%d ",a[i].weight);
		printf("\n");*/
		for(i=1;i<=m;i++)
		{
			p=representative(a[i].src,a[i].des);
			if(p==1)
			{
				merge(a[i].src,a[i].des);
				x++;
				ans+=a[i].weight;
			}
			if(x==n-1)
				break;
		}
		if(x<n-1)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
