#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie
{
	int data;
	struct trie* next[11];
}trie;

int flag=0;
trie *createnode();
void insert(trie *pre, char *number)
{
	int k,len,j,ind,count=0;
	len=strlen(number);
	for(j=0;j<len;j++)
	{
		if(j==0)
		{
			if(len!=1)
			{
					//pre->next[10]=createnode();
				if(pre->data==1)
					flag=1;
			}
			else if (len==1)
			{
				if(pre->data==1)
					flag=1;
				//else if(pre->next[10]!=NULL && pre->next[10]->data==1)
					//flag=1;
				else
				{
					int pop=0;
					for(k=0;k<=9;k++)
					{
						if(pre->next[k]!=NULL)
							pop=1;
					}
					if(pop==1)
						flag=1;
					//pre->next[10]=createnode();
					pre->data=1;
				}
			}
		}
		else 
		{
			if((pre->next[(number[j]-'0')]) == NULL )
			{
				trie *t;
				t=createnode();
				pre->next[(number[j]-'0')]=t;
				pre=t;
				if(j==len-1)
				{
					//pre->next[10]=createnode();
					pre->data=1;
				}
			}
			else
			{
				pre=pre->next[(number[j]-'0')];
				if((pre->data) == 1)
					flag=1;
				else if(j==len-1)
				{
					int pop=0;
					for(k=0;k<=9;k++)
					{
						if(pre->next[k]!=NULL)
							pop=1;
					}
					if(pop==1)
						flag=1;
					pre->data=1;
				}

			}
		}
	}
}

trie *createnode()
{
	int i;
	trie *t = (trie*)malloc(sizeof(trie));
	t->data=-1;
	for(i=0;i<11;i++)
		t->next[i]=NULL;
	return t;
}
int main()
{
	int t,n,i;
	char number[11];
	scanf("%d",&t);
	trie *pre[10];
	for(i=0;i<=9;i++)
		pre[i]=createnode();
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",number);
			trie *temp;
			//temp=malloc(sizeof(trie));
			temp=pre[number[0]-'0'];
			insert(temp,number);
		}
		if(flag==1)
			printf("NO\n");
		else 
			printf("YES\n");
		//free(pre);

		int I,J;
		for(I=0;I<=9;I++)
			for(J=0;J<=10;J++)
			{
				pre[I]->next[J]=NULL;
				pre[I]->data=-1;
			}
	}
	return 0;
}
