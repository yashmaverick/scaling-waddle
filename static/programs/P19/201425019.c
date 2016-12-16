#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define size 10

typedef struct trie{
	int data;
	struct trie* link[size];
	int end;
}node;

node *getnode()
{
	int i;
	node *q = (node*)malloc(sizeof(node));
	for(i=0; i<size; i++)
		q->link[i]=NULL;
	q->end=0;
	return q;
}

node *root= NULL;

int insert(char key[]) 
{
	int length, i,j,c=0;
	length = strlen(key);

	if(root == NULL)
		root = getnode();
	node *q = root;  

	for(i=0; i<length; i++) 
	{
		j=key[i]-'0';
		
		if(q->link[j] == NULL)
			q->link[j] = getnode();
		q = q->link[j];

		if(q->end==1)
			c=1;
			
	}
	q->end=1;

	if(c==1)
		return 1;
	else
	{
		for(i=0; i<size; i++)
		{
			if(q->link[i]!=NULL)
				c=1;
		}
		if(c==1)
			return 1;
		else
			return 0;
	}
}

	


int main() 
{
	int n,T,i,test,flag;
	char key[100000];
	scanf("%d",&T);

	while(T--)
	{
		root=NULL;
		flag=0;
		scanf("%d", &n);
		getchar();
		for(i=0; i<n; i++)
		{
			scanf("%s",key);
			getchar();
			test=insert(key);
			if(test==1)
				flag=1;
		}
				
		if(flag==1)
			printf("NO\n");
		if(flag!=1)
			printf("YES\n");
	}
	return 0;
}

