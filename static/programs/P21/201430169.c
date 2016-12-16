#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define limit 100000000000000000
typedef struct node
{
	long long int dist;
	int v;
}node;
typedef struct adj
{
	int v,wt;
	struct adj* next;
}adj;	
long long int D[10000001];
int hash[1000001],visit[1000001],pvisit[1000001],p=1;
node heap[10000001];
adj* A[1000001];
void swap(int x, int y)
{
	node t=heap[x];
	heap[x]=heap[y];
	heap[y]=t;
	hash[heap[x].v]=x;
	hash[heap[y].v]=y;
}
void delmin()
{
	heap[1]=heap[p-1];
	hash[heap[1].v]=1;
	p--;
	int y=1;
	while(y<=(p-1)/2 && (heap[y].dist>heap[2*y].dist || heap[y].dist>heap[2*y+1].dist))
	{
		if(heap[2*y].dist<heap[2*y+1].dist)
		{
			swap(2*y,y);
			y*=2;
		}
		else
		{
			swap(2*y+1,y);
			y=2*y+1;
		}
	}
}
int  insert_heap(int vertex,long long int d)
{
	//node new=(node*)malloc(sizeof(node));
	//node new=heap[p];
	heap[p].dist=d;
	heap[p].v=vertex;
	hash[vertex]=p;
	p++;
	int y=p-1;
	while(y>1 && heap[y].dist<heap[y/2].dist)
	{
		swap(y,y/2);
		y/=2;
	}
	return y;
}
void insert(int x, int y,int w)
{
	adj* new=(adj*)malloc(sizeof(adj));
	new->v=y;
	new->wt=w;
	if(A[x]==NULL)
	{
		new->next=NULL;
		A[x]=new;
	}
	else
	{
		new->next=A[x];
		A[x]=new;
	}
}
int main()
{
	
	int n,m,i,j,u,v,w,s=0,t,k,x,y,cur,l;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		insert(u,v,w);
		//insert(v,u,w);
	}
	if(m>0)
		scanf("%d%d",&s,&t);
	for(i=0;i<=m;i++)
		D[i]=limit;
	if(s>0)
	{
		visit[s]=1;
		pvisit[s]=1;
	}	
	D[s]=0;	
	i=s;p=1;
	l=insert_heap(s,0);
	//hash[s]=l;
	
	while(i>0)
	{
		adj* m=A[i];
		
		while(m!=NULL)
		{
			//printf("A[%d]->%d\n",i,m->v);
			if(visit[m->v]==0)
			{
				if(D[m->v]>D[i]+m->wt)
				{
					D[m->v]=D[i]+m->wt;
					if(pvisit[m->v]==0)
					{
						//printf("pvisit is 0\n");
						k=insert_heap(m->v,D[m->v]);
						//hash[m->v]=k;
					}
					else
					{
						//printf("pvisit is 1\n");
						x=hash[m->v];
						heap[x].dist=D[m->v];
						y=x;
						if(heap[y].dist<heap[y/2].dist)
						{
							while(y>1 && heap[y].dist<heap[y/2].dist)
							{
								swap(y,y/2);
								y/=2;
							}
						}
						else
						{
							while(y<=(p-1)/2 && (heap[y].dist>heap[2*y].dist || heap[y].dist>heap[2*y+1].dist))
							{
								if(heap[2*y].dist<heap[2*y+1].dist)
								{
									swap(y,2*y);
									y=2*y;
								}
								else
								{
									swap(y,2*y+1);
									y=2*y+1;
								}
							}
						}	
						//hash[m->v]=y;
					}
					pvisit[m->v]=1;
				}
			}
			m=m->next;
		}
		//for(j=1;j<p;j++)
		//	printf("i=%d heap.v=%d heap.dist=%lld\n",j,heap[j].v,heap[j].dist);
		delmin();
		cur=heap[1].v;
		visit[cur]=1;
		//printf("cur is %d\n",cur);	
		i=cur;
	}
	if(m==0)
		printf("NO\n");
	else if(D[t]==limit || visit[t]==0)
		printf("NO\n");
	else	
		printf("%lld\n",D[t]);
	return 0;
}	




		



