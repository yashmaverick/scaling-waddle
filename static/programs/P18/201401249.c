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
int sum,l,kpk;
void new(int,int,node **);
void depth(int,node **);
int main()
{
	int i,e,x,test,pnts,yy;
	node **head;
	node **head1;
	scanf("%d",&test);
	while(test>0)
	{
		scanf("%d",&pnts);
		head=(node **)malloc(sizeof(node *)*(pnts+1));
		head1=(node **)malloc(sizeof(node *)*(pnts+1));
		for(i = 1;i <= pnts;i++)
		{
			head[i] = NULL;
			head1[i] = NULL;
		}
		for(i = 1;i <= pnts;i++)

		{
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d",&e);
				new(e,i,head);
				new(i,e,head1);
			}
		}
		kpk=0;
		for(yy=1;yy <= pnts; yy++)
		{
			for(i = 1;i <= pnts;i++)
				visited[i] = 0;

			sum = 1;
			depth(yy,head);
			if(sum==pnts)
			{kpk=1;
				break;
			}
		}
		if(kpk==1)
		{
		for(i = 1;i <= pnts;i++)
			visited[i] = 0;
		sum = 1;
		depth(yy,head1);
		printf("%d\n",sum);
		}
		else
		{
			printf("0\n");
		}
		test = test-1;
	}
	return 0;
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
void depth(int i,node **head)
{
	if(head==NULL || visited[i]==1)
		return ;
	visited[i] = 1;
	node *temp = head[i];
	while(temp!=NULL)
	{
		if(visited[temp->c]!=1)
		{
			sum++;
			depth(temp->c,head);
		}
		temp = temp->next;
	}
}







































































































































































