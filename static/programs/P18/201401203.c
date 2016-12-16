#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}node;
node * defeats[1001],* db[1001];
int vis[1001],sz[1001],comp[1001][2],stack[1001],mark[1001];
//int c;
int cn,head,tail;

void dfs(int i)
{
	node *cur;
	cur=defeats[i]->next;
	while(cur!=NULL)
	{
		if(vis[cur->data]==0)
		{
			vis[cur->data]=1;
			dfs(cur->data);
		}
		cur=cur->next;
	}
	if(cur==NULL)
	{
		tail++;
		stack[tail]=i;
		return;
	}
}

int scc(int i,int c)
{
	node *cur;
	cur=db[i]->next;
	while(cur!=NULL)
	{
		if(vis[cur->data]==0)
		{
			mark[cur->data]=cn;
			vis[cur->data]=1;
			c=scc(cur->data,c+1);
		}
		cur=cur->next;
	}
	if(cur==NULL)
		return c;
}

int main()
{
	int n,i,k,j,ind,t,x,v,found,sum;
	node * newnode,*tmp;
	scanf("%d",&t);
	while(t--)
	{
		head=1;tail=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			defeats[i]=(node *)malloc(sizeof(node));
			defeats[i]->data=i;
			db[i]=(node *)malloc(sizeof(node));
			db[i]->data=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&sz[i]);
			for(j=0;j<sz[i];j++)
			{
				scanf("%d",&x);
				newnode=(node *)malloc(sizeof(node));		
				newnode->data=i;
				newnode->next=defeats[x]->next;
				defeats[x]->next=newnode;
				newnode=(node *)malloc(sizeof(node));		
				newnode->data=x;
				newnode->next=db[i]->next;
				db[i]->next=newnode;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				dfs(i);
			}
		}//in defeats array
	/*	printf("stack\n");
		for(i=tail;i>=head;i--)
			printf("%d ",stack[i]);
		printf("\n");
		*///stack ready
		for(i=1;i<=n;i++)
			vis[i]=0;
		//forming the SCCs
		cn=0;
		for(i=tail;i>=head;i--)
		{
			v=stack[i];
			if(vis[v]==0)
			{
				vis[v]=1;
				cn++;
				mark[v]=cn;
				comp[cn][0]=scc(v,1);//in db array
			}
		}
		/*printf("comp size\n");
		for(i=1;i<=cn;i++)
			printf("%d %d\n",i,comp[i][0]);
		printf("mark\n");
		for(i=1;i<=n;i++)
			printf("%d ",mark[i]);
		printf("\n");
		*///find indegree for each scc
		for(i=1;i<=n;i++)
		{
			newnode=db[i]->next;
			ind=0;
			while(newnode!=NULL)
			{
				if(mark[i]!=mark[newnode->data])
					ind++;
		//	ind=sz[i]-comp[mark[i]][0]+1;
				newnode=newnode->next;
			}
			comp[mark[i]][1]+=ind;
		}
		/*printf("entire\n");
		for(i=1;i<=cn;i++)
		{
			printf("%d %d %d\n",i,comp[i][0],comp[i][1]);
		}
*/
		found=0;sum=0;
		for(i=1;i<=cn;i++)
		{
			if(comp[i][1]==0)
			{
				found++;
				sum+=comp[i][0];
			}
			if(found>1)
				break;
		}
		if(found>1)
			printf("0\n");
		else
			printf("%d\n",sum);/**/
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
			if(i<=cn)
			comp[i][1]=0;
		}
	}
	return 0;
}
