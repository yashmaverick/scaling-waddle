#include<stdio.h>
#include<stdlib.h>
int stk[1000000],V[1000000],sp=0;
typedef struct node
{
	int val;
	struct node* next;
}node;
node *head[1000000];
void insert( int u , int v )
{
	node *tmp;
	node* p=(node*)malloc(sizeof(node));
	p->val=v;
	p->next=head[u]->next;
	head[u]->next=p;
	return;
	node* e=(node*)malloc(sizeof(node));
	e->val=v;
	e->next=NULL;
	if( head[u]->next==NULL )
	/*	head[u]->next=e*/;
	else
	{
		//tmp=head[u]->next;
		//e->next=tmp;
		//head[u]->next=e;
	}
}
int dfs( int v )
{
	if( V[v]==1 )
		return;
	V[v]=1;
	node* k=head[v]->next;
	while( k!=NULL )
	{
		dfs(k->val);
		k=k->next;
	}
	//printf("V %d\n",v);
	stk[sp]=v;
	sp++;
	return 1;
}
int main()
{
	int n,m,u,v,i;
	scanf("%d%d",&n,&m);
	for( i=1  ; i<=n ; i++ )
	{
		head[i]=(node*)malloc(sizeof(node));
		head[i]->val=i;
		head[i]->next=NULL;
	}
	for( i=1 ; i<=m ; i++ )
	{
		scanf("%d%d",&u,&v);
		insert( u,v);
	}
	for(i=1;i<=n;i++)
	{
		node*p;
		p=head[i]->next;
		while(p!=NULL)
		{
	//		printf("%d ",p->val);
			p=p->next;
		}
//		printf("\n");
	}
	while(n--)
	{
	dfs( n+1 );
	}
	for( i=sp-1 ; i>0 ; i-- )
		printf("%d ",stk[i]);
	printf("%d\n",stk[0]);
		return 0;
}

