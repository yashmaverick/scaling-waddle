#include<stdio.h>
#include<stdlib.h>
int V;
int v[100000];
int stack[100000];
int size=0;
typedef struct node
{
	int data;
	struct node * next;
}node;
void insert(node * a[],int d, int s)
{
	node * temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=s;
	temp->next=a[d]->next;
	//      temp->next=NULL;
	a[d]->next=temp;
}
/*int size=0;
  void push(int v)
  {

  }*/
void  dfs(int i,node * a[])
{
	if(v[i]==0)
	{
		v[i]=1;
		node * temp=a[i]->next;
		while(temp!=NULL)
		{
			if(v[temp->data]==0)
			{
				v[i]=1;
				dfs(temp->data,a);
			}
			temp=temp->next;
		}
		if(v[i]==1)
		{
			stack[size]=i;
			size++;
		}
	}
}
void fun(node *a[])
{
	int i;
	node *temp;
	for(i=1;i<=V;i++)
	{
		temp=a[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	int i,l,n,d,s,k,m;
	scanf("%d%d",&V,&m);
	node * a[V];
	for(i=1;i<=V;i++)
	{
		v[i]=0;
		a[i]=(node *)malloc(sizeof(node));
		a[i]->data=i;
		a[i]->next=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&d,&s);
		insert(a,d,s);
	}
//	fun(a);
	size=0;
	for(l=V;l>0;l--)
	{

		/*	if(v[temp->data]==0)
				dfs(temp->data,a);
			stack[size]=temp->data;
			v[temp->data]=1;
			temp=temp->next;
			size++;

		}
		if(v[l]==0)
		{
			stack[size]=l;
			size++;
			v[l]=1;
		}*/
		dfs(a[l]->data,a);
}
	for(i=size-1;i>0;i--)
		printf("%d ",stack[i]);
	printf("%d",stack[0]);
	printf("\n");
	return 0;
}
