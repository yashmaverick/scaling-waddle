#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie
{
	struct trie *next[11];
}trie;
trie *root;
long long int ans,flag;
void initialize(trie *root)
{
	int i;
	for(i=0;i<11;i++)
	{
		root->next[i]=NULL;
	}
}
void insert(trie *root,char s[],long long int i)
{
	if(i==strlen(s))
	{
		root->next[10]=(trie *)malloc(sizeof(trie));
		return ;
	}
	if(root->next[s[i]-'0']==NULL)
	{
		ans=1;
		root->next[s[i]-'0']=(trie *)malloc(sizeof(trie));
		initialize(root->next[s[i]-'0']);
	}
	if(root->next[10]!=NULL)
		flag=1;
	insert(root->next[s[i]-'0'],s,i+1);
	return ;
}
int main()
{
	long long int t,n,i;
	char str[50];
	root=(trie *)malloc(sizeof(trie));
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		initialize(root);
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			ans=0;
			scanf("%s",str);
			insert(root,str,0);
			if(ans==0)
				flag=1;
		}
		if(flag==1)
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
