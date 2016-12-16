#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int v;
	int w;
	struct node *next[10];
}*root;
struct node * newnode()
{
	int i;
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->v=0;
	p->w=-1;
	for(i=0;i<10;i++)
		p->next[i]=NULL;
	return p;
}
int f(char *s)
{
	int i,x,n;
	n=strlen(s);
	struct node *head;
	head=root;
	for(i=0;s[i]!='\0';i++)
	{
		x=(int)s[i]-48;
		if(head->next[x]==NULL)
		{
			head->next[x]=newnode();
			head->next[x]->w=x;
			if(i==n-1)
				head->next[x]->v=1;
//			printf("haha");
		}
		else if(head->next[x]->w==-1)
		{
			head->next[x]->w=x;
			if(i==n-1)
				head->next[x]->v=1;
		}
		else if(head->next[x]->w==x)
		{
//			printf("lala");
			if(i==n-1)
			{
				return 1;
			}
			else if(head->next[x]->v==1)
			{
				return 1;
			}
		}
		head=head->next[x];

	}
	return -1;
}
		
int main()
{
	int j=0,t,i,n;
	char s[10];
	scanf("%d",&t);
	while(j<t)
	{
		scanf("%d",&n);
                root=newnode();
		i=-1;
		while(n--)
		{
			scanf("%s",s);
			if(i==-1)
				i=f(s);
		}
		if(i==-1)
			printf("YES\n");
		else
			printf("NO\n");
		j++;
	}
	return 0;
}

