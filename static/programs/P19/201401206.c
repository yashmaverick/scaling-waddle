#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tries{
	char data;
	int flag;
	struct tries *next[10];
};

typedef struct tries tries;
int l,val=0;
tries* insert(tries *root,char x[],int ind)
{
	if(root==NULL)
	{
		root=(tries*)malloc(sizeof(tries));
		root->data=x[ind];
		root->flag=0;
	}
	else if(root!=NULL)
	{
		if(root->flag==1)
		{   
			val=1;
			return root;
		}
		else if(ind==l-1&&root->flag==0)
		{
			val=1;
			return root;
		}
	}
	if(ind<l-1)
			root->next[x[ind+1]-'0']=insert(root->next[x[ind+1]-'0'],x,ind+1);
	if(ind==l-1)
	{
		root->flag=1;
		return root;
	}
	return root;
}
void print(tries *root)
{
	if(root==NULL)
		return;
	printf("%c",root->data);
	if(root->flag==1)
		printf("\n");
	if(root->data=='R')
		printf("\n");
	int count=1;
	while(count!=10)
	{
		print(root->next[count]);
		count++;
	}
}
int main()
{
	int t,n;
	scanf("%d",&n);
	while(n--)
	{
		val=0;
		char str[100];
		scanf("%d",&t);
		tries *root=(tries*)malloc(sizeof(tries));
		//root->data='R';
		//root->flag=0;
		while(t--)
		{
			scanf("%s",str);
			if(val==0)
			{
				l=strlen(str);
				root->next[str[0]-'0']=insert(root->next[str[0]-'0'],str,0);
			}
		}
		if(val==1)
			printf("NO\n");
		else
			printf("YES\n");
		//print(root);
	}
	return 0;
}
