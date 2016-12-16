#include<stdio.h>
#include<stdlib.h>
#define INF 100000007
typedef struct node
{
	int data;
	int weight;
	struct node *next;
}node;
int size=0;
node *a[100005];
void addedge(int i,int j,int weight)
{
	node *temp=malloc(sizeof(node));
	temp->data=i;
	temp->weight=weight;
	temp->next=a[j];
	a[j]=temp;
	temp=malloc(sizeof(node));
	temp->data=j;
	temp->weight=weight;
	temp->next=a[i];
	a[i]=temp;
}
int vis[100005];
int vert[100005];
int label[100005];
int pos[100005];
void print()
{
	int i=1;
	printf("Vertices in heap\nVertex label\n");
	for(;i<=size;i++)
	{
		printf("%d  %d\n",vert[i],label[vert[i]]);
	}
	printf("\n");
}
int min(int a,int b,int i)
{
	if(a>b)
		return 2*i+1;
	return 2*i;
}
void insert(int value,int v)
{
//	printf("%d ",value);
	int i=size+1;
	while(i>1 && label[vert[i/2]] > value)
	{
		vert[i]=vert[i/2];
		pos[vert[i]]=i;
		i=i/2;
	}
	vert[i]=v;
	label[vert[i]]=value;
	pos[vert[i]]=i;
	size++;
}
void heapify(int i)
{
	if(i>size/2)
		return ;
	int ind;
	if(2*i==size)
		ind=2*i;
	else ind=min(label[vert[2*i]],label[vert[2*i+1]],i);
	if(label[vert[i]]>label[vert[ind]])
	{
		int t=vert[i];
		
		vert[i]=vert[ind];
		vert[ind]=t;
		pos[vert[i]]=i;
		pos[vert[ind]]=ind;
		heapify(ind);
	}
}
void reducepriority(int position,int value)
{
//	printf("Before reduction of priority by value %d at position %d\n",value,position);
//	print();
	int i=position;
	int temp=vert[i];
	while(i > 1 && label[vert[i/2]] > value)
	{
		vert[i]=vert[i/2];
		pos[vert[i]]=i;
		i=i/2;
	}
	vert[i]=temp;
	label[vert[i]]=value;
	pos[vert[i]]=i;
//	heapify(i); Not required since you are only reducing priority

//	printf("After reduction of priority by value %d at position %d\n",value,position);

//	print();
}
void deletemin()
{

//	printf("Before deletemin\n");
//	print();
	int t=vert[size];
	vert[size]=vert[1];
	vert[1]=t;
	pos[vert[1]]=1;
	size--;
	heapify(1);

//	printf("After deletemin\n");

//	print();
}
void dfs(int s)
{
	vis[s]=1;
	insert(INF,s);
	node *temp=a[s];
	while(temp!=NULL)
	{
		if(!vis[temp->data])
			dfs(temp->data);
		temp=temp->next;
	}
}
int vis2[100005];
int main()
{
	int m;
	scanf("%d",&m);
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		addedge(p,q,r);
	}
	i=0;
	dfs(1);
	reducepriority(1,0);
	int sum=0;
	while(size>0)
	{
		int t=vert[1];
	//	printf("%d ",label[t]);
		sum=sum+label[t];
		deletemin();
		node *temp=a[t];
		while(temp!=NULL)
		{
			if(!vis2[temp->data])
			{
			//	printf("%d ",label[temp->data]);
				if(label[temp->data] > temp->weight)
				{
			//		printf("%d ",temp->weight);
					reducepriority(pos[temp->data],temp->weight);
				}
			}
			temp=temp->next;
		}
		vis2[t]=1;
	}
	for(i=1;i<=m;i++)
	{
		if(vis2[i]==0)
		{
			printf("-1\n");
			return ;
		}
	}
	printf("%d\n",sum);
	return 0;
}

			


	







		

	






