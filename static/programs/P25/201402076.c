#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
typedef struct node node;
struct edge
{
	int weight;
	int v1;
	int v2;
};
typedef struct edge edge;
node* adj[100005]={NULL};
node* list[100005]={NULL};
/*bool operator<(edge l,edge r)
{
	return (l.weight<r.weight);	
}*/
node* insert(node* curr,int val)
{
	node* head=(node*)malloc(sizeof(node));
	head->val=val;
	head->next=curr;
	return head;
}

edge edges[1000005];
edge temp[1000005];
void mergesort(int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int i=l,k=l;
	int j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(edges[i].weight<edges[j].weight)
		{
			temp[k]=edges[i];
			i++;
			k++;
		}
		else
		{
			temp[k]=edges[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		temp[k]=edges[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=edges[j];
		j++;
		k++;
	}
	for(i=l;i<=r;i++)
		edges[i]=temp[i];

}
int vis[100005]={0};
void dfs(int u)
{
	vis[u]=1;
	node* temp=adj[u];
	while(temp!=NULL)
	{
		if(!vis[temp->val])
			dfs(temp->val);
		temp=temp->next;
	}
}
int main()
{
	int n,m,arr[100005]={0},par[100005],size[100005];
	scanf("%d %d",&n,&m);
	int i;
	for(i=0;i<n;i++)
	{
		par[i]=i;
		size[i]=1;
		list[i]=insert(list[i],i);
	}
	for(i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		u--;v--;
		adj[u]=insert(adj[u],v);
		adj[v]=insert(adj[v],u);
		arr[u]++;
		arr[v]++;
		edges[i].weight=w;
		edges[i].v1=u;
		edges[i].v2=v;
	}
	mergesort(0,m-1);
	int ans=0;
//	printf("%d\n",m);
	for(i=0;i<m;i++)
	{
	//	printf("%d\n",i);
		int v1=edges[i].v1;
		int v2=edges[i].v2;
		int wt=edges[i].weight;
	//	printf("%d %d\n",par[v1],par[v2]);
		if(par[v1]==par[v2])
			continue;
		else
		{
	//		printf("%d %d %d\n",v1+1,v2+1,wt);
			ans+=wt;
			int temp1=par[v2],temp2=par[v1];
			if(size[par[v1]]<size[par[v2]])
			{
				temp1=par[v1];
				temp2=par[v2];
			}
			node* temp=list[temp1];
			while(temp!=NULL)
			{
				int val=temp->val;
				list[temp2]=insert(list[temp2],val);
				par[val]=par[temp2];
				temp=temp->next;
				size[temp2]++;
			}
		}

	}
	dfs(0);
	int cnt=0;
	for(i=0;i<n;i++)
		if(vis[i])
			cnt++;
	if(cnt==n)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
