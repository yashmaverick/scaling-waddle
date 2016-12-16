#include<stdio.h>
#include<stdlib.h>

typedef struct c
{
	long long int data;
	struct c *next;
}node;
int top=-1;
//node *temp=-1;
long long int c=0,s[1000000];
void push(long long int b[],long long int value)
{
	//node *temp=malloc(sizeof(node));
	c++;
	top++;
	b[top]=value;
	return;
}

void pop()
{
	c--;
	top--;
	return;
}

/*void display()
{
	node *temp=malloc(sizeof(node));
	temp=top;
	while(temp!=-1)
	{
		printf("%lld ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return;
}*/

long long int main()
{
	long long int n,i;
	scanf("%lld",&n);
	while(n!=0){
	long long int a[n];
	long long int count=0,flag=1;
	top=-1;
	c=0;
	for(i=0;i<n;i++)
	{
		int in=0;
		scanf("%lld",&a[i]);
		if(top==-1||a[i]<a[s[top]])
		{
			flag=1;
			push(s,i);
		}
		/*else if(a[i]==a[top->data])
		{
			//printf("here\n");
			flag++;
			if(c==flag-1)
				flag--;
			count+=flag-1;		
			push(i);
		}*/
		else
		{
			flag=1;
			while(a[i]>a[s[top]])
			{
					pop();
				if(top!=-1)
					count++;
				else if(top==-1)
					break;
			}
			 int temp=top;
			if(temp!=-1)
			{
			while(a[i]==a[s[temp]])
			{
				in=1;
				count++;
				temp--;
				if(temp==-1)
				{	count--;
					break;
				}
			}
			}
			//if(in=1)
			//	count--;
			//if(top!=-1&&top->next!=-1&&a[i]==a[top->data]&&a[i]==a[top->next->data])
			//	count++;
			push(s,i);
		}
		//display();
		//printf("count is %lld\n",count);
	}
	n=n-2;
	long long int r=(n*(n+1))/2;
	if(n==0)
		printf("0\n");
	else
	{long long int qw=r-count;
	printf("%lld\n",qw);
	}
	scanf("%lld",&n);
	}
	return 0;
}

