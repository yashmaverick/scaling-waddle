#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define node struct node
#define trie struct trie
#define s(n) scanf("%d",&n)
#define NOC 10

node
{
	int flag;
	node* C[NOC];
};

trie
{
	node* root;
	int tot;
};

node* newNode()
{
	node* p=NULL;
	p=(node*)malloc(sizeof(node));
	int i;
	for(i=0;i<NOC;i++)
		p->C[i]=NULL;
	return p;
}

void init(trie *T)
{
	T->root=NULL;
	T->root=newNode();
	T->tot=0;
}

int prefixChecker(trie *T, char A[])
{
	int i,l=strlen(A),noOfInserts=0,ret=1;
	node *k=T->root;

	for(i=0;i<l;i++)
	{	
		int I=A[i]-'0';
		if(k->flag==1)
		{	ret=0;break;}
		if(k->C[I]==NULL)
		{
			k->C[I]=newNode();
			noOfInserts++;
		}
		k=k->C[I];
	}
	k->flag=1;
	if(noOfInserts==0 || ret==0)
		return 0;
	else
		return 1;
}


int main()
{
	int t,i,n,k,j;
	s(t);
	for(i=0;i<t;i++)
	{	
		trie T;
		init(&T);
		int yOn=1,perm=1;
		char A[11];
		s(n);
		for(j=0;j<n;j++)
		{
			scanf("%s",A);
			yOn=prefixChecker(&T,A);
			if(yOn==0)
				perm=0;
		}
		if(perm==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}