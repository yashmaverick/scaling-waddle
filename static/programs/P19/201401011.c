#include<stdio.h>
#include<stdlib.h>
#define ALPHABET_SIZE 10

typedef struct trie_node
{
	int v;
	struct trie_node *children[ALPHABET_SIZE];
}trie_node;

trie_node *newNode()
{
	trie_node *p = (trie_node*) malloc(sizeof(trie_node));
	p->v = 0;

	int i;
	for(i=0;i<ALPHABET_SIZE;i++)
		p->children[i] = NULL;

	return p;
}

int Insert( trie_node *t, char key[] )
{
//	printf("trying to insert %s.....\n",key);
	int level,node_banaya = 0;
	trie_node *position = t;

	for( level=0 ; key[level]!='\0' ; level++ )
	{
//		printf("if p is NULL mode must be made , p = %p\n",position->children[key[level]]);
		if( !position->children[key[level]-'0'] ) /* if absent */
		{
			node_banaya = 1;
			position->children[key[level]-'0'] = newNode();
		}
		else
		{
			if(position->children[key[level]-'0']->v)
			{
//				printf("%s is prefix-of-something...\n",key);
				return 0;	/* insert == false */
			}
		}

		position = position->children[key[level]-'0'];
	}
//	printf("node-banaya:%d\n",node_banaya);	
	position->v = 1;
	
	if(node_banaya)
		return 1;	/* insert == true */
	else
		return 0;
}

int main()
{
	int n, i, kar, t;
	char s[200];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		trie_node *root=newNode();

		scanf("%d",&n);
		getchar();

		kar = 1;
		for(i=0 ; i<n ; i++)
		{
			scanf("%s",s);
			if(kar)
			{
				if(!Insert(root, s))
				{
//					printf("%s last insertion\n",s);
					kar = 0;	
				}
//				printf("KAR = %d\n",kar);
			}
		}

		if(kar)
			printf("YES\n");
		else
			printf("NO\n");

		free(root);
	}
	return 0;
}
