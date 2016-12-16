#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
node *a[100001];
int vis[100001];
int top=-1,k;
node *insert(node *x,int y)
{
	node *new=malloc(sizeof(node));
	new->data=y;
	new->next=x;
	x=new;
	return x;
}
int stack[100001];
void push(int x)
{
	top++;
	stack[top]=x;
	
}
//void pop()
//{
//	top--;
//}
void dfs(int x)
{
	if(vis[x]==0)
	{
		node *y=a[x];
		vis[x]=1;
		while(y!=NULL)
		{
			if(vis[y->data]!=1)
			{
				
				//push(y->next->data);
				dfs(y->data);
				//y=y->next;
			}
		y=y->next; 
		}
		push(x);
		//printf(" %d %d \n",top,x);
	}
}
int main()
{
	int n,r,m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<100001;i++)
	{
		a[i]=NULL;
		vis[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x]=insert(a[x],y);
		//k=x;
	}
	for(k=n;k>0;k--)
	{
		dfs(k);
	//for(r=0;r<100001;r++)
	//	vis[r]=0;
	//printf("%d ",top);
	
	}
	for(i=top;i>0;i--)
	{
		printf("%d ",stack[i]);
		//pop();
	}
	printf("%d\n",stack[0]);
	//printf("%d\n",stack[top]);
	//pop();
	return 0;
}
