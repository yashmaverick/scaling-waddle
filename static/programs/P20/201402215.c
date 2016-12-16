#include<stdio.h>
#include<stdlib.h>
int max=1,visited[1000001],l;
struct node{
	int val;
	struct node *next;
};
typedef struct node node;
node* insert(node *head,int y)
{
	if(head==NULL)
	{
		node *temp=NULL;
		temp=(node*)malloc(sizeof(node));
		temp->val=y;
		temp->next=NULL;
		return temp;
	}
	else
	{	head->next=insert(head->next,y);
			return head;
	}
}
void print(node *head)
{
	if(head==NULL)
		return ;
	else
	{	printf("%d ",head->val);
		print(head->next);
	}
}
void dfs(node *k[],int i,int count,int visited[])
{
	node *head=k[i];
	
	if(count>max)
	{
		//printf("%d %d\n",head->val,count);
	}
		visited[i]=1;
		while(head!=NULL)
		{
		
			if(visited[head->val]==0)
			{
				//printf("value with which dfs is called %d and count is %d \n",head->val,count);
				
				dfs(k,head->val,count+1,visited);
				if(count+1>max)
				{
					max=count+1;
					l=head->val;
				}
			}
		head=head->next;
		}
		//printf("%d\n",count);
//		printf("p is %d\n",p);
		visited[i]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,x,y;
		max=1;
		node* k[1000001]={NULL};
		scanf("%d",&n);
		for(i=1;i<n;i++)
			k[i]=NULL;
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			visited[i]=0;
			k[x]=insert(k[x],y);
			k[y]=insert(k[y],x);
		}
		visited[n]=0;
	//	for(i=1;i<=n;i++)
	//	{	printf("%d ",i);
	//		print(k[i]);
	//	printf("\n");
	//	}
			dfs(k,1,1,visited);
			dfs(k,l,1,visited);
		printf("%d\n",max);
	}
	return 0;
}


