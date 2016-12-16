#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int flag;
	int data;
	struct node *next[10];
}node;
node *root;
node * newnode()
{
	int i;
	node *p;
	p=(node *)malloc(sizeof(node));
	p->flag=0;
	p->data=-1;
	for(i=0;i<10;i++)
		p->next[i]=NULL;
	return p;
}
bool f(char *s)
{
	int i,x,n;
	n=strlen(s);
	node *head;
	head=root;
	for(i=0;s[i]!='\0';i++)
	{
		x=(int)s[i]-48;
		if(head->next[x]==NULL)
		{
			head->next[x]=newnode();
			head->next[x]->data=x;
			if(i==n-1)
				head->next[x]->flag=1;
		}
		else if(head->next[x]->data==-1)
		{
			head->next[x]->data=x;
			if(i==n-1)
				head->next[x]->flag=1;
		}
		else if(head->next[x]->data==x)
		{
			if(i==n-1)
			{
				return true;
			}
			else if(head->next[x]->flag==1)
			{
				return true;
			}
		}
		head=head->next[x];

	}
	return false;
}
		
int main()
{
	bool i;
	int test,n;
	char s[10];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
                root=newnode();
		i=false;
		while(n--)
		{
			scanf("%s",s);
			if(i==false)
				i=f(s);
		}
		if(i==false)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

