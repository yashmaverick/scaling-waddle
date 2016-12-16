#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node *next;
};
node *a[1000003];
int b[1000003];
int flag;
int co;
int last;
void dfs(int n,int ans)
{

	node *c=a[n];

	if(flag==1)
	{

		b[n]=0;
		ans++;
//		printf("%d ",ans);
//		printf("%d ",co);
		if(ans>=co)
		{
			last=n;
			co=ans;
		}
//		printf("%d\n",co);

	}
	else if(flag==0)
	{
//		if(ans>=co);
//			co=ans;
		return;
	}
	while(c!=NULL)
	{
		flag=1;
		if(b[c->val]==0)
		{

			flag=0;
		}
	//	printf("%d\n",c->val);
		dfs(c->val,ans);
		//	co=ans;
		c=c->next;
	}
}
int main()
{

	int t,i,n,j,r,s,ans;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		last=0;
		ans=0;
		scanf("%d",&n);
		for(j=1;j<n;j++)
		{
			scanf("%d%d",&r,&s);
			node *p,*q;
			p=malloc(sizeof(node));
			q=malloc(sizeof(node));
			p->val=r;
			q->val=s;
			p->next=a[s];
			a[s]=p;
			q->next=a[r];
			a[r]=q;
		}
	/*	for(j=1;j<=n;j++)
		{
			node *tmp=a[j];
			while(tmp!=NULL)
			{
				printf("%d ",tmp->val);
				tmp=tmp->next;
			}
			printf("\n");
		}*/
		for(j=1;j<=n;j++)
			b[j]=1;
		co=0;
		ans=0;
		flag=1;
		dfs(1,ans);

		for(j=1;j<=n;j++)
			b[j]=1;
		co=0;
		ans=0;
		flag=1;
	//	printf("%d\n",last);
		if(last!=1)
		{
			dfs(last,ans);
			printf("%d\n",co);
		}
		else
			printf("%d\n",co);
		for(j=1;j<=n;j++)
			a[j]=NULL;
	}
	return 0;
}










