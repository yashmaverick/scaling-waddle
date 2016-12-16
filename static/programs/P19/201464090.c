#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag=0,flag2=0;
typedef struct node
{
	int val;
	int height;
	int count;
	struct node *next[10];
}node;
node *head=NULL;
void insert(char s[])
{
	int d,i,j;
	d=strlen(s);
	node *temp=head;
	for(i=0;i<d;i++)
	{
		j=s[i]-48;
		if(temp->next[j]==NULL)
		{
			node *new=malloc(sizeof(node));
			new->val=j;
			temp->next[j]=new;
			if(i==d-1)
			{
				temp->next[j]->count=0;
				temp->next[j]->height=1;
			}
			else
			{
				temp->next[j]->count=1;
				temp->next[j]->height=0;
			}
		}
		else
		{
			temp->next[j]->count==1;
                        if(i==d-1)
			{
		//		temp->next[j]->count=0;
				temp->next[j]->height=1;
			}
			if(temp->next[j]->height==0)
				temp->next[j]->height=0;
			if(temp->next[j]->height==1)
				flag2=1;
		}
		temp=temp->next[j];
	}
}
void search(node *temp)
{
	int i;
	if(flag==1)
		return;
	if(temp->count==1 && temp->height==1)
	{
		flag=1;
		return;
	}
	for(i=0;i<10;i++)
		if(temp->next[i]!=NULL)
			search(temp->next[i]);
}
int main()
{
	int t,n,flag3;
	char s[11];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		flag2=0;
		flag3=0;
		head=NULL;
		head=malloc(sizeof(node));
		head->val=10;
		head->count=1;
		head->height=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s);
			insert(s);
         	}
		search(head);
		if(flag==1 || flag2==1)
		{
			flag3=1;
			printf("NO\n");
		}
		if(flag3==0)
		{
		if(flag==0)
			printf("YES\n");
		}
	}
	return 0;
}
