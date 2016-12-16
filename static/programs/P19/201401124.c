#include<stdio.h>
#include<stdlib.h>

struct tries{
	struct tries *next[10];
	int leaf;
};
typedef struct tries tries;
int ans,flag,otherflag,crapflag;
tries* insert(char k,tries *temp)
{
	int g=k-'0';
	if(temp->next[g]==NULL)
	{
		temp->next[g]=(tries*)malloc(sizeof(tries));
		//temp->next[g]->val=1;
		temp->leaf=0;
		temp=temp->next[g];
		otherflag=1;
		flag=1;
		return temp;
	}
	else if(temp->next[g]!=NULL&&temp->next[g]->leaf==1)
	{
		ans=1;
		return temp;
	}
	else
	{
		return temp->next[g];
	}

}
int main()
{
	int t,n,i,j;
	char num[10];
	scanf("%d",&t);
	while(t--)
	{
		crapflag=0;
		ans=0;
		tries *try=(tries*)malloc(sizeof(tries));
		tries *temp=(tries*)malloc(sizeof(tries));
	//	try->val=0;
		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			otherflag=0;
			temp=try;
			scanf("%s",num);
			if(crapflag==0)
			{
				for(j=0;num[j]!='\0';j++)
				{
					flag=0;
					temp=insert(num[j],temp);
					if(flag==1)
						temp->leaf=1;
					if(ans==1)
						break;
				}
				if(otherflag==0||ans==1)
				{
					printf("NO\n");
					crapflag=1;
				}
			}
		}
		if(crapflag==0)
			printf("YES\n");

	}
	return 0;
}
