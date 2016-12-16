#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* next;
};

int state=0;
int count=0,n;
struct Node* mystor[1005]={NULL};
struct Node* mystor2[1005]={NULL};

int marked[1005]={0};
int marked2[1005]={0};

void dfs2(int a)
{
	struct Node* temp=mystor2[a];
	while(temp!=NULL)
	{
		if(marked2[temp->val]==0)
		{
			marked2[temp->val]=1;
			dfs2(temp->val);
		}
		temp=temp->next;
	}
}

void dfs(int a)
{
	struct Node* temp=mystor[a];
	while(temp!=NULL)
	{
		if(marked[temp->val]==0)
		{
			count++;
			marked[temp->val]=1;
			dfs(temp->val);
		}
		temp=temp->next;
	}
}

int main()
{
	int tc,a,b,c,i,j,k,m;
	scanf("%d", &tc);
	for(k=0;k<tc;k++)
	{
		count=1;
		for(i=0;i<1005;i++)
		{
			marked[i]=0;
			mystor[i]=NULL;
		}
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &m);
			for(j=0;j<m;j++)
			{
				scanf("%d", &a);
				struct Node* temp=malloc(sizeof(struct Node));
				temp->val=a;
				temp->next=mystor[i];
				mystor[i]=temp;
				struct Node* temp2=malloc(sizeof(struct Node));
				temp2->val=i;
				temp2->next=mystor2[a];
				mystor2[a]=temp2;
			}
		}
		for(i=1;i<=n;i++)
		{
			count=0;
			for(j=0;j<1005;j++)
				marked2[j]=0;
			marked2[i]=1;
			dfs2(i);
			int state2=0;
			for(j=1;j<=n;j++)
				if(marked2[j]==0)
					state2=1;
			if(state2==0)
			{
				marked[i]=1;
				//printf("%d ", i);
				count=1;
				dfs(i);
				break;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
