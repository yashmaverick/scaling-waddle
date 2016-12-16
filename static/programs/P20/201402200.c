#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node* next;
    int vertex;
}node;
node* N[1000000];
void adj_list(int no_nodes);
int visited_arr[1000000];
void dfs(int index , int depth );
void insert(int u , int v);
int maxdepth;
int val;
int main()
{
    int i,test_cases,no;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
	//val=0;
	maxdepth=0;
	//int N;
	scanf("%d",&no);
	adj_list(no);
	dfs(1,0);
	maxdepth=0;
//	printf("i am calling 2nd time\n");
	for(i=1 ; i<=no ; i++)
	visited_arr[i]=0;
	dfs(val,0);
	    printf("%d\n",maxdepth+1);
    }
    return 0;
}
void dfs(int index,int depth )
{
    node *p;
    p=N[index];
    visited_arr[index]=1;
    if(depth>maxdepth)
    {
	maxdepth=depth;
    	val=index;
    }
    while(p!=NULL)
    {
  //  printf("i am ==%d\n",p->vertex);
    index=p->vertex;
    if(visited_arr[index]==0)
    {
    dfs(index,depth+1);
    }
    p=p->next;
    }
    //printf("index=%d\nmaxdepth=%d\ndepth=%d\nvalue=%d\n",index,maxdepth,depth,val);
}
void adj_list(int no_nodes)
{
    int i,ui,vi;
    for(i=1; i<=no_nodes ; i++)
    {
	N[i]=NULL;
	visited_arr[i]=0;
    }
    for(i=0 ; i<no_nodes-1 ; i++)
    {
	scanf("%d%d",&ui,&vi);
	insert(ui,vi);
	insert(vi,ui);
    }
}
void insert(int u , int v)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=v;
    q->next=NULL;
	if(N[u]==NULL)
	    N[u]=q;
	else
	{
	p=N[u];
	while(p->next!=NULL)
	    p=p->next;
	p->next=q;
	}
}

