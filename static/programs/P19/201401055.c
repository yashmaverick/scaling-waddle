#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	char c;
	int data;
	struct node *next[10];
}*root;
struct node * enter()
{
	int i;
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->c='n';
	p->data=1;
	for(i=0;i<10;i++)
		p->next[i]=NULL;
	return p;
}
int find_pref(char *arr)
{
	int i,n;
	n=strlen(arr);
	struct node *head;
	head=root;
	for(i=0;i<n;i++)
	{
		if(head->next[(int)arr[i]-48]==NULL)
		{
			head->next[(int)arr[i]-48]=enter();
			head->next[(int)arr[i]-48]->data=0;
			if(i==n-1)
				head->next[(int)arr[i]-48]->c='y';
		}
		else if(head->next[(int)arr[i]-48]->data==1)
		{
			head->next[(int)arr[i]-48]->data=0;
			if(i==n-1)
				head->next[(int)arr[i]-48]->c='y';
		}
		else if(head->next[(int)arr[i]-48]->data==0)
		{
			if(i==n-1)
			{
				return 1;
			}
			else if(head->next[(int)arr[i]-48]->c=='y')
			{
				return 1;
			}
		}
		head=head->next[(int)arr[i]-48];

	}
	return 0;
}	
int main()
{
	int j=0,t,i,n,flag;
	char arr[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
                root=enter();
		i=-1;
		flag=0;
		while(n--)
		{
			scanf("%s",arr);
			i=find_pref(arr);
			if(i==1)
				flag=1;
		}
		if(flag!=0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

