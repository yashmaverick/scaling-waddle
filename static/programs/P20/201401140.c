#include<stdio.h>
#include<stdlib.h>
int flag=0,maxcount,node1;
typedef struct node{
	int val;
	struct node *next;
}node;
node *arr[1000010];
void  func(int n1,int n,int vis[],int count)
{
	if(maxcount<count)
	{
		maxcount=count;
		node1=n1;
	}
	if(count==n-1)
		flag=1;
	else
	{
		vis[n1]=1;
		node* temp;
		temp=arr[n1];
		while(temp!=NULL)
		{
			if(vis[temp->val]==0)
				func(temp->val,n,vis,count+1);
			temp=temp->next;
		}
	}
}
void insert(int b,int c)
{
	node* temp;
	node* temp1;
	temp1=(node*)malloc(sizeof(node));
	temp=(node*)malloc(sizeof(node));
	temp1->val=c;
	temp->val=b;
	temp1->next=arr[b];
	temp->next=arr[c];
	arr[b]=temp1;
	arr[c]=temp;
}
int main()
{
	int t,t1;
	scanf("%d",&t);
	for(t1=0;t1<t;t1++)
	{
		int n,n1;
		int b,c;
		scanf("%d",&n);
		for(n1=1;n1<=n;n1++)
			arr[n1]=NULL;
		for(n1=1;n1<n;n1++)
		{
			scanf("%d%d",&b,&c);
			insert(b,c);
		}
		maxcount=0;
		//	for(n1=1;n1<=n;n1++)
		//	{
		int count=0;
		int vis[1000010]={0};
		func(b,n,vis,count);
		maxcount=0;
		count=0;
		int vis1[1000010]={0};
		func(node1,n,vis1,count);
		//		if(flag==1)
		//			break;
		//	}
		printf("%d\n",maxcount+1);
	}
	return 0;
}
