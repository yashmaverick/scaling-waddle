#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct trie
{
	int digit[11];
	struct trie *d[11];
} node;

int gfl=0;

int check(int a[11])
{
	int i;
	for(i=0;i<11;i++)
		if(a[i]==1)
			return 1;
	return 0;
}

node* insert(node *l,char *s)
{
	if(l==NULL)
	{
		l=(node *)malloc(sizeof(node));
		memset(l->digit,0,sizeof(l->digit));
		//memset(l->d,NULL,sizeof(node *));
		int i;
		for(i=0;i<11;i++) l->d[i]=NULL;
	}
	if(s[0]=='\0')
	{
		if(check(l->digit))
			gfl=1;
		l->digit[10]=1;
		return l;
	}
	else
	{
		if(l->digit[10]==1)
		{
			gfl=1;
			return l;
		}
		l->digit[s[0]-'0']=1;
		l->d[s[0]-'0']=insert(l->d[s[0]-'0'],s+1);
		return l;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		gfl=0;
		node* root=NULL;
		while(n--)
		{
			char s[11];
			scanf("%s",s);
			if(gfl==1)
				continue;
			else
				root=insert(root,s);
		}
		free(root);
		if(gfl)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
