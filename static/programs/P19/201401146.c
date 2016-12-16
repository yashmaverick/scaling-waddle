#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie trie;
struct trie
{
	int ter;
	trie *num[10];
};
int l;
trie *head=NULL;
trie* make_trie()
{
	trie *tmp;
	int i;
	tmp=(trie*)malloc(sizeof(trie));
	tmp->ter=0;
	for(i=0;i<10;i++)
		tmp->num[i]=NULL;
	return tmp;
}
trie* insert(char *s,int i,trie* sta)
{
	int k;
	k=s[i]-'0';
	if(!sta)
	{
		sta=make_trie();
		if(i==l)
			sta->ter=1;
		else
			sta->num[k]=insert(s,i+1,sta->num[k]);
	}
	else
	{
		if(i==l)
		{
			sta->ter++;
			return sta;
		}
		sta->num[k]=insert(s,i+1,sta->num[k]);
	}
	return sta;
}
int found[100];
void printT(trie *tmp,int j)
{
	int i;
	if(tmp->ter==1)
	{
		int k=0;
		for(k=0;k<j;k++)
			printf("%d",found[k]);
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		if(tmp->num[i])
		{
			found[j]=i;
			printT(tmp->num[i],j+1);
		}
	}
	return;
}
int flag;
void find_pre(trie *tmp,int val)
{
	if(tmp->ter)
		val+=tmp->ter;
	if(val>1)
	{
		flag=1;
		return;
	}
	int i;
	for(i=0;i<10;i++)
	{
		if(tmp->num[i])
		{
			find_pre(tmp->num[i],val);
			if(flag)
				break;
		}

	}
	return;
}
int main()
{
	int n,i,t;
	scanf("%d",&t);
	char s[11];
	while(t--)
	{
		flag=0;
		head=make_trie();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			l=strlen(s);
			head=insert(s,0,head);
		}
		//printT(head,0);
		find_pre(head,0);
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
