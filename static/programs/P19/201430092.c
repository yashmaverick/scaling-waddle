#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int last_node;
    struct node *child[10];
}node;
node *root;
void create()
{
    int i;
    root = (node*)malloc(sizeof(node));
    root->last_node = 0;
    for(i=0;i<10;i++)
	root->child[i] = NULL;
}
int flag;
void trie(char *str)
{
    node *temp,*temp1;
    int p,l,i=0;
    int flag2 = 0;
    temp = root;
    l = strlen(str);
    while(l--)
    {
          p = str[i++] - 48;
	if(temp->child[p] == NULL)
	{
	    flag2 = 1;
	    temp1 = (node*)malloc(sizeof(node));
            temp1->last_node = 0;
	    int j = 0;
	    while(j<10)
		temp1->child[j++] = NULL;
	   temp->child[p]=temp1;
	   temp=temp->child[p];
	}
	else
	{ 
	    temp = temp->child[p];
	    if(temp->last_node == 1)
	       {
	         flag = 1;
	       }
	}
    }
    if(flag2 == 0)
       flag = 1;
    else{}
     temp->last_node = 1;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
	flag = 0;
	create();
	char str[100000];
	int nos;
	scanf("%d",&nos);
	while(nos--)
	{
	    scanf("%s",str);
	    trie(str);
	}
	if(flag == 1)
	    printf("NO\n");
	if(flag == 0)
	    printf("YES\n");
    }
    return 0;
}
