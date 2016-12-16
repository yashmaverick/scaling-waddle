#include<stdio.h>
#include<stdlib.h>
int final;
int visited[1000010];
typedef struct node
{
	int val;
	struct node* next;
}node;
node **head;
node **head1;
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
void insert1(int value,int f)
{
	node *new=(node*)malloc(sizeof(node));
	new->val=value;
	new->next=NULL;
	node *p=head1[f];
	node *q=head1[f];
	if(head1[f]==NULL)
	{
		head1[f]=new;
		return;
	}
	if(value<=p->val)
	{
		new->next=head1[f];
		head1[f]=new;
		return;
	}
	p=p->next;
	q->next=new;
	new->next=p;
	return;
}
void count(int a[],int ans,int i)
{
	final++;
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
	return;
}
void count1(int a[],int ans,int i)
{
	final++;
	a[i]=1;
	node *p=head1[i];
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
				count1(a,ans+1,p->val);
			}
		}
		if(p->next==NULL)
		{
			if(a[p->val]==0)
			{
				a[p->val]=1;
				count1(a,ans+1,p->val);
			}
		}
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
			head1=(node**)malloc((n+1)*sizeof(node));
			for(i=1;i<=n;i++){
				head[i]=NULL;
				head1[i]=NULL;
			}
			int a,b,u;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a);
				for(u=1;u<=a;u++)
				{
					scanf("%d",&b);
					insert(i,b);
					insert1(b,i);
				}
			}
			int g[n+1];
			int j;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					g[j]=0;
				}
				final=0;
				count(g,1,i);
				if(final==n)
				break;
			}
			for(j=1;j<=n;j++)
			{
				g[j]=0;
			}
			if(final==n)
			{
				final=0;
			count1(g,1,i);
			}
			else 
				final=0;
			printf("%d\n",final);
		}
	}
	return 0;
}
