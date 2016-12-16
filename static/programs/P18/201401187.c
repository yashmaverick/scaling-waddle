#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,top=-1;
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1001];
int n,c=1;
int st[1001],hash[1001],in[1001];
void insert(int x,int y)
{
	node* temp=NULL;
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->next=NULL;
	if(a[x]!=NULL)
	{
		temp=a[x]->next;
		new1->next=temp;
		a[x]->next=new1;
	}
	else a[x]=new1;
}
void push(int val)
{
	st[++top]=val;
}
int pop()
{
	if(top==-1)return;
	else return st[top--];
}
void tarjan(int p,int d[],int l[],int h[])
{
	int v;
	static int x=0;
	d[p]=++x;
	l[p]=x;
	push(p);
	h[p]=1;
	node* temp=a[p];
	while(temp!=NULL)
	{
		v=temp->val;
		if(d[v]==-1)
		{
			tarjan(v,d,l,h);
			l[p]=l[p]<l[v]?l[p]:l[v];
		}
		else if(h[v]==1)
			l[p]=l[p]<l[v]?l[p]:l[v];
		temp=temp->next;
	}
	int y=0;
	if(l[p]==d[p]&&top!=-1)
	{
		while(st[top]!=p&&top!=-1)
		{
			y=st[top];
			hash[y]=c;
			h[y]=0;
			pop();
		}
		if(top!=-1)
		{
			y=st[top];
			hash[y]=c;
			h[y]=0;
			pop();
			c++;

		}
	}
}
void connected()
{
	int l[1001],h[1001],d[1001],i;
	for(i=1;i<=n;i++)
	{
		d[i]=l[i]=-1;
		h[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(d[i]==-1)
			tarjan(i,d,l,h);
	}
}
void degree()
{
	int i;
	node* temp=NULL;
	for(i=1;i<=n;i++)
	{
		temp=a[i];
		while(temp!=NULL)
		{
			if(hash[temp->val]!=hash[i])
				in[hash[i]]++;
			temp=temp->next;
		}
	}
}
void initial()
{
	int i;
	for(i=1;i<=n;i++)
	{
		a[i]=NULL;
		hash[i]=0;
		in[i]=0;
	}
	return ;
}
int main()
{
	int m,i,j,b,t,v,cnt,x,y,max;
	int d[1001],l[1001],h[1001];
	node* temp=NULL;
	scanf("%d",&t);
	while(t--)
	{
		c=1;cnt=0;y=0;max=0;
		scanf("%d",&n);
		/*	for(i=1;i<=n;i++)
			{
			a[i]=NULL;hash[i]=in[i]=0;
			}*/
	/*	for(i=1;i<=n;i++)
		{
			a[i]=NULL;
			hash[i]=0;
			in[i]=0;
		}
//		return ;*/

				initial();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&v);
				insert(i,v);
			}
		}
		/*		for(i=1;i<=n;i++)
				{
				d[i]=l[i]=-1;
				h[i]=0;
				}
				for(i=1;i<=n;i++)
				{
				if(d[i]==-1)
				tarjan(i,d,l,h);
				}*/
		connected();
		degree();
		//	for(i=1;i<=n;i++)
		//		printf("%d ",hash[i]);
		//	printf("\n");
		for(i=1;i<c;i++)
		{
			//			printf("in[%d]=%d",i,in[i]);
			if(in[i]==0)
			{
				x=i;cnt++;
			}
			if(cnt>=2)
				break;
		}
		if(cnt>=2)
			printf("0\n");
		else
		{
			for(i=1;i<=n;i++)
				if(hash[i]==x)
					y++;
			printf("%d\n",y);
		}
	}
	return 0;
}
