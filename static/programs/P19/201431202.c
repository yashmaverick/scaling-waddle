#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define true 1
#define false 0

typedef struct node
{
	struct node *c[10];
	int end;
}TRIE;

char a[10]={};

int flag=0;
void insert(TRIE *root,int index)
{
	if(index==strlen(a))
	{
		return ;
	}
	if(root->c[a[index]-'0']==NULL)
	{
		root->c[a[index]-'0']=malloc(sizeof(TRIE));
		if(index==strlen(a)-1)
		root->c[a[index]-'0']->end=true;
		insert(root->c[a[index]-'0'],index+1);
	}
	else
	{
		if(index==strlen(a)-1 || root->c[a[index]-'0']->end==true)
		{	
			flag=1;
			return ;
		}	
		else
			insert(root->c[a[index]-'0'],index+1);
	}
	if(flag==1)
		return ;
	return ;
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		TRIE *root=malloc(sizeof(TRIE));
		for(i=0;i<10;i++)
			root->c[i]=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			insert(root,0);
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}	
	return 0;
}
