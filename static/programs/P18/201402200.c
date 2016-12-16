#include<stdio.h>
#include<stdlib.h>
typedef struct node
{   struct node* next;
    int vertex;
}node;
node* N[1001];
node *M[1001];
int n;
void dfs(int index);
void dfs_reverse(int index );
void reverse_insert(int u , int v);
void insert(int u , int v);
void adj_list(int no_nodes);
int visited_arr[1001];
int val,count,flag;
int main()
{
    int i,test_cases,j,c;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
	count=0;
	int no_realms;
	scanf("%d",&no_realms);
	n=no_realms;
	adj_list(no_realms);
	val=0;
	flag=0;
	
	for(i=1 ; i<=no_realms ; i++)
	{
	    dfs(i);
	    c=0;
	    for(j=1 ; j<=n ; j++)
	    {
		if(visited_arr[j]==1)
		{
		    visited_arr[j]=0;
		    c++;
		}
	    }

//	    for(j=1 ; j<=n ; j++)
//	    {
//	    visited_arr[j]=0;
//	    }
	    if(c==n)
	    {
		flag=1;
	    }
	    if(flag==1)
	    {
		val=i;
		break;
	    }
	}
	//	printf("%d-=\n",val);
	count=0;
	//	printf("bye\n");	
	dfs_reverse(val);
	for(i=1; i<=no_realms; i++)
	{
	    if(visited_arr[i]==1)
		count++;
	}
	printf("%d\n",count);
	//	printf("%d---%d",val,count);
    }
    return 0;
}
void adj_list(int no_nodes)
{
    int m,i,j,ui;
    for(i=1; i<=no_nodes ; i++)
    {
	N[i]=NULL;
	M[i]=NULL;
	visited_arr[i]=0;
    }
    for(i=1 ; i<=no_nodes ; i++)
    {	
	scanf("%d",&m);
	for(j=0 ; j<m ; j++)
	{

	    scanf("%d",&ui);
	    insert(ui,i);
	    reverse_insert(i,ui);
	}
    }
}

void reverse_insert(int u , int v)
{
    node *p,*q,*r;
    q=(node*)malloc(sizeof(node));
    q->vertex=v;
    q->next=NULL;
    if(M[u]==NULL)
	M[u]=q;
    else
    {   
	p=M[u];
	    r=p->next;
	p->next=q;
	q->next=r;
    }   
}
void insert(int u , int v)
{
    node *p,*q,*r;
    q=(node*)malloc(sizeof(node));
    q->vertex=v;
    q->next=NULL;
    if(N[u]==NULL)
	N[u]=q;
    else
    {   
	p=N[u];
	    r=p->next;
	p->next=q;
	q->next=r;
    }   
}
void dfs(int index )
{
    int i,c=0;
    node *p;
    p=N[index];
    visited_arr[index]=1;
    while(p!=NULL)
    {
	//printf("i am inside dfs and index is==%d\n",p->vertex);
	index=p->vertex;
	if(visited_arr[index]==0)
	{
	    dfs(index);
	}
	p=p->next;

    }

}
void dfs_reverse(int index )
{
    node *p;int i;
    p=M[index];
    visited_arr[index]=1;
    while(p!=NULL)
    {
	index=p->vertex;
	if(visited_arr[index]==0)
	{
	    dfs_reverse(index);
	}
	p=p->next;
    }
}
