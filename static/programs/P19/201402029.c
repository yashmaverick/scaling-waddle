#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct trie
{
	int flag;
	struct trie *A[10];
}trie;

int a=0,count=0;

void insert(trie *root,char s[],int j)
{
	if(count==j)
	{
		return;
	}
	if(root->A[s[count]-'0']==NULL)
	{
		root->A[s[count]-'0']=(trie *)malloc(sizeof(trie));
		if(count==j-1)
		{
			root->A[s[count]-'0']->flag=1;
		}
		else
		{
			root->A[s[count]-'0']->flag=0;
		}
	}
	else
	{
		if(root->A[s[count]-'0']->flag==1 || count==j-1)
		{
			a=INT_MAX;
			return;
		}
	}
//	root=root->A[s[count]-'0'];
	count++;
	insert(root->A[s[count-1]-'0'],s,j);
	return ;
}

int main()
{
	int x,i,n,j,g=0;
	char s[11]={};
	trie *root;
	scanf("%d",&x);
	while(x--)
	{
		a=0;
		count=0;
		scanf("%d",&n);
		root=(trie *)malloc(sizeof(trie));
		trie *rootfin=root;
		for(i=0;i<10;i++)
		{
			root->A[i]=NULL;
		}
		while(n--)
		{
			count=0;
			scanf("%s",s);
			j=strlen(s);
			insert(rootfin,s,j);
		}
		if(a==INT_MAX)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
