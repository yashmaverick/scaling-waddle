#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int value;
	long long int index;
	struct node *next;
}node;
long long int topper;
node *head;
long long int size=0;
void push(long long int value,long long int index)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->value=value;
	temp->index=index;
	if(head!=NULL)
	{
		temp->next=head;
		head=temp;
		size++;
		return ;
	}
	head=temp;
	head->next=NULL;
	size++;
	return ;
}
void pop()
{
	if(head==NULL)
		return ;
	node *temp=head;
	head=head->next;
	size--;
	free(temp);
	return ;
}
void top()
{
	if(head==NULL)
		return ;
	topper=head->value;
	return ;
}
int main()
{
	long long int n,i,j,sum,temp1,repitition;
	node *temp;
	long long int input[1000000];
	scanf("%lld",&n);
	while(n!=0)
	{
		j=1;
		sum=0;
		long long int c[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&input[i]);
		}
		push(input[0],0);
		top();
		repitition=0;
		while(j<n)
		{
			if(head==NULL || input[j]<=topper)
			{
				push(input[j],j);
				top();
				if(size>2)
				{
					temp=head->next;
					while(temp!=NULL && topper==(temp->value))
					{
						repitition++;
						temp=temp->next;
					}
					temp1=((size)-(2)-(repitition));
					repitition=0;
					if(temp1<0)
						temp1=0;
					sum=sum+temp1;
				}
				j++;
			}
			else if(input[j]>topper)
			{
				sum=sum+(n-j-1);
				//				printf("topper:%lld   num:%lld  j:%lld\n",topper,head->value,j);
				pop();
				top();
			}
		}
		//	j--;
			while(head!=NULL)
			{
		pop();
		}
		printf("%lld\n",sum);


		scanf("%lld",&n);

	}
	return 0;
	}
