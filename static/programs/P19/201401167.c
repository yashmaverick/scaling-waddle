#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sc(n) scanf("%d",&n)
#define DRT()  int t; sc(t); while(t--)
struct trie{
	int a;
	struct trie* ar[10];
}*head;
typedef struct trie trie;
char fl;
void delete(trie* head)
{	if(head==NULL)
		return;
	int i;
	for(i=0;i<10;i++)
		if(head->ar[i]!=NULL)
			delete(head->ar[i]);
	free(head);
}
void insert(char a[])
{	int i=0,k;trie* cur=head;
	while(a[i]!='\0')
	{	if(cur->ar[a[i]-'0']==NULL)
		{cur->ar[a[i]-'0']=malloc(sizeof(trie));
			for(k=0;k<10;k++)
				cur->ar[a[i]-'0']->ar[k]=NULL;
			cur->ar[a[i]-'0']->a=0;}
		else if(cur->ar[a[i]-'0']->a!=0)
			fl=1;
		if(a[i+1]=='\0')
		{cur->ar[a[i]-'0']->a+=1;
			for(k=0;k<10;k++)
				if(cur->ar[a[i]-'0']->ar[k]!=NULL)
					fl=1;
		}
		cur=cur->ar[a[i]-'0'];i++;
	}
}
int main()
{//	trie *head;
	DRT()
	{	int i,r;
		head =malloc(sizeof(trie));
		for(i=0;i<10;i++)
			head->ar[i]=NULL;
		head->a=0;
		fl=0;sc(r);char n[12];
		for(i=0;i<r;i++)
		{
		scanf("%s",n);
			insert(n);
		}
		if(fl)
			printf("NO\n");
		else
			printf("YES\n");
	delete(head);
	}
	return 0;
}

	
