#include<stdio.h>
#include<stdlib.h>

long long int max=0;

typedef struct list
{
	long long int value;
	long long int count;
	struct list *next;
}list;

typedef struct list *link;

link head=NULL;

long long int top()
{
	if(head==NULL) return -1;

	return head->value;
}

void pop(link temp,long long int number,long long int x)
{
	if(temp==NULL) 
	{
		if(x<0) return;

		head=malloc(sizeof(list));
		head->value=x;
		head->count=number+1;
		head->next=NULL;
		return;
	}

	if(temp->value==x)
	{
		temp->count+=(number+1);

		long long int l;
		l=(temp->count)*(temp->value);
		if(l>max) max=l;

		return;
	}

	if(temp->value<x)
	{
			link temp3;
			temp3=malloc(sizeof(list));
			temp3->count=number+1;
			temp3->value=x;
			temp3->next=head;
			head=temp3;
			return;
	} 

	temp->count+=number;
	long long int l;
	l=(temp->count)*(temp->value);
	if(l>max) max=l;
		
	link temp2;
	temp2=temp->next;
	number=temp->count;
	head=temp2;
	free(temp);
	pop(temp2,number,x);
}

int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		head=NULL;
		max=0;
		long long int i;

		for(i=0;i<n;i++)
		{	
			long long int x,y;
		scanf("%lld",&x);

		y=top();

		if(x==y) { head->count++; if(((head->count)*(head->value))>max) max=(head->count)*(head->value); }
		else if(x>y)
		{
			link temp;
			temp=malloc(sizeof(list));
			temp->next=head;
			temp->value=x;
			temp->count=1;
			head=temp;

			if(x>max) max=x;
		}
		else if(x<y)
		{
			pop(head,0,x);
		}	

		}
		while(head!=NULL)
		{
			pop(head,0,-2);
		}


		printf("%lld\n",max);


		scanf("%lld",&n);
	}
	return 0;
}	