#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,top=-1;
typedef struct node
{
	int val;
	struct node* next;
}node;
node* a[1010];
int n,c=1;
int s[1010],hash[1010],indegree[1010];
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
void util(int x,int upp[],int lowest[],int hash1[])
{
	static int p=0;
	int v,y=0;
	lowest[x]=++p;
	upp[x]=lowest[x];
	s[++top]=x;
	hash1[x]=1;
	node* temp=a[x];
	while(temp!=NULL)
	{
		v=temp->val;
		if(upp[v]==-1)
		{
			util(v,upp,lowest,hash1);
			lowest[x]=min(lowest[x],lowest[v]);
		}
		else if(hash1[v]==1)
		{
			lowest[x]=min(lowest[x],upp[v]);
		}
		temp=temp->next;
	}
	if(top!=-1)
	{
		if(upp[x]==lowest[x])
		{
			while(x!=s[top])
			{
				if(top==-1)
					break;
				y=s[top];
				hash1[y]=0;
				hash[y]=c;
				if(top!=-1)
					top--;
			}
			if(top!=-1)
			{
				y=s[top];
				hash1[y]=0;
				hash[y]=c;
				if(top!=-1)
					top--;
				c++;
			}
		}
	}
}

int main()
{
	int m,i,j,b,t,v,count,r,s,max,z;
	node* temp=NULL;
	scanf("%d",&t);
	while(t--)
	{
		c=1,count=0,s=0,max=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i]=NULL;
			hash[i]=indegree[i]=0;
			//		indegree[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				/*	scanf("%d",&v);
					node* temp=NULL;
					node* new1=malloc(sizeof(node));
					new1->val=v;
					new1->next=NULL;
					if(a[i]!=NULL)
					{
					temp=a[i]->next;
					new1->next=temp;
					a[i]->next=new1;
					}
					else a[i]=new1;
					*/
				scanf("%d",&v);
				node* new1=(node*)malloc(sizeof(node));
				new1->val=v;
				if(a[i]==NULL)
				{
					a[i]=new1;
					a[i]->next=NULL;
				}
				else
				{
					new1->next=a[i];
					a[i]=new1;
				}

			}
		}
		int upp[1010],lowest[1010],hash1[1010],i;
		for(i=1;i<=n;i++)
		{
			upp[i]=-1;
			lowest[i]=-1;
			hash1[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(upp[i]==-1)
				util(i,upp,lowest,hash1);
		}
		node* temp=NULL;
		for(i=1;i<=n;i++)
		{
			temp=a[i];
			while(temp!=NULL)
			{
				z=hash[i];
				if(z!=hash[temp->val])
				{
					indegree[z]=indegree[z]+1;
				}
				temp=temp->next;
			}
		}
		for(i=1;i<c;i++)
		{
			if(indegree[i]==0)
			{
				r=i;
				count++;
			}
			if(count>=2)
			{
				break;
			}
		}
		if(count>=2)
			printf("0\n");
		else
		{
			for(i=1;i<=n;i++)
			{
				if(hash[i]==r)
				{
					s++;
				}
			}
			printf("%d\n",s);
		}
		for(i=1;i<=n;i++)
		{
			temp=a[i];
//			printf("%d--->",i);
			while(temp!=NULL)
			{
//				printf("%d ",temp->val);
				temp=temp->next;
			}
//			printf("\n");
		}
	}
	return 0;
}
