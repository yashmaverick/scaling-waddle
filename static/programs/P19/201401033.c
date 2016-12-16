#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trienode
{
	int value;
	struct trienode *child[10];
	int end;
}node;
node* new(void)
{
	node* one=malloc(sizeof(node));
	int i;
	one->value=0;
	for(i=0;i<10;i++)
	{
		one->child[i]=NULL;	
	}
	one->end=0;
	return one;
}

int ans=1,var=1;
void insert(node *pre,char word[])
{
	int len=strlen(word);
	node *temp=pre,*mm;
	int i,ind,t=0;
	for(i=0;i<len;i++)
	{
		ind=word[i]-'0';
		if(!temp->child[ind])
		{
			temp->child[ind]=new();
		}
		else if(temp->child[ind]!=NULL)
		{
			if((i!=0 && t==1 && (temp->child[ind]->end)==1)||(i==0 && (temp->child[ind]->end)==1))
				var=0;
			else if((i!=0 && t==1 && i==len-1) || len==1 && t==0)
				ans=0;
			t=1;
		}
		mm=temp;
		temp=temp->child[ind];
	}
	temp->end=1;
}

int main()
{
	int tc,n,i,ss;
	char str[1000];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d\n",&n);
		node *mytrie=malloc(sizeof(node));
		mytrie=new();
		ss=1;
		for(i=0;i<n;i++)
		{
			ans=1,var=1;
			scanf("%s",str);
			insert(mytrie,str);
			if(i!=0&&(var==0 || ans==0))
			{
				ss=0;
			}
		}
		if(ss==1)
			printf("YES\n");
		else if(ss==0)
			printf("NO\n");
	}
	return 0;
}
