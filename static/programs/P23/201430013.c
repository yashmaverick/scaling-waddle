#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node node;
typedef node *next;
struct node{
	int val;
	node* next;
};
node* insert(node *head,int data)//to insert a new element(imp. step-node* datatype)//O(1)
{
	node* temp=malloc(sizeof(node));
	temp->val=data;         temp->next=head;
	return temp;
}
/*Declarations*/
int a[1000000];
int visited[1000000];
int degree[1000000];
int ptr1=1;
void swap(int m,int n)
{
	if(m>=ptr1&&n>=ptr1)
		return ;
	int temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
int min(int m,int n)
{
	if(m>=ptr1)
		return n;
	else if(n>=ptr1)
		return m;
	else
	{
		if(a[m]<a[n])
			return m;
		return n;
	}
}
void refresh1(int p)
{
	if(p==0)
		return;
	if(a[p]<a[p/2])
	{
		swap(p,p/2);
		refresh1(p/2);
	}
}
void refresh2(int p)
{
	if(p==0)
		return;
	if(2*p<ptr1)
	{
		int r=min(2*p,2*p+1);
		if(a[r]<a[p])
		{
			swap(r,p);
			refresh2(r);
		}
	}
}
void delete()
{
	a[1]=a[ptr1-1];
	ptr1--;
	refresh2(1);
}
void insert1(int s)
{
	a[ptr1]=s;
	ptr1++;
	refresh1(ptr1-1);
}
int main()
{
	int ptr=0;
	int s[1000000];
	a[0]=-5;
	int i;
	int r,k,u,v;
	node *n[100002]={NULL};
	scanf("%d %d",&r,&k);
	for(i=0;i<r+1;i++)
	{
		degree[i+1]=0;
	}
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&u,&v);
		n[u]=insert(n[u],v);
		degree[v]++;
	}
	for(i=1;i<=r;i++)
	{
		if(degree[i]==0)
		{
			insert1(i);
		}
	}
	while(ptr1!=1)
	{
		int q=a[1];
		s[ptr++]=a[1];
		delete();
		node* head=n[q];
		while(head!=NULL)
		{
			degree[head->val]--;
			if(degree[head->val]==0)
			{
				insert1(head->val);
				visited[head->val]=1;
			}
			head=head->next;
		}
	}
	for(i=0;i<ptr-1;i++)
		printf("%d ",s[i]);
	printf("%d\n",s[ptr-1]);
	return 0;
}
