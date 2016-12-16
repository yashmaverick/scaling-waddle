#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node*next;
}node;
node *A[50009],*B[50009];
int check[50009]={0};

node* insert(node *head,int data)
{
	node* temp=malloc(sizeof(node));
	temp->val=data;
	temp->next=head;
	return temp;
}
void delete(node* head)
{
	head=head->next;
	return;
}

int count=0;

void dfs(int x,int se)
{
	if(check[x]==1)
		return ;
	node *temp;
	if(se<0)
		temp=A[x];
	else
		temp=B[x];

	check[x]=1;

	while(temp!=NULL)
	{
		if(check[temp->val]==0)
		{
			count++;
			dfs(temp->val,se);
		}
		temp=temp->next;
	}
	return ;
}

int main()
{
	int n,m,i,x,y,s,state;
	int j,t,wi,max=0,o;
	scanf("%d",&t);
	while(t--)
	{
		state=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			check[i]=0;
			A[i]=NULL;
			B[i]=NULL;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			for(j=1;j<=x;j++)
			{
				scanf("%d",&y);
				A[y]=insert(A[y],i);
				B[i]=insert(B[i],y);
			}
		}
		for(o=1;o<=n;o++)
		{
			count=0;
			dfs(o,-34343434);
			if(count==n-1)
			{
				state=37489372;
				break;
			}
			for(s=1;s<=n;s++)
				check[s]=0;
		}
		if(state>0)
		{
			count=1;
			for(j=1;j<=n;j++)
				check[j]=0;
			dfs(o,343434);
			printf("%d\n",count);
		}
		else
			printf("0\n");
	}
	return 0;
}
