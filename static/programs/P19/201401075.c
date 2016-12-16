#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ll
{
	struct ll *ar[10];
}node;
int ans=0;	
			
node *head;
node *insert(node *root,char *val,int ct,int l)
{
	if(ct==l-1)
	{
		if(root->ar[val[ct]-'0']==NULL)
		{
			root->ar[val[ct]-'0']=(node *)malloc(sizeof(node));
//			printf("insert case 2 %c\n",val[ct]);
		}
		else
			ans=1;
		return root;
	}
/*	if(root==head)
	{
		printf("root is head in this case \n");
	}*/
	if(root->ar[val[ct]-'0']==NULL)
	{
		root->ar[val[ct]-'0']=(node *)malloc(sizeof(node));
//		printf("insert case 1 %c\n",val[ct]);
	}
	else
	{
//		printf("case when node is already present\n");
		int i,state=0;
		for(i=0;i<10;i++)
		{
			if(root->ar[val[ct]-'0']->ar[i]!=NULL)
				state=1;
		}
		if(state==0)
			ans=1;
	}
	root->ar[val[ct]-'0']=insert(root->ar[val[ct]-'0'],val,ct+1,l);
	return root;
}



int main()
{
	int t,n,n2;
	char ch[11],c;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		head=(node *)malloc(sizeof(node));
		scanf("%d",&n);
		n2=n;
		while(n--)
		{
			scanf("%s",ch);
			int l=strlen(ch);
			head=insert(head,ch,0,l);
		}
		int i;
		free(head);
		for(i=0;i<10;i++)
			head->ar[i]=NULL;
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

		

