#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	struct ll *next;
	int data;
}node;

typedef struct nod
{
	struct nod *down;
	int data;
}stack;

node *a[1000001];
int vis[1000001];
int dist[1000001];

node *insert(int c, int d)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=d;
	temp->next=a[c];
	a[c]=temp;
	return a[c];
}

stack *push(stack* top,int val)
{
	stack *temp;
	temp=(stack*)malloc(sizeof(stack));
	temp->data=val;
	temp->down=top;
	return temp;
}

stack *pop(stack *top)
{
	if(top==NULL)
		return NULL;
	else
	{
		stack *tmp;
		tmp=top->down;
		free(top);
		return tmp;
	}
}

void print(stack *top)
{
	while(top!=NULL)
	{
		printf("%d ",top->data);
		top=top->down;
	}
}

int main()
{
	stack *top=NULL;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,u,v,tm,topdist,k,max=0,maxnode;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			a[i]=NULL;
		for(i=0;i<=n;i++)
			vis[i]=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			a[u]=insert(u,v);
			a[v]=insert(v,u);
		}
		node *g;
		i=1;
		for(k=1;k<=2;k++)
		{
			max=0;
			for(j=0;j<=n;j++)
				vis[j]=0;
			g=a[i];
			vis[i]=1;
 			top=push(top,i);
			dist[i]=0;
		
			while(top!=NULL)
			{
		//		printf("%d ",top->data);
				tm=top->data;
				
				topdist=dist[top->data];
				
				top=pop(top);
				g=a[tm];

				while(g!=NULL)
				{
					if(vis[g->data]==0)
					{
						top=push(top,g->data);
						dist[g->data]=topdist+1;
						vis[g->data]=1;
					}
					g=g->next;
				}
			}
			//	for(j=1;j<=n;j++)
			//		printf("from %d dist of %d is %d \n",i,j,dist[j]);
			//	printf("\n");
			
			for(j=1;j<=n;j++)
			{
				if(dist[j]>max)
				{
					maxnode=j;
					max=dist[j];
				}
			}
			i=maxnode;
		}
		printf("%d\n",max+1);
	}	
	return 0;		
} 
