#include<stdio.h>
#include<stdlib.h>
typedef struct lashit{
	int weight;
	int val;
	struct lashit* next;
}lashit;
int count,v;
int heap[1000000];
int distance[1000000];
int visit[1000000];
void insert(int value)
{
	count++;
	heap[count]=value;
	int a,temp;
	a=count;
	while(distance[heap[a]]<distance[heap[a/2]] && a>1)
	{
		temp=heap[a];
		heap[a]=heap[a/2];
		heap[a/2]=temp;
		a=a/2;
	}
}
void delmin()
{
	heap[1]=heap[count];
	heap[count]=0;
	count--;
	int a,temp;
	a=1;
	while((distance[heap[a]]>distance[heap[(2*a)+1]] ||  distance[heap[a]]>distance[heap[(2*a)]]) && (2*a)<=count)
	{
		if(distance[heap[2*a]]<distance[heap[(2*a)+1]])
		{
			temp=heap[2*a];
			heap[2*a]=heap[a];
			heap[a]=temp;
			a=2*a;
		}
		else
		{
			temp=heap[(2*a)+1];
			heap[(2*a)+1]=heap[a];
			heap[a]=temp;
			a=(2*a)+1;
		}
	}
}
void dijkstra(lashit **head )
{
	while(count!=0)
	{
		int value;
		value=heap[1];
		lashit *itr;
		itr=head[value];
		if(value==v)
			break;
		if(visit[value]==1)
			delmin();
		else
		{
			visit[value]=1;
			delmin();
			while(itr!=NULL)
			{
				if(visit[itr->val]==0)
				{	
					if(distance[itr->val]>distance[value]+(itr->weight))
					{	
						distance[itr->val]=distance[value]+(itr->weight);
						insert(itr->val);
					}
				}	
				itr=itr->next;
			}
		}
	}
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	lashit* head[1000000];
	for(i=0;i<=n;i++)
	{
		visit[i]=0;
		head[i]=NULL;
		distance[i]=1000000007;
	}
	for(i=0;i<1000000;i++)
		heap[i]=0;
	lashit *itr;
	int u,w;
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		itr=(lashit*)malloc(sizeof(lashit));
		itr->val=v;
		itr->weight=w;
		itr->next=head[u];
		head[u]=itr;
	}
	scanf("%d%d",&u,&v);
	count=1;
	heap[1]=u;
	distance[u]=0;
	dijkstra(head);
	if(distance[v]==1000000007)
		printf("NO\n");
	else
		printf("%d\n",distance[v]);
	return 0;
}
