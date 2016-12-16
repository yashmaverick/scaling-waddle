#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node arr[100004];
int win[100004];
int visited[100004],count,flag;
node *create(int i)
{
	node *new = (node*)malloc(sizeof(node));
	new->data = i;
	new->next = NULL;
	return new;
}
void insert(int i,int winner)
{
	node *temp;
	if(arr[winner].next == NULL)
		arr[winner].next = create(i);
	else
	{
		temp=create(i);
		temp->next=arr[winner].next;
		arr[winner].next=temp;
	}
	return;
}
void dfs(int i,node* tmp)
{
	visited[i] = 1;
	count++; 
	while(tmp!=NULL)
	{
		if(visited[tmp->data]==0)
			dfs(tmp->data,arr[tmp->data].next);
		tmp = tmp->next;
	}
	return;
}
int state=0;
void bfs(int i,node* tmp)
{
	visited[i]=1;
	if(win[i]==1)
	{
		state=1;
		return;
	}
	while(tmp!=NULL && state==0)
	{
		if(visited[tmp->data]==0)
			bfs(tmp->data,arr[tmp->data].next);
		tmp=tmp->next;
	}
	return;
}
void print(node* head)
{
	if(head==NULL)
	{
		printf("\n");
		return;
	}
	printf("%d->",head->data);
	print(head->next);
}
int main()
{    
	node *temp;
	int test,now1,j;
	scanf("%d",&test);
	while(test--)
	{
		int now,winner,i=1,ans = 0,flag=0,q = 1;
		int p,now1;
		for(p=0;p<=1005;p++)
		{
			arr[p].next = NULL;
			win[p]=0;
		}
		scanf("%d",&now);
		now1 = now;
		while(now--)
		{
			int j;
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&winner);
				insert(i,winner);
			}
			q++;
			i++;
		}
		for(i=1;i<=now1;i++)
		{
			int j;
			for(j=0;j<=now1;j++)
				visited[j] = 0;
			count = 0;
			dfs(i,arr[i].next);
			if(count == now1)
				break;	
		}
		win[i]=1;
		for(;i<=now1;i++)
		{
			int j;
			for(j=0;j<=now1;j++)
				visited[j] = 0;
			state=0;
			bfs(i,arr[i].next);
			if(state==1)
			{
				win[i]=1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
