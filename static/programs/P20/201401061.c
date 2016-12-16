#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node{
	int data;
	struct node *next;
};

int max=0,vis[1000005],r,count;
struct node * l[1000005];

void list(int x,int y)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=y;
	p->next=NULL;
	if(l[x]!=NULL)
		p->next=l[x];
	l[x]=p;

	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	if(l[y]!=NULL)
		p->next=l[y];
	l[y]=p;
}

/*void longest_path(struct node *head,int count)
{

	//	if(vis[head->data]==1)
	//	return;
	while(head!=NULL)
	{
//		printf("%d ",count);
//		printf("%d ",head->data);
		if(vis[head->data]==0)
		{
//			if(head->data==3)
//				printf("%d",count);
			count++;
		//	printf("countincrease=%d\n",count);
			vis[head->data]=1;
		//	printf("%d ",head->data);
		//	printf("%d\n",count);
			m=head->data;
			longest_path(l[head->data],count);
		}
//		else
		if(head->c>=3)
		{
			count--;
//	//		printf("hey");
		}
//			count--;
                //      printf("%d\n",count);
		head=head->next;
	}
//	head=head->next;
//	printf("count=%d\n",count);
	if(count>max)
	{
		max=count;
		r=m;
	}
}*/


void longest_path(struct node *head)
{
//	printf("%d ",head->data);
        while(head!=NULL)
        {
		if(vis[head->data]==0)
		{
			count++;
//			printf("level=%d head->data=%d\n",count,head->data);
			if(count>max)
			{
				max=count;
				r=head->data;
			}
			vis[head->data]=1;
//			printf("%d ",head->data);
//			m=head->data;
			longest_path(l[head->data]);
		}
		head=head->next;
	}
	count--;
}

int main()
{
	int i,j=0,t,n,x,y,f;
	scanf("%d",&t);
	struct node *temp;
	while(j<t)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			l[i]=NULL;
		if(n==0)
			printf("0\n");
		else if(n==1)
			printf("1\n");
		else
		{
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			list(x,y);
		}
/*		for(i=1;i<=n;i++)
		{
			temp=l[i];
			printf("%d ----> ",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}*/
		for(i=1;i<=n;i++)
			vis[i]=0;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
		max=0;
//		vis[x]=1;
//		printf("%d ",x);
		count=0;
		longest_path(temp);
//		printf("\n");
//		printf("maxcount=%d\n",max);
//		printf("r=%d\n",r);
		for(i=0;i<=n;i++)
			vis[i]=0;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=r;
		temp->next=NULL;
		max=0;
//		vis[r]=1;
//		printf("%d ",r);
//		printf("r=%d\n",r);
		count=0;
		longest_path(temp);
//		printf("\n");
		printf("%d\n",max);
//		printf("%d\n",max);
		}
		j++;
		
	}
	return 0;
}
