#include<stdio.h>
#include<stdlib.h>
#define inf 1000000010
int front=-1,rear=-1,top=-1,flag=0;
long long int sum=0;
typedef struct node
{
	int val;
	int weight;
	struct node* next;
}node;
node* a[1000009];
typedef struct Node
{
	int vertex;
	int dis;
}Node;
Node heap[1000009];
int dis[1000009],pos[1000009];
int hsize;
//heap[0].distance=-1000000;
//heap[0].vertex=-1;
void insert(int x,int y,int z)
{
	node* temp=NULL;
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->weight=z;
	new1->next=NULL;
	if(a[x]!=NULL)
	{
		temp=a[x]->next;
		new1->next=temp;
		a[x]->next=new1;
	}
	else a[x]=new1;
	new1->next=temp;
	//vice versa
		node* new2=malloc(sizeof(node));
		new2->val=x;
		new2->weight=z;
		new2->next=NULL;
		if(a[y]!=NULL)
		{
		temp=a[y]->next;
		new2->next=temp;
		a[y]->next=new2;
		}	
		else a[y]=new2;
}
//int hsize=0;
//heap[0].dis=1000000;
//heap[0].vertex=0;
void insertheap(Node x)
{
	int w;
	hsize=hsize+1;
	heap[hsize]=x;
	w=hsize;
	while(w/2!=0&&heap[w/2].dis>x.dis)
	{
		heap[w]=heap[w/2];
		w=w/2;
	}
	heap[w]=x;
	pos[x.vertex]=w;
}
void change(int x,int y)
{
	int ch1,ch2,small;
	ch1=2*x;
	ch2=2*x+1;
	if(ch1<=y)
	{
		small=ch1;
		if(ch2<=y)
		{
			if(heap[ch2].dis<heap[ch1].dis)
				small=ch2;
		}
	if(heap[x].dis>heap[small].dis)
	{
		Node smallest,beg;
		smallest=heap[small];
		beg=heap[x];
		int i=smallest.vertex,j=heap[x].vertex;
		pos[i]=x;
		pos[j]=small;
		Node temp;
		temp=heap[small];
		heap[small]=heap[x];
		heap[x]=temp;
		change(small,y);
	}
	}
}
void delmin()
{
	if(hsize>0)
	{
		Node top=heap[1];
		Node last=heap[hsize];
		heap[1]=last;
		pos[last.vertex]=1;
		pos[top.vertex]=hsize;
		hsize--;
		change(1,hsize);
	}
}
void updateheap(int src)
{
	int w=pos[src];
	Node tempheap;
	heap[w].dis=dis[src];
	while(w>1&&heap[w/2].dis>heap[w].dis)
	{
		pos[heap[w].vertex]=w/2;
		pos[heap[w/2].vertex]=w;
		tempheap=heap[w];
		heap[w]=heap[w/2];
		heap[w/2]=tempheap;
		//pos[heap[w].vertex]=w/2;
		//pos[heap[w/2].vertex]=w;
		w=w/2;
	}
}
int main()
{
	int src,dest,i,j,v,e,x,y,z;
	node* temp=NULL;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
	}
//	scanf("%d%d",&src,&dest);
	//Heap temp;
	for(i=1;i<=v;i++)
	{
		dis[i]=inf;
		heap[i].vertex=i;
		heap[i].dis=inf;
		pos[i]=i;
	}
/*	for(i=1;i<=v;i++)
	{
		temp=a[i];
//		printf("i is %d:\n",i);
		while(temp)
		{
//			printf("	%d = %d\n",temp->val,temp->weight);
			temp=temp->next;
		}
		printf("\n");
	}*/
	hsize=v;
	dis[1]=0;
	updateheap(1);
	while(hsize>0)
	{
	//if(dis[top.vertex]!=inf)
	//sum+=dis[top.vertex];
	//	if(top.vertex==dest)
	temp=a[heap[1].vertex];
//	printf("%d : %d\n",heap[1].vertex,heap[1].dis);
	if(dis[heap[1].vertex]!=inf)
		sum+=dis[heap[1].vertex];
	delmin();
	while(temp)
	{
		if(pos[temp->val]<=hsize&&dis[temp->val]>temp->weight)
		{
			dis[temp->val]=temp->weight;

//		printf("before   %d: %d\n",temp->val,temp->weight);
			updateheap(temp->val);
		
//		printf("after   %d: %d\n",temp->val,heap[pos[temp->val]].dis);
		}
		temp=temp->next;
	}
//	Node top2;
//	delmin();
	}
	for(i=1;i<=v;i++)
	{
		if(dis[i]==inf)
		{
			flag=1;
			break;
		}
	}
	//	printf("%d  ",dis[i]);
//	printf("\n");
	//if(dis[dest]!=inf)
//	printf("%d\n",dis[dest]);
//	else printf("NO\n");
	if(flag==1)
		printf("-1\n");
	else printf("%lld\n",sum);
	return 0;
}



