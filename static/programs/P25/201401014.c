#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
struct node {
	int data;
	struct node *next;
};
typedef struct node node;
node *A[1000002];
int visited[1000002];
void adj_list(int vi,int vj)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=vj;
	temp->next=NULL;
	if(A[vi]==NULL)
		A[vi]=temp;
	else
	{
		temp->next=A[vi];
		A[vi]=temp;
	}
}

void dfs(int i)
{
	node *t;
	visited[i]=1;
	t=A[i];
	while(t!=NULL)
	{
		if(visited[t->data]==0)
			dfs(t->data);
		t=t->next;
	}
}
	
struct heap_node{
	int weight;
	int v;
	int u;
};
typedef struct heap_node heap_node;
heap_node heap[1000002];
int parent[1000002],rank[1000002],heapsize;

void deletemin()
{
	int var,temp,min_ind;
	heap[1].weight=heap[heapsize].weight;
	heap[1].u=heap[heapsize].u;
	heap[1].v=heap[heapsize].v;
	heapsize--;
	temp=1;
	while(1)
	{
		if(((2*temp)+1)<=heapsize)
		{
			if(heap[temp].weight>min(heap[2*temp].weight,heap[(2*temp)+1].weight))
			{
				if(min(heap[2*temp].weight,heap[(2*temp)+1].weight)==heap[2*temp].weight)
					min_ind=2*temp;
				else
					min_ind=2*temp+1;
				//swap
				var=heap[temp].weight;
				heap[temp].weight=heap[min_ind].weight;
				heap[min_ind].weight=var;
				var=heap[temp].u;
				heap[temp].u=heap[min_ind].u;
				heap[min_ind].u=var;
				var=heap[temp].v;
				heap[temp].v=heap[min_ind].v;
				heap[min_ind].v=var;
				temp=min_ind;
			}
			else
				break;
		}
		else if(2*temp<=heapsize && (2*temp+1)>heapsize)
		{
			if(heap[temp].weight>heap[2*temp].weight)
			{
				min_ind=2*temp;
				var=heap[temp].weight;
				heap[temp].weight=heap[min_ind].weight;
				heap[min_ind].weight=var;
				var=heap[temp].u;
				heap[temp].u=heap[min_ind].u;
				heap[min_ind].u=var;
				var=heap[temp].v;
				heap[temp].v=heap[min_ind].v;
				heap[min_ind].v=var;
				temp=min_ind;
			}
			else
				break;
		}
		else
			break;
	}
}				

void insert(int u,int v,int w)
{
	int temp,var;
	heapsize++;
	heap[heapsize].weight=w;
	heap[heapsize].u=u;
	heap[heapsize].v=v;
	temp=heapsize;
	while(heap[temp].weight<heap[temp/2].weight && temp>1)
	{
		var=heap[temp].weight;
		heap[temp].weight=heap[temp/2].weight;
		heap[temp/2].weight=var;
		var=heap[temp].u;
		heap[temp].u=heap[temp/2].u;
		heap[temp/2].u=var;
		var=heap[temp].v;
		heap[temp].v=heap[temp/2].v;
		heap[temp/2].v=var;
		temp=temp/2;
	}
	return;
}

int main()
{
	int n,m,i,j,flag,u,v,vv,vv1,w,shpath,count,v11,v22,v1,v2,edge_weight,par_v1,par_v2,rank1,rank2;
	heapsize=0;
	count=0;
	flag=0;
	shpath=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		A[i]=NULL;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		insert(u,v,w);
		adj_list(u,v);
		adj_list(v,u);
	}
	dfs(1);
	for(i=1;i<=n;i++)
		parent[i]=i;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("-1\n");
	else
	{
		while(count!=n-1)
		{
		edge_weight=heap[1].weight;
		v1=heap[1].u;
		v11=v1;
		v2=heap[1].v;
		v22=v2;
		deletemin();
		while(parent[v1]!=v1 && v1>=1)
			v1=parent[v1];
		par_v1=v1;
		while(parent[v2]!=v2 && v2>=1)
			v2=parent[v2];
		par_v2=v2;
	//	for(i=1;i<=n;i++)
	//		printf("rank: %d parent[%d] %d\n",rank[i],i,parent[i]);
	//	printf("\npar[%d]: %d par[%d]: %d\n",v11,par_v1,v22,par_v2);
		if(par_v1==par_v2)
			continue;
		else
		{
			rank1=rank[par_v1];
			rank2=rank[par_v2];
			if(rank1>=rank2)
			{
				rank[par_v1]++;
				vv=v22;
				parent[par_v2]=par_v1;
		//		while(parent[vv]!=vv)	
		//		{
				//	vv1=parent[vv];
//					parent[v22]=par_v1;
				//	vv=vv1;
		//		}
			}
			else
			{
				rank[par_v2]++;
				vv=v11;
			//	while(parent[vv]!=vv)
			//	{
			//		vv1=parent[vv];
					parent[par_v1]=par_v2;
			//		vv=vv1;
		//		}
			}
//			printf("u: %d v: %d weight: %d\n",v11,v22,edge_weight);
			shpath+=edge_weight;
			count++;
	//		printf("shpath: %d count: %d\n",shpath,count);
		}
		}
		printf("%d\n",shpath);
	}
	return 0;
}
