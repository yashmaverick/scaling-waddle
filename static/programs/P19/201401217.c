#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	struct node*arr[10];
	int flag;
	int val;
}node;
node*head;
node*w;
int insert(char* q,int len)
{
	node*p;
	p=head;
	int j,i;
	for(j=0;j<len;j++)
	{
		if(p->arr[(int)q[j]-48]==NULL)
		{
			w=(node*)malloc(sizeof(node));
			w->val=0;
			for(i=0;i<10;i++)
				w->arr[i]=NULL;
			if(j==(len-1))
				w->flag=1;
			p->arr[(int)q[j]-48]=w;
		}
		(p->val)++;
		if(p!=head)
		{
			if(p->flag==1)
				return 1;
		}
		p=p->arr[(int)q[j]-48];
		(p->val)++;
		if(j==(len-1))
		{
			if(p->val>1)
				return 1;
			else
				return 0;
		}
	}
}
int main()
{
	int t,length,i,n;
	char str[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int y;
		head=(node*)malloc(sizeof(node));
		head->val=0;
		for(i=0;i<10;i++)
			head->arr[i]=NULL;
		while(n--)
		{
			scanf("%s",str);
			length=strlen(str);
			y=insert(str,length);
			//	printf("%d   ",n);
			if(y==1)
				break;
		}
		if(y==1)
		{
			while(n--)
			{
				scanf("%s",str);
			}
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}
