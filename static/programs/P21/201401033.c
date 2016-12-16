#include<stdio.h>
#include<stdlib.h>
#define MAX 1000009
long long int dist[MAX];
long long int check[MAX]={0}; 
long long int position[MAX];
long long int isinheap[MAX]={0};
long long int n,src;
typedef struct node
{
	long long int val;
	long long int weight;
	struct node* next;
}node;
node* A[MAX];
long long int size=0;
typedef struct heap
{
	long long int v;
	long long int w;
}heap;
heap Arr[MAX];
void shuffleup(long long int x)
{
	long long int r;
	long long int temp;
	while(x>0 & Arr[x/2].w>Arr[x].w)
	{
		temp=Arr[x].v;
		Arr[x].v=Arr[x/2].v;
		Arr[x/2].v=temp;

		temp=Arr[x].w;
		Arr[x].w=Arr[x/2].w;
		Arr[x/2].w=temp;

		r=position[Arr[x].v];
		position[Arr[x].v]=position[Arr[x/2].v];
		position[Arr[x/2].v]=r;
		x=x/2;
	}
}
void shuffledown(long long int x)
{
	long long int r;
	long long int temp;
	while(1)
	{
		int j=2*x;
		if(j>size)
			return;
		if(j+1<=size && Arr[j+1].w<Arr[j].w)
			j++;
		if(Arr[x].w>Arr[j].w)
		{
			temp=Arr[x].v;
			Arr[x].v=Arr[j].v;
			Arr[j].v=temp;

			temp=Arr[x].w;
			Arr[x].w=Arr[j].w;
			Arr[j].w=temp;

			r=position[Arr[x].v];
			position[Arr[x].v]=position[Arr[j].v]; 
			position[Arr[j].v]=r; 
			x=j;
		}
		else
			return;
	}
}

void insheap(long long int x,long long int w)
{
	size++;
	Arr[size].v=x;
	Arr[size].w=w;
	position[x]=size;
	isinheap[x]=1;
	shuffleup(size);
}

void deletemin()
{
		long long int minn=Arr[1].v;
		long long int temp=Arr[size].v,tw=Arr[size].w;
		size--;
		Arr[1].v=temp;
		Arr[1].w=tw;
		isinheap[minn]=0;
		position[minn]=0;
		position[temp]=1;
		shuffledown(1);
}

node* insert(node* head,long long int x,long long int w)
{
	node* temp=malloc(sizeof(node));
	temp->val=x;
	temp->weight=w;
	temp->next=head;
	return temp;
}

long long int cnt=0;

void func()
{
	while(size!=0)
	{
		//long long int ver=min();//min from heap
		long long int ver=Arr[1].v;
		check[ver]=1;
		long long int t,w;
		node* temp=A[ver];
		while(temp!=NULL)
		{
			t=temp->val;
			w=temp->weight;
			if(check[t]!=1)
			{
				if(dist[t]>dist[ver]+w)
				{
					dist[t]=dist[ver]+w;
					if(isinheap[t]==1)
					{
						Arr[position[t]].w=dist[t];
						shuffleup(position[t]);
					}
				}

				if(isinheap[t]==0)
					insheap(t,dist[t]);
			}
			
			temp=temp->next;
		}
		cnt++;
		deletemin();
	}
	return ;
}

int main()
{
	long long int i,x,y,w,m,tc=1,t,des,mmm;
//	scanf("%lld",&tc);
	for(mmm=0;mmm<tc;mmm++)
	{
		size=1;
		cnt=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
			dist[i]=MAX;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&w);
			A[x]=insert(A[x],y,w);
			//A[y]=insert(A[y],x,w);
		}
		scanf("%lld%lld",&src,&des);
	//	Arr[size].v=0;
	//	Arr[size].w=-MAX;
		//insheap(src,dist[src]);
		//	src=1;
		dist[src]=0;
		check[src]=1;
		cnt++;
		isinheap[src]=1;
		node* temp=A[src];
		while(temp!=NULL)
		{
			dist[temp->val]=temp->weight;
			insheap(temp->val,dist[temp->val]);
			temp=temp->next;
		}
		func();
//		for(i=1;i<=n;i++)
//
//printf("%d	",dist[i]);
		if(src>n || des>n || dist[des]==MAX)
			printf("NO\n");
		else
			printf("%lld\n",dist[des]);
		for(i=1;i<=n;i++)
		{
			check[i]=0;
			A[i]=NULL;
			position[i]=0;
			isinheap[i]=0;
		}
	}
	return 0;
}
