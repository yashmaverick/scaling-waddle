#include<stdio.h>
#include<stdlib.h>
int final;
int visited[1000000];
typedef struct node
{
	int wei;
	int val;
	struct node* next;
}node;
node **head;
int count1;
void print(int v)
{
	int i;
	for(i=1;i<=v;i++)
	{
		node *p=head[i];
		while(p!=NULL)
		{
			printf("%d %d\n",p->val,p->wei);
			p=p->next;
		}
		printf("\n\n");
	}
}
void insert(int value,int f,int weight)
{
	node *new=(node*)malloc(sizeof(node));
	new->val=value;
	new->next=NULL;
	new->wei=weight;
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
	/*while(p!=NULL&&p->val<value)
	{
		q=p;
		p=p->next;
	}*/
	p=p->next;
	q->next=new;
	new->next=p;
	return;
}
void count(int a[],int ans,int i,int t)
{
	if(i==t)
	{
		count1++;
		if(count1==1)
		{
			final=ans;
		}
		else
		{
		if(final>ans)
			final=ans;
		}
	}
	else
	{
		if(i!=t)
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
					if(p->val!=t)
					a[p->val]=1;
					count(a,ans+(p->wei),p->val,t);
				}
			}
			if(p->next==NULL){
				if(a[p->val]==0)
				{
					if(p->val!=t)
					a[p->val]=1;
					count(a,ans+(p->wei),p->val,t);
				}
			}
		}
	}
	return;
}
int main()
{
	int n,i,e;
	final=0;
	count1=0;
	scanf("%d%d",&n,&e);
	if(e>0)
	{
		head=(node**)malloc((n+1)*sizeof(node));
		for(i=1;i<=n;i++)
		{
			head[i]=NULL;
		}
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		insert(b,a,w);
		for(i=1;i<e;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			insert(b,a,w);
		}
		int g[n+1];
		for(i=1;i<=n;i++)
		{
			g[i]=0;
		}
		int s,t;
		scanf("%d%d",&s,&t);
		count(g,0,s,t);
		if(count1!=0)
		printf("%d\n",final);
		else
			printf("NO\n");
}
else if (e==0)
{
	int s,t;
	scanf("%d%d",&s,&t);
printf("NO\n");
}
	return 0;
}
