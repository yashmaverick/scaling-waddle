#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
node* A[1009];
node* B[1009];
int check[1009]={0};
int co=0;
node* insert(node *head,int data)
{
	//printf("***%d\n",data);
	node* temp=malloc(sizeof(node));
	temp->val=data;
	temp->next=head;
	return temp;
}

void dfs(int x)
{
	node* temp=A[x];
	check[x]=1;
	while(temp!=NULL)
	{
		if(check[temp->val]==0)
		{
			check[temp->val]=1;
			dfs(temp->val);
		}

		temp=temp->next;
	}
	return;
}

void func(int x)
{
	node* temp=B[x];
	check[x]=1;
	while(temp!=NULL)
	{
		if(check[temp->val]==0)
		{
			check[temp->val]=1;
			func(temp->val);
		}
		temp=temp->next;
	}
	return;
}

int main()
{
	int n,m,i,y,s,mycnt=0,tc,j,temp,state;
	scanf("%d",&tc);
	while(tc--)
	{
		co=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&s);
			for(m=0;m<s;m++)
			{
				scanf("%d",&y);
				B[i]=insert(B[i],y);
				A[y]=insert(A[y],i);
			}
		}
		/*	mycnt=n;
			for(i=1;i<=n;i++)
			{
			dfs(i);
			for(j=1;j<=n;j++)
			{
			if(check[j]!=1)
			{
			mycnt--;
			break;
			}
			}
			for(j=1;j<=n;j++)
			check[j]=0;
			}
			printf("%d\n",mycnt);
			for(i=1;i<=n;i++)
			A[i]=NULL;*/
		temp=-1;
		for(i=1;i<=n;i++)
		{
			state=0;
			dfs(i);
			for(j=1;j<=n;j++)
			{
				if(check[j]!=1)
				{
					state=1;
					break;
				}
			}

			for(j=1;j<=n;j++)
				check[j]=0;

			if(state==0)
			{
				temp=i;//reverse-dfs for temp
				break;
			}
		}
		if(temp!=-1)
		{
			func(temp);
			for(j=1;j<=n;j++)
			{
				if(check[j]==1)
					co++;
				check[j]=0;
			}
			printf("%d\n",co);
		}
		else
			printf("0\n");
		for(i=1;i<=n;i++)
		{
			A[i]=NULL;
			B[i]=NULL;
		}
	}
	return 0;
}
