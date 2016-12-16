#include<stdio.h>
#include<stdlib.h>
int stack[500001];
int top=0;
int b[500001]={};
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node* a[500001];
void push(int val)
{
	top++;
	stack[top]=val;
}
void pop()
{
	top--;
}
void insert(int i,int j)
{
	node *new=malloc(sizeof(node));
	new->data=j;
	new->next=a[i];
	a[i]=new;
}
void sort(int n)
{
	b[n]=1;
	node* temp=a[n];
	while(temp!=NULL)
	{
		if(b[temp->data]!=1)
			sort(temp->data);
		temp=temp->next;
	}
	push(n);
}
void topolog(int n)
{
	int i;
	for(i=n;i>=1;i--)
		if(b[i]==0)
			sort(i);
	for(i=top;i>1;i--)
		printf("%d ",stack[i]);
	printf("%d\n",stack[i]);
}
int main()
{
	int n,m,f,i,j;
	scanf("%d%d",&n,&m);
	for(f=0;f<m;f++)
	{
		scanf("%d%d",&i,&j);
		insert(i,j);
	}
	topolog(n);
	return 0;
}
