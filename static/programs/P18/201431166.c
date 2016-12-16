#include<stdio.h>
#include<stdlib.h>

typedef struct linklist
{
	struct linklist *next;
	int value;
}linklist;

struct stack
{
	int top;
	int stk[10000];
}stack,stack1;

void push(int value)
{
	stack.top+=1;
	stack.stk[stack.top]=value;
}

void push1(int value)
{
	stack1.top+=1;
	stack1.stk[stack1.top]=value;
}

void pop()
{
	stack.top-=1;
}

void pop1()
{
	stack1.top-=1;
}

linklist *insert(linklist *head,int va)
{	
	linklist *new=(linklist*)malloc(sizeof(linklist));
	new->value=va;
	linklist *tmp;
	tmp=head;
	new->next=NULL;
	if(head==NULL)
	{	head=new;
		return head;
	}
	else 
	{
		new->next=tmp;
		head=new;
		return head;
	}
}

int main()
{	
	linklist *head[100000],*head1[100000];
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int i;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{	
			head[i]=NULL;
			head1[i]=NULL;
		}
		int m=n,realms,count=1,vis[100000];
		while(m--)
		{
			int num;
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&realms);
				head[realms]=insert(head[realms],count);
				head1[count]=insert(head1[count],realms);
			}
			count++;
		}
/*
		for(i=1;i<=n;i++)
		{
			linklist *temp=head[i];
			printf("%d ->>",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->value);
				temp=temp->next;
			}
			printf("\n");
		}

		for(i=1;i<=n;i++)
		{
			linklist *temp=head1[i];
			printf("%d ->>",i);
			while(temp!=NULL)
			{
				printf("%d ",temp->value);
				temp=temp->next;
			}
			printf("\n");
		}
*/
		int count2=0;
		//dfs :-----
		int l,flag1=0,count1=0;
		for(i=1;i<=n;i++)
		{	count1=0;
			stack.top=-1;
			int k;
			for(k=1;k<=n;k++)
				vis[k]=0;
			push(i);
			vis[i]=1;
			int d;
			while(stack.top!=-1)
			{
				d=stack.stk[stack.top];
				pop();
				linklist *temp=head[d];
				while(temp!=NULL)
				{
					if(vis[temp->value]==0)
					{
						vis[temp->value]=1;
						push(temp->value);
					}
					temp=temp->next;
				}
			}

			int j;
			for(j=1;j<=n;j++)
			{	
				if(vis[j]==1)
				{
					count1++;
				}
			}
			if(count1==n)
			{
				l=i;
				flag1=1;
				count2++;
				break;
			}
		
		}
		stack1.top=-1;
		int k1;
		for(k1=1;k1<=n;k1++)
			vis[k1]=0;
		push1(l);
		vis[l]=1;
		int d1;
		while(stack1.top!=-1)
		{
			d1=stack1.stk[stack1.top];
			pop1();
			linklist *temp1=head1[d1];
			while(temp1!=NULL)
			{
				if(vis[temp1->value]==0)
				{
					vis[temp1->value]=1;
					push1(temp1->value);
					count2++;
				}
				temp1=temp1->next;
			}
		}
		printf("%d\n",count2);
	}
	return 0;
}
