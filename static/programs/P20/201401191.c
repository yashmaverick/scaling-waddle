#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int val;
    struct node* next;
};
void do_dfs(int,int);
void insert(int,int);
void clear(int);
int vis[1000010];
node* adj[1000010];
int depth,max,mode;
int leaf;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k,v1,v2;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            vis[i]=0;
        }
        clear(n);
        depth=0;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&v1,&v2);
            v1--;
            v2--;
            insert(v1,v2);
            insert(v2,v1);
        }
        max=0;
        mode=10;
        do_dfs(0,0);
	//printf("Leaf:%d\n",leaf);
        depth=0;
        mode=100;
        for(i=0;i<n;i++)
        {
            vis[i]=0;
        }
        do_dfs(leaf,0);
        printf("%d\n",max);
    }
}
void insert(int v1,int v2)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->val=v2;
    tmp->next=adj[v1];
    adj[v1]=tmp;
}
void do_dfs(int i,int depth)
{
    if(vis[i])
    {
        return;
    }
    vis[i]=1;
    depth++;
  //  printf("Visiting:%d\n",i+1);
    if(depth>=max)
    {
        max=depth;
        leaf=i;
    }
    node* tt;
    for(tt=adj[i];tt!=NULL;tt=tt->next)
    {
        do_dfs(tt->val,depth);
    }
}
void clear(int n)
{	
	int i;
	for(i=0;i<n;i++)
	{	
		while(adj[i]!=NULL)
		{
			node* tmp=adj[i];
			adj[i]=adj[i]->next;
			free(tmp);
		}
	} 
}
