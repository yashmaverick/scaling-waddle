#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	int val;
	struct ll *next;
}node;

node *ar[100001];
node *x[100001];
int state[100001],count=0;
void dfs(int a)
{
	state[a]=1;
	count++;
	node *temp=ar[a];
	while(temp!=NULL)
	{
		if(state[temp->val]!=1)
			dfs(temp->val);
		temp=temp->next;
	}
	return;
}
void ndfs(int a)
{
//	printf("*%d*\n",a);
	state[a]=1;
	count++;
	node *temp=x[a];
	while(temp!=NULL)
	{
		if(state[temp->val]!=1)
			ndfs(temp->val);
		temp=temp->next;
	}
	return;
}

void insert(int a,int b)
{
	if(ar[a]==NULL)
	{
		ar[a]=(node *)malloc(sizeof(node));
		ar[a]->val=b;
		ar[a]->next=NULL;
	}
	else
	{
		node *temp=(node *)malloc(sizeof(node)),*t;
		temp->val=b;
		temp->next=ar[a];
		ar[a]=temp;
	}
}
void xinsert(int a,int b)
{
	if(x[a]==NULL)
	{
		x[a]=(node *)malloc(sizeof(node));
		x[a]->val=b;
		x[a]->next=NULL;
	}
	else
	{
		node *temp=(node *)malloc(sizeof(node)),*t;
		temp->val=b;
		temp->next=x[a];
		x[a]=temp;
	}
}

int main()
{
	int t,i,j,n,val1,val2,n2,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		for(i=1;i<=100000;i++)
		{
			free(x[i]);
			x[i]=NULL;
			free(ar[i]);
			ar[i]=NULL;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&n2);
			val1=i+1;
			while(n2--)
			{
				scanf("%d",&val2);
				insert(val2,val1);
				xinsert(val1,val2);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				state[j]=0;
			count=0;
			dfs(i);
			if(count==n)
			{
/*				for(j=1;j<=n;j++)
				{
					node *temp=x[j];
					printf("%d",j);
					while(temp!=NULL)
					{
						printf("->%d",temp->val);
						temp=temp->next;
					}
					printf("\n");
				}*/
				for(j=1;j<=n;j++)
					state[j]=0;
				count=0;
				ndfs(i);
				ans=count;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

