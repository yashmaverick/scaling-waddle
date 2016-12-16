#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct box
{
	char data;
	struct box *x[11];
}*shubh;
int insert(char str[])
{
	struct box *temp;
	int len=strlen(str),count,flag=0,j;
	temp=shubh;
	for(j=0;j<len;j++)
	{


		if(temp->x[10]!=NULL)
		{
			return 1;
		}
		else if(temp->x[str[j]-'0']==NULL)
		{
			temp->x[str[j]-'0']=malloc(sizeof(struct box));
			temp->x[str[j]-'0']->data=str[j];
			temp=temp->x[str[j]-'0'];
			flag=1;
		}
		else if(temp->x[str[j]-'0']!=NULL)
		{
			temp=temp->x[str[j]-'0'];
		}
	}
	if(flag==0)
		return 1;
	else if(flag==1)
	{
		temp->x[10]=malloc(sizeof(struct box));
		temp->x[10]->data='@';
		return 0;
	}
}
int main()
{
	int test,i,k;
        char str[100010];
	scanf("%d",&test);
	for(k=0;k<test;k++)
	{
		shubh=malloc(sizeof(struct box));
		shubh->data='c';
		for(i=0;i<=10;i++)
		{
			shubh->x[i]=NULL;
		}
		int n,flag=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			if(flag==0)
			{
				flag=insert(str);
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;
}

