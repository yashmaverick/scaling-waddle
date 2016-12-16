#include<stdio.h>
#include<stdlib.h>
struct node{
	long long int data;
	struct node *next;
};
struct node *head;
void push(int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}
long long int pop()
{
	struct node *temp=NULL;
	long long int x;
	if(head==NULL)
		return;
	x=head->data;
	temp=head;
	head=head->next;
	free(temp);
	return x;
}
long long int peek()
{
	long long int x;
	x=head->data;
	return x;
}
/*void print()
  {
  struct node *temp=head;
  while(temp!=NULL)
  {
  printf("%d ",temp->data);
  temp=temp->next;
  }
  }*/

int main()
{
	long long int n,a[100004],i,t;
	long long int max,area,x;
	//scanf("%d",&t);
	//scanf("%lld",&n);
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		i=0;max=0;
		while(i<n)
		{
			if(head!=NULL && a[peek()]>a[i])
			{
				x=peek();
				pop();
				if(head!=NULL)
				{
					area=(a[x]*(i-1-peek()));
				}
				else
				{
					area=(a[x]*i);
				}
				if(area>max)
					max=area;
			}
			else
			{
				push(i);
				i++;
			}
		}
		while(head!=NULL)
		{
			x=peek();
			pop();
			if(head!=NULL)
			{
				area=(a[x]*(i-1-peek()));
			}
			else
			{
				area=(a[x]*i);
			}
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
		
		}
	}
	return 0;
}
