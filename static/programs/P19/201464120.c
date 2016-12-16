#include <stdio.h>

#include <stdlib.h>
#include <string.h>

typedef struct trie
{
	int d;
	struct trie *next[11];
}trie;


trie *head=NULL;


trie* create()
{
	int i;
	trie *t;
	t=(trie*)malloc(sizeof(trie));
	for(i=0;i<11;i++)
		t->next[i]=NULL;
	return t;
}


int f=1;


void insert(char s[])
{
	int i=0,l;
	trie *h=head;
	
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(h->next[s[i]-'0']!=NULL)
		{
			h=h->next[s[i]-'0'];
			
			if(h->next[10]!=NULL)
				f=2;				
			continue;
		}
		trie *temp;
		temp=create();
		temp->d=s[i]-'0';
//		printf("%d \n",temp->d);
		h->next[s[i]-'0']=temp;
		h=temp;
	}
	for(i=0;i<10;i++)
	{
		if(h->next[i]!=NULL)
			f=2;
	}
	trie *la;
	la=create();
	la->d=-1;
	h->next[10]=la;
	return;
}



int main()
{
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
	int n,i;
	f=1;
	char in[15];
	//head=(trie*)malloc(sizeof(trie));
	head=create();
	head->d=0;	
	//for(i=0;i<11;i++)
	//	head->next[i]=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",in);
		insert(in);
	}
	if(f==1)
		printf("YES\n");
	else
		printf("NO\n");
	test--;
	}
	return 0;
}


