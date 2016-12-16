#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define true 1
#define false 0
#define max 100000000000

long long int dis[1000001];
long long int vis[1000001];


typedef struct node
{
	long long int city;
	long long int edge;
	struct node *next;
}NODE;

NODE *a[1000001];

NODE *insert(NODE *root,long long int data,long long int num)      //insert for the graph
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->city=data;
	temp->edge=num;
	temp->next=root;
	return temp;
}

void print(NODE *root)
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		printf("%lld ",temp->city);
		temp=temp->next;
	}
	printf("NULL\n");
	return ;
}
typedef struct heap
{
	long long int data;
	long long int city;
}HEAP;

HEAP aa[1000001];

long long int size=0; 

void inserth(long long int data,long long int city)     //insert  for the heap
{
	size++;
	long long int r=size,temp;
	aa[r].data=data;
	aa[r].city=city;
	while(r>1 && aa[r].data < aa[r/2].data)
	{
		temp=aa[r].data;
		aa[r].data=aa[r/2].data;
		aa[r/2].data=temp;
		temp=aa[r].city;
		aa[r].city=aa[r/2].city;
		aa[r/2].city=temp;
		r=r/2;
	}
	return ;
}

long long int deleteh()      //delete for the heap
{
	long long int ret,t;
	ret=aa[1].city;
	aa[1].data=aa[size].data;
	aa[1].city=aa[size].city;
	size--;
	long long int i=1,j;
	while(2*i<=size)
	{
		j=2*i;
		if(2*i+1<=size)
		{
			if(aa[2*i].data<aa[2*i+1].data)
			{
				j=2*i;
			}
			else
			{
				j=2*i+1;
			}
		}
		if(aa[j].data<aa[i].data)
		{	
			t=aa[i].data;
			aa[i].data=aa[j].data;
			aa[j].data=t;
			t=aa[i].city;
			aa[i].city=aa[j].city;
			aa[j].city=t;
			i=j;
		}
		else
			break;
	}
	return ret;
}

long long int flag=0,x=0;

void dijkstra(long long int n,long long int start,long long int end)        
{
	long long int i,r,stemp,o;
	for(i=1;i<=n;i++)
	{
		dis[i]=max;
		vis[i]=false;
	}
	dis[start]=0;
	inserth(0,start);
	while(size!=0)
	{
		long long int source=deleteh();
		NODE *temp=a[source];
		if(vis[source]==0)
		{
			while(temp!=NULL)
			{
				if(vis[temp->city]==0)
				{
					if(dis[source] + temp->edge < dis[temp->city])
					{
						dis[temp->city]=dis[source] + temp->edge;
						inserth(dis[temp->city],temp->city);
					}
				}
				temp=temp->next;
			}
			vis[source]=1;
		}
	}
	return ;
}

int main()
{
	long long int t=1,i,j,k,cities,index,ed,l,m,n,il,val,edge,o;
	long long int test1,test2;
	while(t--)
	{
		scanf("%lld %lld",&n,&ed);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=ed;i++)
		{
			scanf("%lld %lld %lld",&il,&val,&edge);
			a[il]=insert(a[il],val,edge);
		}
		scanf("%lld %lld",&test1,&test2);
		dijkstra(n,test1,test2);
		if(dis[test2]!=max)
		{
			printf("%lld\n",dis[test2]);
		}
		else
			printf("NO\n");
		for(o=1;o<=n;o++)
		{
			a[o]=NULL;
		}
	}
	return 0;
}
