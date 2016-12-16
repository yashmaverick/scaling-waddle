#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node *A[1005];
node *B[1005];
int visitedarray[1005];

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
int myi,count=0;
long long int globalmax=0;
void dfs(int root,long long int level)
{
//    if(A[root]==NULL)
  //  {
//	return ;
  //  }
    count++;
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
void dfs1(int root,long long int level)
{
//    if(A[root]==NULL)
  //  {
//	return ;
  //  }
    count++;
    level++;
    if(level>globalmax)
    {
	myi=root;
	globalmax=level;
    }
    visitedarray[root]=1;
    node* temp=B[root];
    while(temp!=NULL)
    {
	if(visitedarray[temp->data]==0)
	{
	    dfs1(temp->data,level);
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
	int n,i,j,p,q,x=0,winner;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    A[i]=NULL;
	    B[i]=NULL;
	}
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&p);
	    if(p!=0)
	    {
	    	for(j=0;j<p;j++)
	    	{
			scanf("%d",&q);
			adjlist(A,q,i,n);
			adjlist(B,i,q,n);
	    	}
	    }
	}
	int flag=0;
	for(i=1;i<=n;i++)
	{
	    count=0;
	    memset(visitedarray,0,sizeof(visitedarray));
	    dfs(i,0);
	    if(count==n)
	    {
		x++;
		winner=i;
		flag=1;
		break;
	    }
	}
	count=0;
	memset(visitedarray,0,sizeof(visitedarray));
	dfs1(winner,0);
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
	/*dfs(1,0);
	dfs(myi,0);
	printf("%lld",globalmax);
	printf("\n");
	*/
	if(flag!=1)
	    printf("0\n");
	else
	    printf("%d\n",count);
    }
    return 0;
}
