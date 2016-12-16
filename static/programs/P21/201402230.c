#include<stdio.h>
#include<stdlib.h>
#define INF 10000000000000000
typedef struct node
{
	long long int data;
	long long int weight;
	struct node *next;
}node;
typedef struct heap
{
	long long int node_val;
	long long int distance;
}heap;
node *ad[100001];
heap a[100001];
long long int distance[100001];
long long int deleted[100001];
long long int size=0;
long long int n;
long long int index_array[100001];
void insert(long long int x,long long int y,long long int w);
void dijkstra(long long int x,long long int y);
void shuffle_up(long long int n);
void shuffle_down(long long int n);
//void print(node *p);
int main()
{
	long long int n,m,x,y,w,i;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
		ad[i]=NULL;
	for(i=1;i<=n;i++)
	{	
		a[i].node_val=i;
		a[i].distance=INF;
		deleted[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&w);
		insert(x,y,w);
	}
//	for(i=1;i<=n;i++)
//	{
//		printf("%d",i);
//		print(ad[i]);
//	}
	long long int x1,x2;
	scanf("%lld %lld",&x1,&x2);
//	dijkstra(x1,x2);
	for(i=1;i<=n;i++)
	{
		if(i==x1)
			distance[i]=0;
		else
			distance[i]=INF;
	}
	dijkstra(x1,x2);
//	for(i=1;i<=n;i++)
//		printf("%lld ",distance[i]);
//	printf("\n");
	if(distance[x2]==INF)
		printf("NO\n");
	else
		printf("%lld\n",distance[x2]);
	return 0;
}
void insert(long long int x,long long int y,long long int w)
{
	node *temp;
	node *new=(node *)malloc(sizeof(node));
	new->data=y;
	new->weight=w;
	if(ad[x]==NULL)
	{
		ad[x]=new;
		new->next=NULL;
	}
	else
	{
		temp=ad[x];
		ad[x]=new;
		new->next=temp;
	}
}
void shuffle_up(long long int n)
{
	long long int now=n;
	long long int no=a[now].distance;
	heap temp;
	while(now>1 && a[now/2].distance>no)
	{
		index_array[a[now].node_val]=now/2;
		index_array[a[now/2].node_val]=now;
		temp=a[now/2];
		a[now/2]=a[now];
		a[now]=temp;
		now=now/2;
	}
}
void shuffle_down(long long int n)
{
	long long int now=n;
	long long int no=a[now].distance;
	heap temp;
	while(now<=size/2 && (a[2*now].distance<no || a[2*now+1].distance<no))
	{
		if(a[2*now].distance<a[2*now+1].distance)
		{
			index_array[a[now].node_val]=now*2;
			index_array[a[2*now].node_val]=now;
			temp=a[2*now];
			a[2*now]=a[now];
			a[now]=temp;
			now=now*2;
		}
		else
		{
			index_array[a[now].node_val]=now*2+1;
			index_array[a[2*now+1].node_val]=now;
			temp=a[2*now+1];
			a[2*now+1]=a[now];
			a[now]=temp;
			now=now*2+1;
		}
	}
}
void dijkstra(long long int x,long long int y)
{
//	printf("entered\n");
	node *p=ad[x];
	deleted[x]=2;
	while(size>=0)
	{
		while(p!=NULL)
		{
//			printf("%lld\n",p->data);
			if(distance[p->data]==INF && size!=0)
			{
//				printf("enter 1st case\n");
//				printf("%lld\n",p->data);
				distance[p->data]=distance[x]+p->weight;
//				printf("distance %lld\n",distance[p->data]);
				size++;
				a[size].node_val=p->data;
				a[size].distance=distance[p->data];
				index_array[p->data]=size;
				shuffle_up(index_array[p->data]);
				deleted[p->data]=1;
			}
			else if(deleted[p->data]==1 && size>=1)
			{
//				printf("enter 2nd case\n");
				if(distance[p->data]>distance[x]+p->weight)
				{	
					distance[p->data]=distance[x]+p->weight;
					a[index_array[p->data]].distance=distance[p->data];
				}
				long long int i=index_array[p->data];
				if(a[i].distance>a[2*i].distance || a[i].distance>a[2*i+1].distance)
					shuffle_down(i);
				else if(a[i].distance<a[i/2].distance )
					shuffle_up(i);
			}
			else if(distance[p->data]==INF && size==0)
			{
				distance[p->data]=distance[x]+p->weight;
				size++;
				a[size].node_val=p->data;
				a[size].distance=distance[p->data];
				index_array[p->data]=1;
				deleted[p->data]=1;
			}
			p=p->next;
		}
//		printf("size %lld\n",size);
		long long int num=a[1].node_val;		
		long long int i;
		a[1]=a[size];
//		for(i=1;i<=size;i++)
//			printf("%lld ",a[i].node_val);
//		printf("\n");
		size--;
		shuffle_down(1);
//		printf("size %lld\n",size);
//		for(i=1;i<=n;i++)
//			printf("%lld ",deleted[i]);
//		printf("\n");
//		printf("num %lld\n",num);
		dijkstra(num,y);
//		printf("num %lld\n",num);
	//	for(i=1;i<=n;i++)
	//		printf("%lld ",deleted[i]);
	  //     printf("\n");	
//		long long int i;
//		for(i=1;i<=size;i++)
//			printf("%d %d\n",a[i].node_val,a[i].distance);
	}
}
/*void print(node *p)
{
	while(p!=NULL)
	{
		printf("->%d",p->data);
		p=p->next;
	}
	printf("\n");
}*/
