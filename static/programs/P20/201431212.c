#include<stdio.h>
#include<stdlib.h>
int b[1000001]={};
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *a[1000001];
int in,on;
void insert(int n1,int n2)
{
	node* new=malloc(sizeof(node));
	new->data=n2;
	new->next=a[n1];
	a[n1]=new;
}
void dfs(int n1,int count)
{
	int i;
	b[n1]=1;
	node* temp=malloc(sizeof(node));
	temp=a[n1];
	while(temp!=NULL)
	{
		if(b[temp->data]!=1)
		{
			if(count+1>on)
			{
				on=count+1;
				in=temp->data;
			}
			dfs(temp->data,count+1);
		}
		temp=temp->next;
	}
}
int main()
{
	int m,t,n1,i,v,n2;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		in=0,on=0;
		for(i=0;i<1000001;i++)
			b[i]=0;
		scanf("%d",&v);
		for(i=1;i<=v-1;i++)
		{
			scanf("%d",&n1);
			scanf("%d",&n2);
			insert(n1,n2);
			insert(n2,n1);
		}
		dfs(1,1);
//		printf("%d %d\n",in,on);
		on=0;
		for(i=0;i<1000001;i++)
			b[i]=0;
		dfs(in,1);
		printf("%d\n",on);
		for(i=1;i<=v;i++)
			a[i]=NULL;
	}
	return 0;
}
