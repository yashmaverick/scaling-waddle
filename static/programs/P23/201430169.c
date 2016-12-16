#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int v;
	struct node* next;
}node;
node* list[1000000];
int indeg[1000000],A[1000000],h=1;
void insert_adj(int x, int y)
{
	node* new=(node*)malloc(sizeof(node));
	new->v=y;
	if(list[x]==NULL)
	{
		list[x]=new;
		new->next=NULL;
	}
	else
	{
		new->next=list[x];
		list[x]=new;
	}
	return;
}
void swap(int x,int y)
{
	int t=A[x];
	A[x]=A[y];
	A[y]=t;
}	
void insert_min(int x)
{
	A[h++]=x;
	int y=h-1;
	while(y>1 && A[y]<A[y/2])
	{
		swap(y,y/2);
		y/=2;
	}
}	
void delmin()
{
	A[1]=A[h-1];
	h--;
	int y=1;
	while(y<=(h-1)/2 && (A[y]>A[2*y] || A[y]>A[2*y+1]))
	{
		if(A[2*y]<A[2*y+1])
		{
			swap(y,2*y);
			y=2*y;
		}
		else
		{
			swap(y,2*y+1);
			y=2*y+1;
		}
	}
}
int main()
{
	int n,m,x,y,i,j,k;
	node* p;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		A[i]=1000000;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		insert_adj(x,y);
		indeg[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(indeg[i]==0)
			insert_min(i);
	}
	for(j=0;j<n;j++)
	{
		k=A[1];
		delmin();
		if(j<n-1)
			printf("%d ",k);
		else
			printf("%d",k);
		p=list[k];
		while(p!=NULL)
		{
			indeg[p->v]--;
			if(indeg[p->v]==0)
				insert_min(p->v);
			p=p->next;
		}
	}
	printf("\n");
	return 0;
}	
