#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int create=0;
typedef struct trie{
	int val;
	struct trie *A[10];
	int base;
}trie;
trie *root;
int ans=0;
trie *node(int a)
{
	int i;
	trie *new=(trie*)malloc(sizeof(trie));
	new->val=0;
	new->base=1;
	for(i=0;i<10;i++)
		new->A[i]=NULL;
	return new;
}
void insert(char s[])
{
	int l,i;
	l=strlen(s);
	trie *temp;
	temp=root;
	for(i=0;i<l;i++)
	{
		if(temp->A[s[i]-48]==NULL)
		{
			trie *new=node(s[i]-48);
			temp->A[s[i]-48]=new;
			create=1;
		}
		temp=temp->A[s[i]-48];
		temp->base=1;
	}
	temp->val=1;
	if(create==1)
		temp->base=0;
	create=0;
}
void search(trie *temp)
{
	int i,j;
	if(temp==NULL)
	{
		//printf("p");
		return ;
	}
	if(temp->val==1 && temp->base==1)
	{
		ans=1;
		return ;
	}
	for(i=0;i<10;i++)
		search(temp->A[i]);
}
int main()
{
	int i,j,n,t,k;
	char s[20];
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
	//	for(i=0;i<20;i++)
	//		s[1000]=-1;
		root=(trie*)malloc(sizeof(trie));
		root->val=0;
		for(i=0;i<10;i++)
			root->A[i]=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			insert(s);
		}
		search(root);
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
		ans=0;
	}
	return 0;
}
