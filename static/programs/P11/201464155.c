#include<stdio.h>
#include<stdlib.h>
/*typedef storeruct c
{
	long long int data;
	storeruct c *next;
}node;
node *top=NULL;
node *rear=NULL;
long long int count=0;
void push(long long int val)
{
	count++;
	node *temp;
	temp=malloc(sizeof(node));
	temp->data=val;
	temp->next=top;
	if(top==NULL)
	{
		top=temp;
		rear=temp;
	}
	else
		top=temp;   
	return;
	printf("Dta is %lld\n",top->data);
}

void pop()
{
	top=top->next;
	count--;
	return;
}   
void display()
{ 
	node *temp;
	temp=malloc(sizeof(node));
	temp=top;
	printf("The storeack is ");
	while(temp!=NULL)
	{
		printf("%lld ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}*/


long long int a[1000000];
long long int store[1000000];
int main()
{
	long long int i,n;
	long long int top;
	scanf("%lld",&n);
	while(n!=0)
	{

		top=-1;
		long long int h;
		long long int max=-1;
		long long int area,t;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(top==-1||a[store[top]]<=a[i])
			{
				top++;
				store[top]=i;
			}
			else
			{
				while((a[store[top]]>a[i])&&(top>-1))
				{
					h=store[top];
					top--;
					if(top==-1)
						t=i;
					else
						t=i-store[top]-1;
					area=a[h]*t;
					if(area>max)
						max=area;
				}
				top++;
				store[top]=i;
			}

		}
		while(top>-1)
		{
			h=store[top];
			top--;
			if(top==-1)
				t=i;
			else
				t=i-store[top]-1;
			area=a[h]*t;
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
		//long long int n;
		scanf("%lld",&n);
	}
	return 0;
} 
