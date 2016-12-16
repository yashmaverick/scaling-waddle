/* Code written by - Abhishek on 02/03/2014
	***All rights reserved *** */
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef long long int ll;
struct node{
	int ind;
	int val;
	struct node* next;
};
void push(node** head,ll i,ll data)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->ind=i;
	tmp->val=data;
	tmp->next=*head;
	*head=tmp;
}
void pop(node** head)
{
	node* tmp=*head;
	*head=(*head)->next;
	free(tmp);
}
ll top(node* head)
{
	if(head!=NULL)
	{
		return head->ind;
	}
}
int main()
{
	while(1)
	{
		ll n,i,j,k,l;
		scanf("%Ld",&n);
		if(n==0)
		{
			break;
		}
		ll a[100100];
		node* head=NULL;
		ll max,res,st;
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%Ld",&a[i]);
		}
		for(i=0;i<=n-1; )
		{
			if(head==NULL || a[i]>=a[top(head)])
			{
				push(&head,i,a[i]);
				i++;
			}
			//		printf("Ind:%d\t",top(head));
			/*	while(head!=NULL && a[i+1]<a[top(head)])
				} */
		else
		{
			st=head->val;
			pop(&head);
			if(head==NULL)
			{
				//0 indicates left index till 0.
				res=(st)*(i-0);
			}
			else
			{
				//Taking care of left index to right index. i-1 for right index, top for right.
				res=(st)*(i-1-top(head));
			}
			//		printf("%d\t",res);
			if(res>max)
			{
				max=res;
			}
		}
	}
	while(head!=NULL)
	{
		st=head->val;
		pop(&head);
		if(head==NULL)
		{
			res=(st)*(i);
		}
		else
		{
			res=(st)*(i-1-top(head));
		}
		//		printf("%d\t",res);
		if(res>max)
		{
			max=res;
		}
	} 
	printf("%Ld\n",max);
	}
return 0;
}
