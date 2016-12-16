#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
struct node
{
	int c;
	struct node *next;
};
int visited[1000001];
int sum,l;
void new(int,int,node **);
void visitset(int);
void depth(int,int,node **);
int main()
{
	int i,e,x,test,pnts;
	node **head;
	scanf("%d",&test);
	while(test>0)
	{
		scanf("%d",&pnts);
		head=(node **)malloc(sizeof(node *)*(pnts+1));
		for(i = 1;i <= pnts;i++)
		{
			head[i] = NULL;
			i++;
		}
		for(i = 1;i < pnts;i++)
		{
			scanf("%d%d",&x,&e);
			new(e,x,head);
			new(x,e,head);
		}
		node *temp;
	 /*for(i = 1;i <= pnts;i++)
		{
			printf("%d->",i);
			temp=head[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->c);
				temp=temp->next;
			}
			printf("\n");
		}*/
		visitset(pnts);
		depth(1,1,head);
		visitset(pnts);
		depth(l,1,head);
		printf("%d\n",sum);
		test = test-1;
	}
	return 0;
}
void visitset(int v)
{
	int i;
	for(i = 1;i <= v;i++)
		visited[i] = 0;
	sum = 0;
}
void new(int e,int x,node **head)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->c = x;
	if(head[e]==NULL)
	{
	head[e] = temp;
	return ;
	}
	else
	{
		temp->next = head[e];
		head[e] = temp;
	}
}
void depth(int i,int sum1,node **head)
{
	if(head==NULL || visited[i]==1)
		return ;
	visited[i] = 1;
	if(sum1>sum)
	{
		sum = sum1;
	}
	l=i;
	node *temp = head[i];
	while(temp!=NULL)
	{
		if(visited[temp->c]!=1)
			depth(temp->c,sum1+1,head);
		temp = temp->next;
	}
}







































































































































































