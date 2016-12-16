#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int value;
    struct node* child[11];
}mynode;
mynode* createnode()
{
    int i;
    mynode* tmpnode;
    tmpnode=(mynode*)malloc(sizeof(mynode));
    tmpnode->value=0;
    for(i=0;i<11;i++)
    {
	tmpnode->child[i]=NULL;
    }
    return tmpnode;
}
typedef struct trie{
    mynode* root;
    int count;
}trie;
int flag=1;
void createtrie(trie* badshah,char string[])
{
    int jugad=0;
    int i,nu;
    int length=strlen(string);
    mynode* assigner=badshah->root;
    badshah->count++;
    for(i=0;i<length;i++)
    {
	nu=string[i]-'0';
	if(!(assigner->child[nu]))
	{
	    jugad=1;
	    assigner->child[nu]=createnode();
	}
	if(assigner->child[nu]->value!=0)
	{
	    //	    printf("a\n");
	    flag=0;
	}
	assigner=assigner->child[nu];
    }
    if(jugad==0)
    {
	//	printf("a\n");
	if(flag==1)
	{
	    flag=0;
	}
    }
    assigner->value=badshah->count;
}
int searchforstring(char A[],trie* badshah)
{
    int i,temp;
    mynode* tmp=badshah->root;
    int length=strlen(A);
    for(i=0;i<length;i++)
    {
	temp=A[i]-'0';
	if(tmp->child[temp]!=NULL)
	{
	    tmp=tmp->child[temp];
	}
	else
	{
	    return 0;
	}
    }
    printf("%d\n",tmp->value);
    return 1;
}
int main()
{
    char A[100];
    trie ab_bna;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
	flag=1;
	scanf("%d",&n);
	getchar();
	ab_bna.root=createnode();
	ab_bna.count=0;
	while(n--)
	{
	    scanf("%s",A);
	    getchar();
	    createtrie(&ab_bna,A);
	}
	if(flag==1)
	{
	    printf("YES\n");
	}
	else
	{
	    printf("NO\n");
	}
	ab_bna.root=NULL;
    }
    return 0;
}
