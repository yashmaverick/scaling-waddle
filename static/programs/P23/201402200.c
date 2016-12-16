#include<stdio.h>
#include<stdlib.h>
typedef struct node
{   struct node* next;
    int vertex;
}node;
node* N[600001];
int n;
void dfs(int index);
void insert(int u , int v); 
void adj_list(int no_nodes,int no_edges);
int visited_arr[600001];
int stack[600001];
int top=-1;
int main()
{
    	int i,no_vertices,no_edges;
	scanf("%d%d",&no_vertices,&no_edges);
	adj_list(no_vertices,no_edges);
	for(i=no_vertices ;i>=1; i--)

//	for(i=1;i<=no_vertices ;i++)
	{
	    if(visited_arr[i]==0)
		dfs(i);
//		printf("sreeja\n");
	}
	while(top!=-1)
	{
	printf("%d",stack[top]);
	if(top!=0)
	printf(" ");
	else
	printf("\n");
	//printf("%d i am top\n",top);
	top--;
	}
    	return 0;
}
void adj_list(int no_nodes,int no_edges)
{
        	int m,i,j,ui,vi;
	    	for(i=1; i<=no_nodes ; i++)
		    {
	        	N[i]=NULL;				        	      visited_arr[i]=0;
		    }
	        	for(i=1 ; i<=no_edges ; i++)
			{					    		           scanf("%d%d",&ui,&vi);					 	insert(ui,vi);    
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
	//while(p->next!=NULL)
	//{
	r=p->next;
	p->next=q;
	q->next=r;
	//p=p->next;
	//}
	//p->next=q;
    }
}

void dfs(int index )
{
    int i,c;
    node *p;
    p=N[index];
    visited_arr[index]=1;
    while(p!=NULL)
    {
	//printf("i am inside dfs and index is==%d\n",p->vertex);
	c=p->vertex;
	if(visited_arr[c]==0)
	{
	    dfs(c);
	}
	p=p->next;
    }
    ++top;
//    printf(" %d \n",index);
    stack[top]=index;
//	printf("%d\n",stack[top]);
}

