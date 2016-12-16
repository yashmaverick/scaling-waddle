#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct List{
	int value;
	struct List *next;
}node;

void L(int x,int y);
int longest_path(node *head);

int max=0,r,count;
int visit[1000000];
node *larr[1000000];


int main()
{
	int i,j=0,t,nodes,x,y,f;
	int ans;
//	printf("Enter the number of test cases:\n");
	scanf("%d",&t);
	node *temp, *tmp;
	for(j=0;j<t;j++)
	{
//		printf("Enter the number of nodes:\n");
		scanf("%d",&nodes);
		for(i=1;i<=nodes;i++)
			larr[i]=NULL;
		if(nodes==0)
			printf("0\n");
		else if(nodes==1)
			printf("1\n");
		else
		{
			i=1;
			while(i<nodes)
			{
				scanf("%d %d",&x,&y);
				L(x,y);
				i++;
			}
			i=1;
			while(i<=nodes)
			{
				visit[i]=0;
				i++;
			}
			temp=(node *)malloc(sizeof(node));
			temp->value=x;
			temp->next=NULL;
			max=0;
			count=0;
			ans=longest_path(temp);
			i=0;
			while(i<=nodes)
			{
				visit[i]=0;
				i++;
			}
//			printf("%d\n",ans);
			tmp=(node *)malloc(sizeof(node));
			tmp->value=r;
			tmp->next=NULL;
			max=0;
			count=0;
			ans=longest_path(tmp);
			printf("%d\n",ans);
		}
	}
	return 0;
}

void L(int x,int y)
{
	node *new, *new2;
	new=(node *)malloc(sizeof(node));
	new->value=y;
	new->next=NULL;
	if(larr[x]!=NULL)
		new->next=larr[x];
	larr[x]=new;
//      printf("New Node Created.\n");

	new2=(node *)malloc(sizeof(node));
	new2->value=x;
	new2->next=NULL;
	if(larr[y]!=NULL)
		new2->next=larr[y];
	larr[y]=new2;
//      printf("New Node 2 created.\n");
}

int longest_path(node *head)
{
	while(head!=NULL)
	{
		if(visit[head->value]==0)
		{
			count++;
			if(count>max)
			{
				max=count;
				r=head->value;
			}
			visit[head->value]=1;
			longest_path(larr[head->value]);
		}
		head=head->next;
	}
	count--;
	return max;
}
