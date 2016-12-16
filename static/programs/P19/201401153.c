#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0,l,f=0,no;

typedef struct tnode
{
	struct tnode *a[10];
	int flag;
}node;

node *insert(node *root,int val)
{
	/*	int count=0;
		for(k=0;k<10;k++)
		{
		if(root->a[k]==NULL)
		count++;
		}
		if(count==10)
		{			*/
	int k;
	count++;
	if(root->a[val]==NULL)
	{
		if(root->flag==1)
		{
		//	printf("There was a substring of it\n");
			no=1;
		}
	
		root->a[val]=(node*)malloc(sizeof(node));
		for(k=0;k<10;k++)
			root->a[val]->a[k]=NULL;
		if(count==l)
			root->a[val]->flag=1;
		f=1;

	}
	return root->a[val];
}
/*
void *print(node *tmp)
{
	int q;
	for(q=0;q<10;q++)
	{
		if(tmp->a[q]!=NULL)
		{
			printf("%d ",q);
			printf("flag for %d is %d\n",q,tmp->a[q]->flag);
			print(tmp->a[q]);
		}
	}
}
*/
int main()
{
	int t,n,i,j;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		no=0;
		node *root;
		root=(node*)malloc(sizeof(node));
		for(i=0;i<10;i++)
			root->a[i]=NULL;
		node *tmp;
		tmp=root;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			l=strlen(s);
			for(j=0;j<l;j++)
			{
				root=insert(root,s[j]-'0');
			}
		//	print(tmp);
		//	printf("\n");
			root=tmp;
			count=0;
			if(f==0)
			{
			//	printf("it is a substring\n");
				no=1;
			}
			f=0;
		}
		if(no==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
