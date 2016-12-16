#include<stdio.h>
typedef struct node
{
	int weight;
	int v1;
	int v2;
}node;
node a[1000001];
node temp[1000001];
int rank[1000001];
int parent[1000001];
int find_parent(int i);
int merge_sort(node a[],int fi,int la);
void merge(node a[],int l,int r);
int main()
{
	int n,m,i,sum=0,cnt=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		parent[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a[i].v1,&a[i].v2,&a[i].weight);
	}
	merge_sort(a,0,m-1);
//	for(i=0;i<m;i++)
//		printf("%d %d %d\n",a[i].weight,a[i].v1,a[i].v2);
	for(i=0;i<m;i++)
	{
		int x=find_parent(a[i].v1);
		int y=find_parent(a[i].v2);
//		for(i=1;i<=n;i++)
//			printf("%lld ",parent[i]);
//		printf("\n");
//		printf("parents of %d: %d parents of %d:%d\n",a[i].v1,parent[a[i].v1],a[i].v2,parent[a[i].v2]);
		if(x!=y && rank[x]==rank[y])
		{
			parent[x]=y;
			rank[y]++;
			cnt++;
			sum+=a[i].weight;
//			printf("edge added:%d\n",a[i].weight);
		}
		else if(x!=y && rank[x]!=rank[y])
		{
			if(rank[y]>rank[x])
				parent[x]=y;//printf("yay!!\n");}
			else
				parent[y]=x;
			cnt++;
			sum+=a[i].weight;
//			printf("edge added:   %d\n",a[i].weight);
		}
//		else if(find_parent(a[i].v1)==find_parent(a[i].v2))
//			continue;
//		printf("parents of %d: %d parentd of %d :%d\n",a[i].v1,parent[a[i].v1],a[i].v2,parent[a[i].v2]);
//		printf("%d\n",sum);	
	if(cnt==n-1)
			break;
	}
//	printf("cnt %lld\n",cnt);
	if(cnt<n-1)
		printf("-1\n");
	else
		printf("%d\n",sum);
return 0;
}
int merge_sort(node a[],int fi,int la)
{
	if(fi>=la)
		return;
	if(fi<la)
	{
		int mid=(fi+la)/2;
		merge_sort(a,fi,mid);
		merge_sort(a,mid+1,la);
		merge(a,fi,la);
	}
}
void merge(node a[],int l,int r)
{
	int i,mid=(l+r)/2;
	int j=mid+1,k=0;
	i=l;
	while(i<=mid && j<=r)
	{
		if(a[i].weight<=a[j].weight)
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	k=0;
	for(i=l;i<=r;i++)
	{
		a[i]=temp[k];
		k++;
	}
}

/*void find_parent(long long int i)
{
	long long int index=i;
	while(parent[i]!=i)
	{
		i=parent[i];
	}
	while(parent[num]!=num)
	{
		parent[num]=i;
		num=parent[num];
	}
}*/
int find_parent(int i)
{
	if(parent[i]!=i)
		parent[i]=find_parent(parent[i]);
	
		return (parent[i]);

}
