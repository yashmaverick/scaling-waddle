#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int depth=0,max=0;
int dist[1000006];
int b[1000006];
struct node{
	int vertex;
	struct node *next;
};
struct node *ar[1000006];
struct node *newnode(int v)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->vertex=v;
	new->next=NULL;
	return new;
}
struct node * insert(struct node* root,int data){
	struct node *x=newnode(data);
	x->next=root;
	return x;
}
void DFS(int i)
{
	struct node *p;
	if(!b[i]){
		b[i]=1;
		p=ar[i];
		while(p!=NULL)	
		{
			if(!b[p->vertex]){
				dist[p->vertex]=dist[i]+1;
				if(dist[p->vertex] > depth)
				{ 
					depth=dist[p->vertex];
					max=p->vertex;
				}
				DFS(p->vertex);
			}
			p=p->next;
		}
	}
	return ;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		depth=0;
		int n,distance,vertex;
		scanf("%d",&n);
		int aa,bb;
for(i=1;i<=n;i++)ar[i]=NULL;
		for(i=1;i<n;i++){
			scanf("%d%d",&aa,&bb);
			ar[aa]=insert(ar[aa],bb);
			ar[bb]=insert(ar[bb],aa);
		}
		memset(dist,0,sizeof(dist));
		memset(b,0,sizeof(b));
		DFS(1);
		depth=0;
		//printf("--depth is %d\n",depth);
		memset(dist,0,sizeof(dist));
		memset(b,0,sizeof(b));
		DFS(max);
		printf("%d\n",depth+1);
	}
	return 0;
}
