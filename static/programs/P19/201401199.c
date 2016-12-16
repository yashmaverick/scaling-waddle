#include<stdio.h>
#include<stdlib.h>

struct trie
{
    char val;
    int leaf;
    struct trie* n[10];
};
typedef struct trie trie;
typedef trie* link;
int fl=1;


link insert(link root,char s[],int in)
{
    if(s[in]=='\0')
	return root;

    int v;
    v=s[in]-'0';
//    printf("\nv=%d\n",v);

    if(root!=NULL && root->leaf==2)
    {
//	printf("first\n");
	root->n[v]=insert(root->n[v],s,0);
    }
    else if(root==NULL)
    {
//	printf("NULL making\n");
	root=(link) malloc(sizeof(trie));
	root->val=s[in];
	root->leaf=0;
	if(s[in+1]=='\0')
	{
//	    printf("leaf=1\n");
	    root->leaf=1;
	    //	    return root;
	}
	else
	{
	    v=s[in+1]-'0';
	    root->n[v]=insert(root->n[v],s,in+1);
	}
    }
    else
    {
//	printf("exists already\n");
	if(root->leaf==1)
	{
//	    printf("leaf of one reached but still calling\n");
	    fl=0;
	}
	if(s[in+1]=='\0')
	{
//	    printf("it is a part of an already existing string\n");
//	    printf("leaf=1\n");
	    root->leaf=1;
	    fl=0;
	}
	else
	{
	    v=s[in+1]-'0';
	    root->n[v]=insert(root->n[v],s,in+1);
	}
    }
    return root;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
	int i,n,v;
	char s[10];
	fl=1;
	link root;
	root=(link) malloc(sizeof(trie));
	root->val='0';
	root->leaf=2;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%s",s);
	    v=s[0]-'0';
	    root=insert(root,s,0);
//	    printf("%c\n",root->val);
	}
	if(fl==1)
	    printf("YES\n");
	else
	    printf("NO\n");
    }
}

