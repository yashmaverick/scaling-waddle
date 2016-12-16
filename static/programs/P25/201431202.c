#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define true 1
#define false 0

int dis[1000001];
int vis[1000001];
int inh[1000001];

int min(int a,int b)
{
	return a<b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

typedef struct node
{
	int city;
	int edge;
	struct node *next;
}NODE;

NODE *a[1000001];

NODE *insert(NODE *root,int data,int num)      //insert for the graph
{
	NODE *temp=malloc(sizeof(NODE));
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
	int data;
	int city;
}HEAP;

HEAP aa[1000001];

int size=0; 

void inserth(int data,int city)     //insert  for the heap
{
	size++;
	int r=size,temp;
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
		/*temp=hindex[aa[r].city];
		 * 		hindex[aa[r].city]=hindex[aa[r/2].city];
		 * 				hindex[aa[r/2].city]=temp;*/
		r=r/2;
	}
	return ;
}

int deleteh()      //delete for the heap
{
	int ret,t;
	ret=aa[1].city;
	aa[1].data=aa[size].data;
	aa[1].city=aa[size].city;
	/*hindex[aa[1].city]=hindex[aa[size].city];*/
	size--;
	int i=1,j;
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
			/*t=hindex[aa[i].city];
			 * 			hindex[aa[i].city]=hindex[aa[j].city];
			 * 						hindex[aa[j].city]=t;*/
			i=j;
		}
		else
			break;
	}
	return ret;
}

void printh()
{
	int i;
	for(i=1;i<=size;i++)
		printf("Edge length is %lld and vertex is %lld\n",aa[i].data,aa[i].city);
	return ;
}

int span=0;

int prims(int n)
{
	int start=1,value,i,j,count=0;
	for(i=1;i<=n;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=false;
	}
	dis[1]=0;
	inserth(0,start);
	while(count!=n)
	{
		int source=deleteh();
		if(vis[source]==false)
		{
			vis[source]=true;
			span=span+dis[source];
			count++;
			NODE *temp=a[source];
			while(temp!=NULL)
			{
				if(vis[temp->city]==0)
				{
					dis[temp->city]=min(dis[temp->city],temp->edge);
					inserth(dis[temp->city],temp->city);
				}
				temp=temp->next;
			}
		}
	}
	return span;
}

int main()
{
	int t=1,i,j,k,cities,index,ed,l,m,n,il,val,edge,o;
	int test1,test2,fla=0;
	while(t--)
	{
		scanf("%d %d",&n,&ed);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=ed;i++)
		{
			scanf("%d %d %d",&il,&val,&edge);
			a[il]=insert(a[il],val,edge);
			a[val]=insert(a[val],il,edge);
		}
		int prim=prims(n);
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				printf("-1\n");
				fla=1;
				break;
			}
		}
		if(fla==0)
		printf("%d\n",prim);
		for(o=1;o<=n;o++)
		{
			a[o]=NULL;
			inh[o]=0;
		}
	}
	return 0;
}
