#include<stdio.h>
#include<stdlib.h>
int top;
int vst[1000000];
int stack[1000000];
int visited[1000000];
void push(int a)
{
	top++;
	stack[top]=a;
}
void pop(int a)
{
	if(a!=0)
	printf("%d ",stack[top]);
	else
		printf("%d\n",stack[top]);
	top--;
}
typedef struct node
{
	int val;
	struct node* next;
}node;
node **head;
void insert(int value,int f)
{
	node *new=(node*)malloc(sizeof(node));
	new->val=value;
	new->next=NULL;
	node *p=head[f];
	node *q=head[f];
	if(head[f]==NULL)
	{
		head[f]=new;
		return;
	}
	if(value<=p->val)
	{
		new->next=head[f];
		head[f]=new;
		return;
	}
	p=p->next;
	q->next=new;
	new->next=p;
	return;
}
void count(int i)
{
	visited[i]=1;
	node *p=head[i];
	if(p!=NULL)
	{
		while(p->next!=NULL)
		{
			while(visited[p->val]!=0&&p->next!=NULL)
			{
				p=p->next;
			}
			if(visited[p->val]==0)
			{
				visited[p->val]=1;
				count(p->val);
			}
		}
		if(p->next==NULL)
		{
			if(visited[p->val]==0)
			{
				visited[p->val]=1;
				count(p->val);
			}
		}
	}
	push(i);
	return;
}
int main()
{
	top=-1;
	int n,i,m;
	scanf("%d%d",&n,&m);
	head=(node**)malloc((n+1)*sizeof(node));
	for(i=1;i<=n;i++)
		{
			head[i]=NULL;
		}
	int a,b;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		vst[a]=1;
		vst[b]=1;
		insert(b,a);
	}
	int j;
	for(j=1;j<=n;j++)
	{
		visited[j]=0;
	}
	for(i=n;i>=1;i--)
	{
		if(visited[i]==0)
		count(i);
	}
	for(i=top;i>=0;i--)
		pop(i);
	return 0;
	}
