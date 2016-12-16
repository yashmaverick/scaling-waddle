#include<stdio.h>
#include<stdlib.h>
typedef long long int L;
#define s(n) scanf("%lld",&n)

typedef struct node{
	L val;
	struct node* next;
}n;
typedef n* np;
np head;

void push(L x)
{
	np temp;
	temp=(np)malloc(sizeof(n));
	temp->val = x;
	temp->next = head;
	head=temp;
}

void pop()
{
	if(head!=NULL)
	{
		np temp;
		temp = head->next;
		free(head);
		head=temp;
	}
	else
		return;
}

L peek()
{
	return head->val;
}

int main()
{
	L a[100000],i;
	L max, area, temp;
	L n;
	while(1)
	{
		s(n);
		if(n==0)
			break;
		while(head!=NULL)
			pop();
		for(i=0;i<n;i++)
			s(a[i]);
		max = 0;
		i=0;
		a[n]=0;
		/*
		   while(i<n)
		   {
		   if( head ==NULL || a[i] >= a[peek()])
		   push(i);
		   else
		   {
		   temp = peek();
		   pop();
		   area = a[temp]*(i-peek());
		   if (area > max )
		   max = area;
		   i++;
		   }
		   printf("%lld\n",max);
		   }
		*/
		for(i=0;i<=n;i=i+0)
		{
			if(head == NULL || a[i] >= a[peek()])
			{
				push(i);
				i++;
				//printf("Value of i is %lld and a[i] is %lld\n",i,a[i]);
			}
			else
			{
				//while(a[i] < a[peek()] && head!=NULL)
				//{
				temp = peek();
				pop();	
				if(head!=NULL)
				{
					area = a[temp] *(i-1-peek());
					//printf("%lld\n",area);
				}
				else
					area = a[temp]*i;
					//printf("%lld\n",area);
				if(area > max)
					max = area;
				//}
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}

