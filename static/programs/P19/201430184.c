#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int val[10];
	struct node *next[10];
	int fl;
};
struct node* root=NULL;
struct node* create()
{
	int x=0;
	struct node *q=(struct node*)malloc(sizeof(struct node));
	for(x=0;x<10;x++)
	{
		q->next[x]=NULL;
		q->val[x]=1;
		q->fl=0;
	}
	return q;
}
int main()
{
	int test,count;
	scanf("%d",&test);
	for(count=0;count<test;count++)
	{
		int n,i,j,k,p,flag,o,u,t;
		scanf("%d",&n);
		char a[10];
                struct node* root=NULL;
                flag=0;
                t=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			k=strlen(a);
			u=0;
			if(root == NULL)
			{
				root=create();
			}
			struct node *q=root;
			for(j=0;j<k;j++)
			{
				if(q->fl==1&&j<=k-1)
				{       
					t=1;
					break;
				}
				p=a[j]-'0';
				if(q->next[p]==NULL)
				{
					q->next[p]=create();
                                        u=1;
				}
				q=q->next[p];
                                 if(q->fl==1&&j<=k-1)
                                {
                                        t=1;
                                        break;
                                }
			        if(q->fl==0&&j==k-1&&q!=NULL&&u!=1)
				{
					t=1;
					break;
				}
				if(j==k-1)
				{
					q->fl=1;
				}
			}
                        if(t==1)
                        {
				flag=1;
                        }
		}
		if(flag==0)
		{
			printf("YES\n");
		}
		else if(flag==1)
		{
			printf("NO\n");
		}
	}
	return 0;
}

