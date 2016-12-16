#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next[11];
}node;

int flag=0;

node *head=NULL;
void insert(char a[],int len)
{
	int i,j;
	node *temp=head;
	for(i=0;i<len;i++)
	{
		int var=a[i]-'0';
		if(temp->next[var]==NULL)
		{
			node *p=malloc(sizeof(node));
			p->data=var;
			for(j=0;j<11;j++)
				p->next[j]=NULL;
			temp->next[var]=p;
		}
		temp=temp->next[var];
		if(temp->next[10]!=NULL)
			flag=1;
	}

	for(j=0;j<10;j++)
	{
		if(temp->next[j]!=NULL)
			flag=1;
	}
	node *p=malloc(sizeof(node));
	p->data=-1;
	for(j=0;j<11;j++)
		p->next[j]=NULL;
	temp->next[10]=p;
}



int main()
{
	int n,l,k,j,i;
	int t,len;
	char a[15];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		head=malloc(sizeof(node));
		head->data=22;
		for(i=0;i<11;i++)
			head->next[i]=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			if(flag==0)
			{
				len=strlen(a);
				insert(a,len);
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
