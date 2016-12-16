#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie_node
{
	int value;
	int flag;
	struct trie_node * children[11];
}trie_node;
trie_node * initialise(trie_node *p,int n)
{
	p=NULL;
//	trie_node*p;
	p=(trie_node *)malloc(sizeof(trie_node));
	p->flag=0;
	p->value=n;
	int i;
	for(i=0;i <10; i++)
		p->children[i] = NULL;
//	printf("%d ",p->flag);
	return p;
}
int insert(trie_node *p,char key[]);
//trie * trie_new;
//trie_node *root;
int main()
{
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		int flag1=0,i;
		trie_node *root=NULL;
		root=(trie_node *)malloc(sizeof(trie_node));
		root->value=0;
		root->flag=-1;
		for(i=0;i<=9;i++)
			root->children[i]=NULL;
		int n;
		char c[10];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			if(flag1==0)
			{
//				printf("entered\n");
				flag1=insert(root,c);
			}
			
		}
		if(flag1==1)
			printf("NO\n");
		else if(flag1==0)
			printf("YES\n");
	}
return 0;
}
int insert(trie_node *p,char key[])
{
	int flag1=0;
	int i,m;
	int len=strlen(key);
	for(i=0;i<len;i++)
	{
		if(p->children[key[i]-'0']!=NULL)
		{
//			printf("1stcase\n");
//			printf("flag %d\n",p->flag);
			p=p->children[key[i]-'0'];
			if(p->flag==0 && i<len-1)
				flag1=1;
			else if(i==len-1 && p->flag==1)
				flag1=1;
			else if(p->flag==0 && i==len-1)
				flag1=1;
		}
		else
		{
//			printf("2ndcase\n");
//			printf("flag %d\n",p->flag);
			p->children[key[i]-'0']=initialise(p->children[key[i]-'0'],(key[i]-'0'));
			if(p->flag!=-1)
				p->flag=1;
			p=p->children[key[i]-'0'];
		}
	}	
	return flag1;
}

