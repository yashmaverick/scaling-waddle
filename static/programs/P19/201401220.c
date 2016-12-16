#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie
{
	int val;
	struct trie * child[10];
}trie;
trie* newnode()
{
	trie *a=NULL;
	a=(trie *)malloc(sizeof(trie));
	if(a)
	{
		int i;

		for(i=0;i<10;i++)
		{
			a->child[i]=NULL;
		}
		a->val=0;
	}
	return a;
}
int c=5;
int state;
void insert(trie *n,char a[])
{
	int i,k;
	k=strlen(a);
	trie* temp;
	temp=n;
	for(i=0;i<k;i++)
	{
		int j;
		j=(int)a[i]-(int)'0';
		if(!temp->child[j])
		{
			temp->child[j]=newnode();
		}
		temp=temp->child[j];
	}
	if(temp->val!=0)
	{
		state=1;
		temp->val=c;
	}
	else
		temp->val=c;
}
int ans(trie* n,char a[])
{
	int i,k;
	k=strlen(a);
	trie* temp;
	temp=n;
	for(i=0;i<k;i++)
	{
		int j;
		j=(int)a[i]-(int)'0';
		//if(!(temp->child[j]))
			temp=temp->child[j];
	}
	for(i=0;i<10;i++)
	{
		if(temp->child[i])
			return 1;
	}
	return 0;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		state=0;
		int n;
		scanf("%d",&n);
		char a[100001][11];
		trie *d;
		d=newnode();
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			if(state!=1)
				insert(d,a[i]);
		}
		if(state==1)
			printf("NO\n");
		if(state!=1)
		{	
			int j;
			for(i=0;i<n;i++)
			{
				j=ans(d,a[i]);
				if(j==1)
				{
					printf("NO\n");
					break;
				}
			}
			if(j==0)
				printf("YES\n");
		}
	}
	return 0;
}
