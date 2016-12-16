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
ll b[100100]={0};
ll c[200100]={0};
ll k,n,max,min;
ll count=0;
void get_deep(ll start,ll end,ll a[],ll size)
{
	//	printf("%Ld\t",count);
	if(count>=max)
	{
		max=count;
	}
	/*	if(size<1 )
		return;
		if(start>=0&&start<n)
	//		printf("%Ld %Ld %Ld\n",k,start,a[start]);
	c[k++]=a[end];
	makepretopost(b[start],end,a,size);
	makepretopost(start+1,end,a,size);
	return;
	size=b[start]-start-1;
	makepretopost(start+1,b[start]-1,a,size); */
	if(size<1)
	{
		count--;
		return;
	}
	if(size==1)
	{
		if(count>=max)
		{
			c[k++]=max;
			c[k++]=a[start];
		}
		count--;
		return;
	}
	size=b[start]-end+1;
	count++;
	get_deep(b[start],end,a,size);
	size=start-1-b[start];
	count++;
	get_deep(start-1,b[start]+1,a,size);
	count--;
	return;
}
int main()
{
	int tes;
	scanf("%d",&tes);
	while(tes--)
	{
		ll stu,i;
		ll a[100100];
		node* head=NULL;
		scanf("%Ld",&n);
		k=0,max=0,count=0;
		for(i=0;i<n;i++)
		{
			scanf("%Ld",a+i);
			b[i]=0;
			c[i]=0;
		}
		for(i=0;i<2*n;i++)
		{
			c[i]=0;
		}
		min=10000000;
		for(i=n-1;i>=0;)
		{
			if(head==NULL || a[i]>a[top(head)])
			{
				push(&head,i,a[i]);
				i--;
			}
			else
			{
				stu=top(head);
				pop(&head);
				b[stu]=i;
			}
		}
		while(head!=NULL)
		{
			stu=top(head);
			pop(&head);
			b[stu]=stu-1;
		}
/*				for(i=0;i<n;i++)
				{
				printf("%Ld ",b[i]);
				}   */
		get_deep(n-1,0,a,n);
		for(i=0;i<2*n;i=i+2)
		{
			if(c[i]==max)
			{
				if(c[i+1]<min)
				{
					min=c[i+1];
				}
			}
		}
		printf("%Ld %Ld\n",min,max);
/*		for(i=0;i<2*n;i++)
		{
			printf("%Ld\n",c[i]);
		} 
		printf("\n"); */
	}
	return 0;
}
