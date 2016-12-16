#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char a;
	struct node* array[10];
	int complete;
};
struct node* addint(struct node* head, char *s)
{
	int i=0,j;
	struct node* current=head;
	while(s[i]!='\0')
	{
		if (head->array[s[i]-'0'] == NULL)
		{
			struct node* newnode = malloc(sizeof(struct node));
			newnode->a=s[i];
			newnode->complete=0;
			for (j=0;j<10;j++)
				newnode->array[j]=NULL;
			head->array[s[i]-'0']=newnode;
		}
		head=head->array[s[i]-'0'];
		i++;
	}
	(head->complete)++;
	head=current;
	return head;
}
int check(struct node* head,char *a)
{
	int n=strlen(a);
	int i=0,f=0;
	for(i=0;i<n;i++)
	{
		head=head->array[a[i]-'0'];
		if(i<n-1)
		{
			if((head->complete)>=1)
			{
				f=1;
				break;
			}
		}
		else if(i==n-1)
		{
			if((head->complete)>1)
			{
				f=1;
				break;
			}
		}
	}
	if((head->complete)>1)
		f=1;
	if (f==0)
		return 0;
	else
		return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		struct node* head = malloc(sizeof(struct node));
		head->a='0';
		int i,n,j,f=0;
		for (i=0;i<10;i++)
			head->array[i]=NULL;
		head->complete=0;
		scanf("%d",&n);
		char s[100010][80];
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
			head=addint(head,s[i]);
		for (i=0;i<n;i++)
		{
			if(check(head,s[i]))
			{
				f=1;
				break;
			}
		}
		if(f==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
