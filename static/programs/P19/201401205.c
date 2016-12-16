#include<stdio.h>
#include<stdlib.h>
int flag=0;
typedef struct node
{
	char data;
	int size;
	struct node *next[10];
}node;
node *insert(node *root,char s[],int i)
{
//	printf("insert %c\n",s[i]);
	if(root!=NULL)
	{
//		printf("not null\n");
		root->size++;
		if(s[i+1]!='\0')
			root->next[s[i+1]-'0']=insert(root->next[s[i+1]-'0'],s,i+1);
		return root;
	}
	else if(root==NULL)
	{
		int j;
//		printf("null\n");
		root=(node*)malloc(sizeof(node));
		root->size=1;
		root->data=s[i];
		for(j=0;j<10;j++)
			root->next[j]=NULL;
		if(s[i+1]!='\0')
			root->next[s[i+1]-'0']=insert(root->next[s[i+1]-'0'],s,i+1);
		return root;
	}
}
void check(node *root)
{
	int i,tempsum=0;
	for(i=0;i<10;i++)
	{
		if(root->next[i]!=NULL)
			tempsum+=root->next[i]->size;
	}
	if((root->size!=1)&&(root->size!=tempsum))
		flag=1;
	else
	{
		for(i=0;i<10;i++)
		{
			if(root->next[i]!=NULL)
				check(root->next[i]);
		}
	}
}
void fre(node *root)
{
	if(root==NULL)
		return;
	int i;
	for(i=0;i<10;i++)
	{
		if(root->next[i]!=NULL)
			fre(root->next[i]);
	}
	free(root);
}
/*void print(node *root)
{
	int i;
	if(root!=NULL)
	{
		printf("%c %d\n",root->data,root->size);
		for(i=0;i<10;i++)
		{
			//	if(root->next[i]!=NULL)
			print(root->next[i]);
		}
	}
}*/
int main()
{
	int i,t,n;
	char s[10001];
	node *a[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
			a[i]=NULL;
		scanf("%d",&n);
		flag=0;
		while(n--)
		{
			scanf("%s",s);
//			printf("Inserting %s\n",s);
			a[s[0]-'0']=insert(a[s[0]-'0'],s,0);
		}
		for(i=0;i<10;i++)
		{
			if(a[i]!=NULL)
			{
//				print(a[i]);
				check(a[i]);
				fre(a[i]);
			}
		}
		if(flag!=1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
