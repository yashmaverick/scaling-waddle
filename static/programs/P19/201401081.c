#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char num[15];
int no_of_digits;
int yes;

typedef struct tr
{
  struct tr *val[10];
  int endbit;
}trie;

trie *root=NULL;

void check_prefix(int index,trie *node)
{
  int pos,i;
  if(node->endbit==1)
	{
	  yes=0;
	  return;
	}
  if(index==no_of_digits&&node!=NULL)
	{
	  for(i=0;i<10;i++)
		if(node->val[i]!=NULL)
		  {
			yes=0;
			return;
		  }
	}
  if(index==no_of_digits)
	{
	  node->endbit=1;
	  return;
	}
  pos=num[index]-'0';
  if(node->val[pos]==NULL)
	{
	  node->val[pos]=(trie*)malloc(sizeof(trie));
	  for(i=0;i<10;i++)
		node->val[pos]->val[i]=NULL;
	  node->endbit=0;
	}
  check_prefix(index+1,node->val[pos]);
}

int main()
{
  int t,n,i;
  scanf("%d",&t);
  root=(trie*)malloc(sizeof(trie));
  while(t--)
	{
	  for(i=0;i<10;i++)
		root->val[i]=NULL;
	  root->endbit=0;
	  yes=1;
	  scanf("%d",&n);
	  while(n--)
		{
		  scanf("%s",num);
		  no_of_digits=strlen(num);
		  //printf("%d:%s\n",no_of_digits,num);
		  check_prefix(0,root);
		  /* if(yes==0) */
		  /* 	while(n--) */
		  /* 		scanf("%s",num); */
		}
	  if(yes==0)
		printf("NO\n");
	  else
		printf("YES\n");
	}
  return 0;
}
