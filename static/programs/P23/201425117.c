#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int depth=0,max=0,t=0;
int d[1000006];
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
int stack[1000001];
void DFS(int i)
{
	struct node *p;
	if(!b[i]){
		b[i]=1;
		p=ar[i];
		while(p!=NULL)	
		{
			if(!b[p->vertex]){
				/*dist[p->vertex]=dist[i]+1;
				if(dist[p->vertex] > depth)
				{ 
					depth=dist[p->vertex];
					max=p->vertex;
				}*/
				DFS(p->vertex);
			}
			p=p->next;
		}
	}
	stack[t]=i;
	t++;
	return ;
}
int main()
{
	int T,i,n;
	scanf("%d%d",&n,&T);
	while(T--)
	{
		depth=0;
		int n,distance,vertex;
	//	scanf("%d",&n);
		int aa,bb;
		/*for(i=1;i<=n;i++)
			ar[i]=NULL;*/
		scanf("%d%d",&aa,&bb);
		ar[aa]=insert(ar[aa],bb);
		/*memset(dist,0,sizeof(dist));
		memset(b,0,sizeof(b));
		DFS(1);
		depth=0;
		//printf("--depth is %d\n",depth);
		memset(dist,0,sizeof(dist));
		memset(b,0,sizeof(b));
		DFS(max);
		printf("%d\n",depth+1);*/
	}
	for(i=1;i<=n;i++)
		b[i]=0;
	for(i=n;i>0;i--)
		if(b[i]==0)
			DFS(i);
	for(i=t-1;i>=0;i--)
	{
		if(i==0)
			printf("%d\n",stack[i]);
		else
			printf("%d ",stack[i]);		
	}	
	return 0;
}
