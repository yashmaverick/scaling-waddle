#include<stdio.h>
#include<stdlib.h>

int vis[1000005];
int height[1000005];

typedef struct list
{
	int value;
	struct list *next;
}list;
list *head[1000005];

struct queue
{
	int front;
	int last;
	int qu[1000004];
}queue;

struct stack
{
	int stk[1000004];
	int top;
}stack;

void push(int value)
{
	stack.top+=1;
	stack.stk[stack.top]=value;
}

int pop()
{
	int number;
	number=stack.stk[stack.top];
	stack.top-=1;
	return number;
}

list *insert(list *head,int val)
{
	list *new=(list *)malloc(sizeof(list));
	new->value=val;
	new->next=NULL;
	list *temp;
	temp=head;
	if(head==NULL)
	{
		head=new;
		return head;
	}
	else
	{
		new->next=temp;
		head=new;
		return head;
	}
}

void enqueue(int value)
{
	queue.last+=1;
	queue.qu[queue.last]=value;
}

void dequeue()
{
	queue.front+=1;
}

int main()
{
//	list *head[100005];
	int t,n,v1,v2;
	scanf("%d",&t);
	while(t--)
	{
		queue.front=0;
		queue.last=-1;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			head[i]=NULL;
			vis[i]=0;
		}
		int m=n-1;
		while(m--)
		{
			scanf("%d%d",&v1,&v2);
			head[v1]=insert(head[v1],v2);
			head[v2]=insert(head[v2],v1);
		}
		
		enqueue(1);
		vis[1]=1;
		int d;
		while(queue.front <= queue.last)
		{
			d=queue.qu[queue.front];
			dequeue();
			list *temp=head[d];
			while(temp!=NULL)
			{
				if(vis[temp->value]==0)
				{
					enqueue(temp->value);
					vis[temp->value]=1;
				}
				temp=temp->next;
			}
		}
		int deep=queue.qu[queue.last];
		for(i=1;i<=n;i++)
		{
			height[i]=0;
			vis[i]=0;
		}
		stack.top=-1;
		push(deep);
		int lastpop;
		vis[deep]=1;
		height[deep]=1;
		while(stack.top!=-1)
		{
			d=stack.stk[stack.top];
			lastpop=pop();
			list *temp=head[d];
			while(temp!=NULL)
			{
				if(vis[temp->value]==0)
				{
					height[temp->value]=height[lastpop]+1;
					vis[temp->value]=1;
					push(temp->value);
				}
				temp=temp->next;
			}
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(height[i]>ans)
				ans=height[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
