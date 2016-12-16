#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	struct node *next[10];
}node;
int gstate=0;
void insert(char *a,int index,node *start)
{
	if(a[index]=='\0')
		return;
	int state=0,pstate=0;
	if(start->next[a[index]-'0']==NULL)
	{
		state=1;
		int j;
		start->next[a[index]-'0']=(node *)malloc(sizeof(node));
		for(j=0;j<=9;j++)
			start->next[a[index]-'0']->next[j]=NULL;
	}
	int i;
	for(i=0;i<=9;i++)
		if(start->next[a[index]-'0']->next[i]!=NULL)
			pstate=1;
	if((state==0&&a[index+1]=='\0')||(state==0&&pstate==0))
	{
		gstate=1;
		return;
	}
	insert(a,index+1,start->next[a[index]-'0']);
}
void dfs(node *root)
{
	int i;
	if(root==NULL)
		return;
	for(i=0;i<=9;i++)
		dfs(root->next[i]);
	root=NULL;
	free(root);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		node *start=(node *)malloc(sizeof(node));
		int i;
		for(i=0;i<=9;i++)
			start->next[i]=NULL;
		scanf("%d",&n);
		int state=0;
		while(n--)
		{
			char a[11];
			scanf("%s",a);
			gstate=0;
			insert(a,0,start);
			if(gstate==1)
				state=1;
		}
		if(state==1)
			printf("NO\n");
		else
			printf("YES\n");
		dfs(start);
	}
	return 0;
}
