#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Arraysize 11
struct node
{
	int value;
	struct node *children[Arraysize-1];
};
typedef struct node node;
struct trie
{
	node *root;
	int count;
};
typedef struct trie trie;
int insert(trie *y, char a[],int i,int x);
void init(trie *y);
node *newnode()
{		
	int i;
	node *b  = (node *)malloc(sizeof(node));
	b->value = 0;
	for(i = 0; i < Arraysize-1; i++)
	{
		b->children[i] = NULL;
	}
	return b;
}
int main()
{	int test;
	scanf("%d",&test);
	while(test--)
	{
		int x=0,n,i,z=0;
		char a[100];
		trie tr;
		init(&tr);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{	scanf("%s",a);
			if(x!=1)
			{		
				x=insert(&tr,a,i,0);
			}
			if(x==1)
				z=x;	
		}
		//printf("%d",z);
		if(z==1)
			printf("NO\n");
		else
		{
			//printf("%d\n",x);
			printf("YES\n");
		}
	}
	return 0;
}
void init(trie *y)
{
	y->root = newnode();
	//>value=0;
}
int insert(trie *y, char a[],int i,int x)
{
	int c, length = strlen(a), q;
	node *traverse;
	traverse= y->root;
	if(i==0)
		traverse->value=0;
	for( c = 0; c < length; c++ )
	{
		q = a[c]-'0';
		if( traverse->children[q]==NULL) 
		{
			traverse->children[q] = newnode();
			if(traverse->value==6)
			{ 
				return 1;
			}
		}
		else 
		{	
			x++;
		}
		traverse = traverse->children[q];
	}
	if(x==length)
	{
		return 1;
	}
	traverse->value = 5+1;
	return 0;
}
