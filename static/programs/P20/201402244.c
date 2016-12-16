#include<stdio.h>
#include<stdlib.h>
int final;
int ty;
int visited[1000010];
typedef struct node
{
	int val;
	struct node* next;
}node;
node **head;
void print(int v)
{
	int i;
	for(i=1;i<=v;i++)
	{
		node *p=head[i];
		while(p!=NULL)
		{
			printf("%d ",p->val);
			p=p->next;
		}
		printf("\n");
	}
}
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
	while(p!=NULL&&p->val<value)
	{
		q=p;
		p=p->next;
	}
	q->next=new;
	new->next=p;
	return;
}
void count(int a[],int ans,int i)
{
	a[i]=1;
	node *p=head[i];
	if(p!=NULL)
	{
		while(p->next!=NULL)
		{
			while(a[p->val]!=0&&p->next!=NULL)
			{
				p=p->next;
			}
			if(a[p->val]==0)
			{
				a[p->val]=1;
				count(a,ans+1,p->val);
			}
		}
		if(p->next==NULL)
		{
			if(a[p->val]==0)
			{
				a[p->val]=1;
				count(a,ans+1,p->val);
			}
		}
	}
	if(final<ans)
	{
		final=ans;
		ty=i;

	}
	return;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,i;
		final=0;
		scanf("%d",&n);
		if(n>1){
			head=(node**)malloc((n+1)*sizeof(node));
			for(i=1;i<=n;i++){
				head[i]=NULL;
			}
			int a,b;
			scanf("%d%d",&a,&b);
			insert(a,b);
			insert(b,a);
			for(i=1;i<n-1;i++)
			{
				scanf("%d%d",&a,&b);
				insert(a,b);
				insert(b,a);
			}
			int g[n+1];
			int j;
				for(j=1;j<=n;j++)
				{
					g[j]=0;
				}
				count(g,1,i);
				for(j=1;j<=n;j++)
				{
					g[j]=0;
				}
				count(g,1,ty);

			printf("%d\n",final);
		}
		else if (n==0)
			printf("0\n");
		else if (n==1)
			printf("1\n");
	}
	return 0;
}
