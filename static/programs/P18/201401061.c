#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node{
	int data;
	struct node *next;
};

int count,vis[1000005];
struct node * l1[1000005],*l2[1000005];

void list1(int w,int l)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=l;
	p->next=NULL;
	if(l1[w]!=NULL)
		p->next=l1[w];
	l1[w]=p;
}

void list2(int l,int w)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=w;
	p->next=NULL;
	if(l2[l]!=NULL)
		p->next=l2[l];
	l2[l]=p;
}

void dfs(struct node *head,int flag)
{
        while(head!=NULL)
        {
		if(vis[head->data]==0)
		{
			count++;
			vis[head->data]=1;
//			printf("%d ",head->data);
			if(flag==0)
				dfs(l1[head->data],flag);
			else
				dfs(l2[head->data],flag);
		}
		head=head->next;
	}
}

int main()
{
	int i,j=0,t,n,w,l,m;
	scanf("%d",&t);
	struct node *temp;
	while(j<t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			l1[i]=NULL;
			l2[i]=NULL;
		}
		
		for(l=1;l<=n;l++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&w);
				list1(w,l);
				list2(l,w);
			}
		}
/*		for(i=1;i<=n;i++)
		{
			temp=l1[i];
			printf("%d ----> ",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}*/
		m=0;
		int flag=0;
		for(i=1;i<=n;i++)
		{

			for(l=1;l<=n;l++)
				vis[l]=0;
			count=0;
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=i;
			temp->next=NULL;
//			printf("%d--->",i);
			dfs(temp,flag);
//			printf("\n");
			if(count==n)
			{
				m=i;
				break;
			}
//			printf("%d\n",count);
		
		}

		if(m==0)
			printf("0\n");
		else
		{
		        flag=1;
//			printf("winner1=%d\n",m);
			for(i=0;i<=n;i++)
				vis[i]=0;
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=m;
			temp->next=NULL;
			count=0;
			dfs(temp,flag);
		
			printf("%d\n",count);

		}
		
			j++;
		
	}
	return 0;
}
