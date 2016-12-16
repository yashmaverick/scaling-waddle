#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[11];
int state;
typedef struct trie
{
	char data;
	struct trie *a[11];
}trie;
trie *root;
void insert(trie *root,int l)
{
	int k=0,m;
	trie *par;
	while(k<l)
	{
		par=root;
		if(root->a[str[k]-'0']==NULL)
			break;
		root=root->a[str[k]-'0'];
		k++;
	}
	if(k==l)
	{
		par=root;
		trie *node=malloc(sizeof(trie));
		node->data='*';
		for(m=0;m<11;m++)
			node->a[m]=NULL;
		par->a[10]=node;
		state=1;
	}
	while(k<l)
	{
		if(par->a[10]!=NULL)
			state=1;
		trie *node=(trie*)malloc(sizeof(trie));
		node->data=str[k];
		for(m=0;m<11;m++)
			node->a[m]=NULL;
		par->a[str[k]-'0']=node;
		par=node;
		k++;
		if(k==l)
		{
			trie *node=malloc(sizeof(trie));
			node->data='*';
			for(m=0;m<11;m++)
				node->a[m]=NULL;
			par->a[10]=node;
		}
	}
}
void clear(trie* root)
{
	int i;
	for(i=0;i<11;i++)
	{
		if(root->a[i]!=NULL)
			clear(root->a[i]);
	}
	root=NULL;
	free(root);
}
int main()
{
	int n,i,l,j,q,tc;
	scanf("%d",&tc);
	while(tc--)
	{
		state=0;
		scanf("%d",&n);
		trie *node=(trie*)malloc(sizeof(trie));
		node->data='*';
		for(i=0;i<11;i++)
			node->a[i]=NULL;
		root=node;
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			if(!state)
			{
				l=strlen(str);
				insert(root,l);
			}
		}
		if(state==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
