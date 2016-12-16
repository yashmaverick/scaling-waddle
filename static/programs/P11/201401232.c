#include<stdio.h>
#include<stdlib.h>
struct node {
	long long int value;
	long long int index;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
long long int logs[100000];
long long int topper;
long long int size=0;
long long int size1,ans;
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
}
void pop()
{
	if(size==0)
		return ;
	else if(size==1)
	{
		free(head);
		head=NULL;
		size--;
	}
	else
	{
		node *temp=head;
		head=head->next;
		free(temp);
		size--;
	}
}
void top()
{
	if(size==0)
		return ;
	else
	{
		topper=head->value;
	}
}
long long int compute()
{
	long long int temp;
	long long int j=0;
	long long int max=0;
	long long int area;
	while(j<size1)
	{
		if(size==0 || logs[j]>=topper)
		{
			push(logs[j],j);
			j++;
			top();
		}
		else
		{
			{
				temp=head->index;
				pop();
				top();
				if(size==0)	
					area=(j)*logs[temp];
				else
					area=(j-(head->index)-1)*logs[temp];
				if(area>max)
					max=area;
			}
		}
	}
	while(size!=0)
	{
		temp=head->index;
		pop();
		top();
		if(size==0)	
			area=(j)*logs[temp];
		else
			area=(j-(head->index)-1)*logs[temp];
		if(area>max)
			max=area;
	}
return max;
}
int main()
{
	scanf("%lld",&size1);
	long long int i;
	while(size1!=0)
	{
		head=NULL;
		for(i=0;i<size1;i++)
			scanf("%lld",&logs[i]);
		ans=compute();
		printf("%lld\n",ans);
		scanf("%lld",&size1);
	}
	return 0;
}
