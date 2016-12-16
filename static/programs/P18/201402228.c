#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node *next;
};
node *a[10001];
int b[10001];
int count;
int ans;
int flag;
void dfs(int n)
{

	node *c=a[n];

	if(flag==1)
	{

		count++;
		b[n]=0;
//		printf("%d ",n);
	}
	//if(flag==1)
	else if(flag==0)
		return;
	while(c!=NULL)
	{
		flag=1;
		if(b[c->val]==0)
			flag=0;
		dfs(c->val);
		c=c->next;
	}


}
int main()
{

	int t,i,n,j,wa,no,k,l;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		
		count=0;
		ans=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			//a[j]=NULL;
			scanf("%d",&no);
			for(k=0;k<no;k++)
			{
				scanf("%d",&wa);
				node *p;
				p=malloc(sizeof(node));
				p->val=j;
				if(a[wa]==NULL)
				{
					p->next=NULL;
					a[wa]=p;
				}
				else
				{
					p->next=a[wa];
					a[wa]=p;
				}
			}
		}
		j=1;
		while(j<=n)
		{

			for(l=1;l<=n;l++)
				b[l]=1;
			flag=1;
			if(count==n)
				ans++;

			count=0;

			//			b[j]=0;
			//			count++;
			//			printf("%d ",j);
			//			if(a[j]!=NULL)
			dfs(j);
		//	printf("\n");
			j++;
		}
		if(count==n)
			ans++;
		printf("%d\n",ans);
		for(j=1;j<=n;j++)
			a[j]=NULL;
	}
	return 0;
}







