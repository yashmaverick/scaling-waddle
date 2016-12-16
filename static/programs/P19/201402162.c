#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct lashit{
	int finish;
	struct lashit* next[10];
}lashit;

int count;
int flag;

lashit* insert(lashit *parent,char c,int final)
{
	if(parent->next[c-'0']==NULL)
	{
		lashit *itr=(lashit*)malloc(sizeof(lashit));
		if(final==1)
			itr->finish=1;
		parent->next[c-'0']=itr;
		flag=0;
		return itr;
	}
	else
	{
		lashit *itr;
		itr=parent->next[c-'0'];
		if(final==1)
			itr->finish=1;
		return itr;
	}
}

void find(lashit * root)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(root->next[i]!=NULL)
		{
			if(root->finish==1)
			{
				count=-1;
//				printf("I AM IN DANGER\n");
				return;
			}
			find(root->next[i]);
//			printf("the value of i is = %d\n",i);
		}
	}
	if(count>=0)
		count+=root->finish;
}
int main()
{
	char s[11];
	int t,n,len,i,j,clue;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		lashit *root= (lashit*)malloc(sizeof(lashit));
		root->finish=0;
		int blue=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			flag=1;
			lashit *itr;
			itr=root;
			scanf("%s",s);
			len=strlen(s);
			for(j=0;j<len;j++)
			{
				if(j!=len-1)
					itr=insert(itr,s[j],0);
				else
					itr=insert(itr,s[j],1);
			}
			if(flag==1)
				blue=1;
		}
		if(blue==1)
		{
			printf("NO\n");
			continue;
		}
		find(root);
		//printf("%d\n",(root->next[3])->finish);
		if(count==-1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
