#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list* next;
}list;
list *head[10010];
typedef struct que
{
	int data;
	struct que *next;
}que;
que *queue,*tail;
void insert(int a,int b)
{
	list* node=(list*)malloc(sizeof(list));
	node->data=b;
	node->next=head[a];
	head[a]=node;
}
int prim[10010],visited[10010],distance[10010];
void push(int val)
{
	que *p=malloc(sizeof(que));
	p->data=val;
	p->next=NULL;
	if(queue==NULL)
		queue=tail=p;
	else
	{
		tail->next=p;
		tail=tail->next;
	}
}
void pop()
{
	if(queue==tail)
		queue=tail=NULL;
	else
	{
		que *p=queue;
		queue=queue->next;
		free(p);
	}
}
void bfs(int i,int j)
{
	list *k;
	push(i);
	visited[queue->data]=1;
	while(queue!=NULL)
	{
		for(k=head[queue->data];k!=NULL;k=k->next)
		{
			if(!visited[k->data])
			{
				visited[k->data]=1;
				distance[k->data]=distance[queue->data]+1;
				if(k->data==j)
				{
					while(queue!=NULL)
						pop();
					return;
				}
				push(k->data);
			}
		}
		pop();
	}
}
int main()
{
	int tc,a,b,c,d,i,j,t;
	prim[1]=prim[0]=1;
	for(i=2;i<10000;i++)
		prim[i]=0;
	for(i=2;i*i<10000;i++)
		if(!prim[i])
			for(j=2;i*j<10000;j++)
				prim[i*j]=1;
	for(i=1000;i<10000;i++)
		if(!prim[i])
		{
			t=i;
			a=(t/1000)*1000;
			t=t%1000;
			b=(t/100)*100;
			t=t%100;
			c=(t/10)*10;
			t=t%10;
			d=t;
			for(j=0;j<=9;j++)
			{
				t=a+b+c+j;
				if(t>i && !prim[t])
				{
					insert(i,t);
					insert(t,i);
				}
				t=a+b+j*10+d;
				if(t>i && !prim[t])
				{
					insert(i,t);
					insert(t,i);
				}
				t=a+j*100+c+d;
				if(t>i && !prim[t])
				{
					insert(i,t);
					insert(t,i);
				}
				t=j*1000+b+c+d;
				if(t>i && !prim[t])
				{
					insert(i,t);
					insert(t,i);
				}
			}
		}
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&a,&b);
		for(i=1000;i<10000;i++)
			visited[i]=distance[i]=0;
		bfs(a,b);
		printf("%d\n",distance[b]);
	}
	return 0;
}
