#include<stdio.h>
#include<stdlib.h>
#define INF 100000000000000007
typedef struct node
{
	long long int data;
	long long int weight;
	struct node *next;
}node;
int size=0;
node *a[100005];
void addedge(long long int i,long long int j,long long int weight)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->weight=weight;
	temp->next=a[i];
	a[i]=temp;
//	temp=malloc(sizeof(node));
//	temp->data=j;
//	temp->weight=weight;
//	temp->next=a[i];
//	a[i]=temp;
}
long long int vis[100005];
long long int vert[100005];
long long int dist[100005];
long long int pos[100005];
void print()
{
	int i=1;
	printf("Vertices in heap\nVertex label\n");
	for(;i<=size;i++)
	{
		printf("%lld  %lld\n",vert[i],dist[vert[i]]);
	}
	printf("\n");
}
long long int min(long long int a,long long int b,long long int i)
{
	if(a>b)
		return 2*i+1;
	return 2*i;
}
void insert(long long int value,long long int v)
{
//	printf("%d ",value);
	int i=size+1;
	while(i>1 && dist[vert[i/2]] > value)
	{
		vert[i]=vert[i/2];
		pos[vert[i]]=i;
		i=i/2;
	}
	vert[i]=v;
	dist[vert[i]]=value;
	pos[vert[i]]=i;
	size++;
}
void heapify(long long int i)
{
	if(i>size/2)
		return ;
	long long int ind;
	if(2*i==size)
		ind=2*i;
	else ind=min(dist[vert[2*i]],dist[vert[2*i+1]],i);
	if(dist[vert[i]]>dist[vert[ind]])
	{
		long long int t=vert[i];
		
		vert[i]=vert[ind];
		vert[ind]=t;
		pos[vert[i]]=i;
		pos[vert[ind]]=ind;
		heapify(ind);
	}
}
void reducepriority(long long int position,long long int value)
{
//	printf("Before reduction of priority by value %lld at position %lld\n",value,position);
//	print();
	long long int i=position;
	long long int temp=vert[i];
	while(i > 1 && dist[vert[i/2]] > value)
	{
		vert[i]=vert[i/2];
		pos[vert[i]]=i;
		i=i/2;
	}
	vert[i]=temp;
	dist[vert[i]]=value;
	pos[vert[i]]=i;
//	heapify(i);

//	printf("After reduction of priority by value %lld at position %lld\n",value,position);

//	print();
}
void deletemin()
{

//	printf("Before deletemin\n");
//	print();
	long long int t=vert[size];
	vert[size]=vert[1];
	vert[1]=t;
	pos[vert[1]]=1;
	size--;
	heapify(1);

//	printf("After deletemin\n");

//	print();
}
/*void dfs(long long int s,long long int p)
{
	vis[s]=1;
	if(p==s)
		insert(0,s);
	else insert(INF,s);
	node *temp=a[s];
	while(temp!=NULL)
	{
		if(!vis[temp->data])
			dfs(temp->data,p);
		temp=temp->next;
	}
}*/
//int vis2[100005];
int main()
{
	long long int n,m;
	scanf("%lld%lld",&n,&m);
	long long int i;
	for(i=0;i<m;i++)
	{
		long long int p,q,r;
		scanf("%lld%lld%lld",&p,&q,&r);
		addedge(p,q,r);
	}
	long long int s,t;
	scanf("%lld%lld",&s,&t);
	for(i=1;i<=n;i++)
	{
		if(i!=s)
			insert(INF,i);
		else
			insert(0,i);
	}
//	reducepriority(1,0);
//	dist[vert[1]]=0;
//	long long int sum=0;
	while(size>0)
	{
		long long int t=vert[1];
//		printf("%d ",label[t]);
	//	sum=sum+[t];
		deletemin();
		node *temp=a[t];
		while(temp!=NULL)
		{
	//		if(!vis2[temp->data])
	//		{
			//	printf("%d ",label[temp->data]);
				if(dist[temp->data] > temp->weight+ dist[t])
				{
			//		printf("%d ",temp->weight);
					reducepriority(pos[temp->data],temp->weight+dist[t]);
				}
		//	}
			temp=temp->next;
		}
	//	vis2[t]=1;
	}
	if(dist[t]==INF)
		printf("NO\n");
	else
		printf("%lld\n",dist[t]);
//	printf("%d\n",dist);
	return 0;
}

			


	







		

	






