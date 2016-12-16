#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int fl;

typedef struct node {
  int val;
  struct node* ch[10];
} node;

typedef struct trie {
  node* root;
  int count;
} trie;

node* new(void) {
  node* temp=NULL;
  temp=(node*)malloc(sizeof(node));
  int i;
  for(i=0;i<10;i++)
    temp->ch[i]=NULL;
  return temp;
}

void start(trie* tr) {
  tr->root=new();
  tr->count=0;
}

void insert(trie *tr,char in[]) {
  int i,j,l=strlen(in),th=1;
  fl=0;
  node* temp;
  tr->count++;
  temp=tr->root;
  for(i=0;i<l;i++)
    {
      j=(int)in[i]-(int)'0';
      //printf("j %d\n",j);
      if(!temp->ch[j])
	{
	  temp->ch[j]=new();
	  fl=1;
	}
      temp=temp->ch[j];
      if(temp->val!=0)
	th=0;//printf("yo\n");
    }
  temp->val=1;
  if(th==0)
    fl=0;
  //printf("%d\n",fl);
}

int main()
{
  int i,n,j,k,l,test;
  char c[MAX];
  scanf("%d",&test);
  for(i=0;i<test;i++)
    {
      fl=1;
      scanf("%d",&n);
      trie tr;
      start(&tr);
      for(j=0;j<n;j++)
	{
	  scanf("%s",c);
	  if(fl==1)
	    insert(&tr,c);
	}
      if(fl==0)
	printf("NO\n");
      else
	printf("YES\n");
    }
  return 0;
}
