#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag;
typedef struct TrieNode {
	int a;
	int b;
	struct TrieNode *child[10];
}node;

node *root;

node *New() 
{
	int i;
	node *x;
	x=(node *)malloc(sizeof(node));
	x->a=0;
	x->b=-1;
	for(i=0;i<10;i++)
		x->child[i]=NULL;
	return x;
}

void start() 
{
	root = New();
	flag=-1;
}

void InsEval(int str[],int size)
{
	int i,t;
	node *temp;
	temp=root;
	for(i=0;i<size;i++)
	{
		t=str[i];
		if(temp->child[t]==NULL)
		{
			temp->child[t]=New();
			temp->child[t]->b=t;
			if(i==size-1)
				temp->child[t]->a=1;
		}
		else if(temp->child[t]->b==-1)
		{
			temp->child[t]->b=t;
			if(i==size-1)
				temp->child[t]->a=1;
		}
		else if(temp->child[t]->b==t)
		{
			if(i==size-1)
			{
				flag=1;
				return;
			}
			else if(temp->child[t]->a==1)
			{
				flag=1;
				return;
			}
		}
		temp=temp->child[t];
	}
	flag=-1;
}

int main()
{
	int test,N,i,j,k,g;
	char number[10];
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d",&N);
		start();
//		a=malloc(N*sizeof(int));
		for(j=0;j<N;j++)
		{
			scanf("%s",number);
			int str[10];
			k=strlen(number);
			for(g=0;g<k;g++)
			{
				str[g]=(int)number[g]-48;
			}
			if(flag==-1)
				InsEval(str,k);
		}
		if(flag==-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
