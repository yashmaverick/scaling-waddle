#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node *A[1000005];
int visitedarray[1000005];

void adjlist(node **A,int p,int q,int n)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=q;
    newnode->next=NULL;
    if(A[p]==NULL)
    {
	A[p]=newnode;
    }
    else
    {
	//temp=A[p-1];
	newnode->next=A[p];
	A[p]=newnode;
    }
}
int myi;
long long int globalmax=0;
void dfs(int root,long long int level)
{
    if(A[root]==NULL)
    {
	return ;
    }
    level++;
    if(level>globalmax)
    {
	myi=root;
	globalmax=level;
    }
    visitedarray[root]=1;
    node* temp=A[root];
    while(temp!=NULL)
    {
	if(visitedarray[temp->data]==0)
	{
	    dfs(temp->data,level);
	}
	temp=temp->next;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	memset(visitedarray,0,sizeof(visitedarray));
	globalmax=0;
	int n,i,p,q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    A[i]=NULL;
	}
	for(i=1;i<=n-1;i++)
	{
	    scanf("%d%d",&p,&q);
	    adjlist(A,p,q,n);
	    adjlist(A,q,p,n);
	}
/*	for(i=1;i<=n;i++)
	{
	    node *temp=A[i];
	    printf("%d",i);
	    while(temp!=NULL)
	    {
		printf(" %d",temp->data);
		temp=temp->next;
	    }
	    printf("\n");
	}*/
	dfs(1,0);
	memset(visitedarray,0,sizeof(visitedarray));
	dfs(myi,0);
	printf("%lld",globalmax);
	printf("\n");
    }
    return 0;
}
