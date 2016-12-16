#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}node;

node * a[1000010],*q;
//int d[10001],vis[10001],q[10001],pos[10001];
//node heap[10001],c;

int max=0,mark[1000010];
void dfs(node * cur,int sum)
{
	node * tmp,*t;
	tmp=cur;
	/*while(tmp->next!=NULL)
	{
		tmp=tmp->next;
		if(mark[tmp->data]==0)
		{
			mark[tmp->data]=1;
			dfs(a[tmp->data],sum+1);
		}
	}*/
	t=cur;
	tmp=cur->next;
	while(tmp!=NULL)
	{
		//printf("a\n");
		if(mark[tmp->data]==0)
		{	
			mark[tmp->data]=1;
			dfs(a[tmp->data],sum+1);
		}
		t=t->next;
		tmp=tmp->next;
	}
	if(tmp==NULL)
	{
		mark[cur->data]=0;
		if(sum>max)
		{
			max=sum;
			q=cur;
			//printf("q %d\n",q->data);
		}
		return ;
	}
}

int main()
{
	node * cur,*newnode;
	int t,i,j,k,n,x,y;
	//int i,min,j,n,v,k,t,x,e,y,w,z,p,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i]=(node *)malloc(sizeof(node));
			a[i]->data=i;
		}
		for(i=1;i<=n-1;i++)
		{
			//create adjacency list
			scanf("%d %d",&x,&y);
			newnode=(node *)malloc(sizeof(node));
			newnode->data=y;
			newnode->next=a[x]->next;
			a[x]->next=newnode;
			newnode=(node *)malloc(sizeof(node));
			newnode->data=x;
			newnode->next=a[y]->next;
			a[y]->next=newnode;
		}
		/*for(i=1;i<=n;i++)
		{
			newnode=a[i]->next;
			while(newnode!=NULL)
			{
				printf("%d ",newnode->data);
				newnode=newnode->next;
			}
			printf("\n");

		}*/
		mark[1]=1;
		max=0;
		dfs(a[1],0);
		//printf("n %d\n",newnode->next->data);
		//printf("m%d %d\n",max+1,q->data);
		/*for(i=1;i<=n;i++)
			printf("%d ",mark[i]);
		printf("\n");*/
		mark[q->data]=1;
		max=0;
		dfs(a[q->data],0);
		//printf("m%d %d\n",max+1,q->data);
		/*for(i=1;i<=n;i++)
			printf("%d ",mark[i]);
		printf("\n");*/
		printf("%d\n",max+1);
	}
	return 0;
}

