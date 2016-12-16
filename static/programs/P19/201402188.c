#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
struct node
{
	int  val;
	int flag;
	int flag1;
	int end;
	node *a[10];
};

int aman=0;

node* insert(node *root ,char s[])
{
	int j,i,b;
	node* temp=root;
	int t;
	i=strlen(s);
	for(j=0;j<i;j++)
	{	int b=s[j]-'0';

		if(root->a[b]==NULL)
		{
			node* tmp=(node*)malloc(sizeof(node));
			for(t=0;t<10;t++)
			{
				tmp->a[t]=NULL;			
			}
			tmp->val=b;
			if(j==i-1)
			{
				tmp->flag=1;
			}
			tmp->flag1=1;
			root->a[b]=tmp;
			root=root->a[b];
			//	printf("if %d\n",root->val);
			//	printf("if flag %d\n",root->flag);
			//	printf("if flag1 %d\n",root->flag1);
		}
		else if(root->a[b]!=NULL)
		{
			root=root->a[b];
			if(j==i-1)
			{
				root->flag=1;
				aman=1;
				//	printf("No\n");
			}
			if(root->flag==1)
			{
				//	printf("No\n");
				aman=1;
			}
			//	printf("elif %d\n",root->val);
			//	printf("elif flag %d\n",root->flag);
			//	printf("elif flag1 %d\n",root->flag1);
		}
	}
	//	print(temp,b,i-1);
	return temp;
}

int main()
{
	int test,jaa;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int n,i,m,t;
		aman=0;
		scanf("%d",&n);
		char s[10];
		node* root=(node*)malloc(sizeof(node));
		root->val=-1;
		root->flag1=1;
		root->flag=0;
		for(t=0;t<10;t++)
		{
			root->a[t]=NULL;			
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(aman==0)
			{
				root=insert(root,s);
			}
		}
		if(aman==0)
			printf("YES\n");
		else if(aman==1)
			printf("NO\n");
	}
	return 0;
}
