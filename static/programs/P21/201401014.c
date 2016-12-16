#include<stdio.h>
#include<stdlib.h>
# define INF 500000000000005;
struct node{
	long long int weight;
	long long int data;
	struct node *next;
};
struct heap_node{
	long long int dist;
	long long int index;
};
typedef struct node node;
typedef struct heap_node heap_node;
long long int visited[100002],position[100002];
node *A[100002];
heap_node heap[100002];

long long int min(long long int a, long long int b)
{
	if(a<b)
		return a;
	else
		return b;
}
void adj_list(long long int u,long long int v,long long int w)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->data=v;
	t->weight=w;
	t->next=NULL;
	if(A[u]==NULL)
		A[u]=t;
	else
	{
		t->next=A[u];
		A[u]=t;
	}
}

void dfs(int i)
{
	node *temp;
	visited[i]=1;
	temp=A[i];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
			dfs(temp->data);
		temp=temp->next;
	}
}

int main()
{
	long long int o,i,shpath,count,source,dest,n,m,vi,vj,wt,itemp,var,ind_root,ind,new_dist,min_ind,min_val,heapsize,tep,root;
	node *temp;
	scanf("%lld%lld",&n,&m);
	heapsize=n-1;
	count=0;
	for(i=1;i<=100001;i++)
		A[i]=NULL;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&vi,&vj,&wt);
		adj_list(vi,vj,wt);
	}
	scanf("%lld%lld",&source,&dest);
	dfs(source);
	shpath=0;
	if(visited[dest]==0)
		printf("NO\n");
	else
	{
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=1;i<source;i++)
		{
			heap[i].dist=INF;
			heap[i].index=i;
			position[i]=i;
		}
//		position[i]=-1;
		for(i=source;i<n;i++)
		{
			heap[i].dist=INF;
			heap[i].index=i+1;
			position[i+1]=i;
		}
		heap[0].dist=0;
		ind_root=position[root];
		heap[0].index=source;
		position[source]=0;
	//	heap[source]->dist=0;
/*		for(i=1;i<=n;i++)			
		{
			printf("i: %lld dist: %lld\n",i,heap[i].dist);
			printf("position: %lld \n",position[i]);
		} */
			visited[source]=1;
		root=source;
		while(visited[dest]!=1)
		{
			count++;
//			printf("while1\n");
			temp=A[root];
//			ind_root=position[root];
			while(temp!=NULL)
			{
			//	printf("while2\n");
//				printf("temp->data: %lld\n",temp->data);
				ind=position[temp->data];
//				printf("ind: %lld\n",ind);
				new_dist=shpath+temp->weight;
//				printf("prev: %lld new: %lld\n",heap[ind].dist,new_dist);
				if(new_dist<heap[ind].dist)
				{
//					printf("\ndistance update\n");
					heap[ind].dist=new_dist;
					itemp=ind;    //index of temp->data in heap
					while(heap[itemp].dist<heap[itemp/2].dist && itemp>1)
					{
						//swap respective distance,indices and positiond
						var=heap[itemp].dist;
						heap[itemp].dist=heap[itemp/2].dist;
						heap[itemp/2].dist=var;
						var=heap[itemp].index;
						heap[itemp].index=heap[itemp/2].index;
						heap[itemp/2].index=var;
						var=position[heap[itemp/2].index];
						position[heap[itemp/2].index]=position[heap[itemp].index];
						position[heap[itemp].index]=var;
						itemp=itemp/2;
				//		printf("heap[1]: %lld\n",heap[1].dist);
					}
	 			}
//				for(o=1;o<=n;o++)
//					printf("node: %lld dist: %lld\n",heap[o].index,heap[o].dist);
	 			temp=temp->next;
			}
				shpath=heap[1].dist;
//				printf("shpath: %lld\n",shpath);
				root=heap[1].index;
				//deletemin()
				heap[1].dist=heap[heapsize].dist;
				heap[1].index=heap[heapsize].index;
				position[heap[heapsize].index]=1;
				heapsize--;
				tep=1;
				while(1)
				{
					//both child exists
					if((2*tep+1)<=heapsize)
					{
						if(heap[tep].dist>min(heap[2*tep].dist,heap[2*tep+1].dist))
						{
							if(min(heap[2*tep].dist,heap[2*tep+1].dist)==heap[2*tep].dist)
								min_ind=2*tep;
							else
								min_ind=2*tep+1;
							//swapping corresponding positions,dist and indices
							var=heap[tep].dist;
							heap[tep].dist=heap[min_ind].dist;
							heap[min_ind].dist=var;
							var=heap[tep].index;
							heap[tep].index=heap[min_ind].index;
							heap[min_ind].index=var;
							var=position[heap[tep].index];
							position[heap[tep].index]=position[heap[min_ind].index];
							position[heap[min_ind].index]=var;
							tep=min_ind;
						}
						else
							break;
					}
					else if((2*tep+1)>heapsize && (2*tep)<=heapsize)
					{
						if((heap[2*tep].dist)<(heap[tep].dist))
						{
							//swap
							min_ind=2*tep;
							var=heap[tep].dist;
							heap[tep].dist=heap[min_ind].dist;
							heap[min_ind].dist=var;
							var=heap[tep].index;
							heap[tep].index=heap[min_ind].index;
							heap[min_ind].index=var;
							var=position[heap[tep].index];
							position[heap[tep].index]=position[heap[min_ind].index];
							position[heap[min_ind].index]=var;
							tep=2*tep;
						}
						else
							break;
					}
					else
						break;
			}
			visited[root]=1;
		}
		printf("%lld\n",shpath);	
	}
	return 0;
}
