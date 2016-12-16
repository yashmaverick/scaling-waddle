#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
int visited[100000];
struct node
{
	int data;
	struct node* next;
};
struct list
{
	struct node* head;
};
struct graph
{
	int v;
	struct list* array[10000];
};
struct graph* cgraph(int v)
{
	struct graph* graph=malloc(sizeof(struct graph));
	graph->v=v;
	int i;
	for(i=1;i<=v;i++)
	{
		graph->array[i]=malloc(sizeof(struct list));
		graph->array[i]->head=NULL;
	}
	return graph;
}
void addedge(struct graph* graph, int s, int d)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=d;
	newnode->next=graph->array[s]->head;
	graph->array[s]->head=newnode;
}
void dfs(struct graph* graph, int s)
{
	visited[s]=1;
	struct node* current=graph->array[s]->head;
	while(current!=NULL)
	{
		if(!visited[current->data])
			dfs(graph,current->data);
		current=current->next;
	}
}
int s[100000];
int r[100000];
int rev[100000];
int revv[100000];
void sieve(int a[])
{
	int i,j;
	a[1]=0;
	for(i=2;i<10000;i++)
		a[i]=1;
	for(i=2;i<10000;i++)
	{
		for(j=2;i*j<10000;j++)
			a[i*j]=0;
	}
}
void enqueue(int a[][2],int *back,int d,int d1)
{
	a[*back][0]=d;
	a[*back][1]=d1;
	(*back)++;
}
void dequeue(int *front)
{
	(*front)++;
}
int convert(char a[])
{
	return ((int)a[0]*1000+(int)a[1]*100+(int)a[2]*10+(int)a[3]);
}
int prime(int p, int b[])
{
	char a[4];
	a[3]=p%10;
	p/=10;
	a[2]=p%10;
	p/=10;
	a[1]=p%10;
	p/=10;
	a[0]=p%10;
	p/=10;
	int tmp;
	int count=0;
	char t;
	int i,j;
	for(i=0;i<4;i++)
	{
		t=a[i];
		if(i!=3)
		{
			for(j=0;j<10;j++)
			{
				if((int)a[i]!=j)
				{
					if(i==0&&j==0)
						continue;
					a[i]=j;
					tmp=convert(a);
					if(s[tmp])
						b[count++]=tmp;
				}
				a[i]=t;
			}
		}
		if(i==3)
		{
			for(j=1;j<10;j+=2)
			{	
				if((int)a[i]!=j)
				{
					if(i==0&&j==0)
						continue;
					a[i]=j;
					tmp=convert(a);
					if(s[tmp])
						b[count++]=tmp;
				}
				a[i]=t;
			}
		}
	}
	return count;
}
void bfs(struct graph* graph,int a,int b)
{
	int i;
	for(i=1;i<=1100;i++)
		visited[i]=0;
	int q[100000][2];
	int front = 0; int back = 0;
	int n=1;
	int p;
	int p1;
	int y=0;
	int j=0;
	int f=1;
	enqueue(q,&back,rev[a],y);
	visited[rev[a]]=1;
	while(n>0)
	{	
		p1=q[front][0];
		y=q[front][1];		
		p=revv[q[front][0]];
		if(p==b)
		{
			printf("%d\n",y);
			f=0;
			break;
		}
		struct node* current = graph->array[p1]->head;
		while(current!=NULL)
		{
			if(!visited[current->data])
			{
				enqueue(q,&back,current->data,y+1);
				n++;
				visited[current->data]=1;
			}
			current=current->next;
		}
		dequeue(&front);
		n--;
	}
	if(f==1)
		printf("Impossible\n");
}
int main()
{
	sieve(s);
	int n=1;
	struct graph* graph = malloc(sizeof(struct graph));
	graph = cgraph(2000);
	int i,j;
	for(i=1000;i<10000;i++)
	{
		if(s[i])
		{
			rev[i]=n;
			revv[n]=i;
			r[n++]=i;
		}
			
	}
	int tmp[10000]; int nn;
	for(i=1;i<n;i++)
	{
		nn=prime(r[i],tmp);
		for(j=0;j<nn;j++)
			addedge(graph,i,rev[tmp[j]]);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;	
		scanf("%d%d",&a,&b);
		bfs(graph,a,b);
	}
	return 0;
}
