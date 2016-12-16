#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* dig[10];
    int end;
}node;
node* newnode()
{
    node *new=malloc(sizeof(node));
    int i;
    for(i=0;i<10;i++)
	new->dig[i]=NULL;
    new->end=0;
    return new;
}
int ans,inchain;
node *root;
map(char *num)
{
    inchain=1;
    node *cur=root;
    int i;
    for(i=0;num[i]!='\0';i++)
    {
	if(cur->end==1)
	    ans=0;
	if(cur->dig[num[i] - '0'] !=NULL)
	    cur=cur->dig[num[i] - '0'];
	else
	{
	    cur->dig[num[i] - '0']=newnode();
	    inchain=0;
	    cur=cur->dig[num[i] - '0'];
	}
    }
    cur->end=1;
    if(inchain==1)
	ans=0;
}
int main()
{
    int n;
    char num[11];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    root=newnode();
    scanf("%d",&n);
    getchar();
    ans=1;
    while(n--)
    {
    scanf("%s",num);
    getchar();
    map(num);
    }
    if(ans==1)
    printf("YES\n");
    else if(ans==0)
	printf("NO\n");
    }
    return 0;
}
