#include<stdio.h>
#include<stdlib.h>

int b[1000000],start,end;
typedef struct node
{
	int val;
	int flag;
	struct node *next;
}node;

node* insert(node *head,int ver,int di)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->val=ver;
	temp->flag=di;
	temp->next=head;
	return temp;
}

void child(node *r,node *a[],int prev,int c[])
{
	int temp;
	node *temp1;
	node* head=r;
	while(head!=NULL)
	{
//		printf("Yes ");
		if(head->flag==0)
		{
			head->flag=1;
			temp=head->val;
			b[end]=temp;
			end++;
			c[temp]=prev+1;
			temp1=a[temp];
			while(1)
			{
				if(temp1->val==b[start])
				{
					temp1->flag=1;
					break;
				}
				temp1=temp1->next;
			}
		}
		head=head->next;
	}
}

void child1(node *head,node *a[],int prev,int c[])
{
	int temp;
	node *temp1;
	while(head!=NULL)
	{
		if(head->flag==1)
		{
			head->flag=0;
			temp=head->val;
			b[end]=temp;
			end++;
			c[temp]=prev+1;
			temp1=a[temp];
			while(1)
			{
				if(temp1->val==b[start])
				{
					temp1->flag=0;
					break;
				}
				temp1=temp1->next;
			}
		}
		head=head->next;
	}
}

int main()
{
	int t,h;
	scanf("%d",&t);
	int c[1000000]={0};
	node* a[1000000];
	for(h=0;h<t;h++)
	{
		int i,n,fi,se;
		start=0;
		end=1;
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(i=0;i<=n;i++)
		{
			c[i]=0;
			a[i]=NULL;
		}
//		node *a[1000000];
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&fi,&se);
//			if(i==0)
//				b[0]=fi-1;
			fi=fi-1;
			se=se-1;
			a[fi]=insert(a[fi],se,0);
			a[se]=insert(a[se],fi,0);
		}
		b[0]=0;
//		printf("\n");
		while(1)
		{
			child(a[b[start]],a,c[b[start]],c);
			start++;
			if(start==end)
				break;
		}
		int max,aaa;
		max=0;
		aaa=0;
		for(i=0;i<n;i++)
		{
			if(c[i]>=max)
			{
				max=c[i];
				aaa=i;
			}
		}
//		printf("%d %d\n",max,aaa);
		for(i=0;i<n;i++)
		{
//			printf("%d ",c[i]);
			c[i]=0;
		}
		start=0;
		end=1;
		b[0]=aaa;
		while(1)
		{
			child1(a[b[start]],a,c[b[start]],c);
			start++;
			if(start==end)
				break;
		}
		max=0;
		aaa=0;
		for(i=0;i<n;i++)
		{
			if(c[i]>max)
			{
				max=c[i];
				aaa=i;
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d ",c[i]);

		printf("%d\n",max+1);
	}
	return 0;
}
