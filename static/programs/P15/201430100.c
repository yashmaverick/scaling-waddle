#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	long long int value;
	long long int index;
	struct stack *next;
}stack;
 
typedef struct stack* link;

link head=NULL;

void pop()
{
	if(head==NULL) return;

	link temp=head;
	head=head->next;
	free(temp);
}


long long int push(long long int x,long long int i)
{
	if(head==NULL)
	{
		head=malloc(sizeof(stack));
		head->value=x;
		head->index=i;
		head->next=NULL;
		return -1;
	}

	if(x>head->value)
	{
		link temp;
		temp=malloc(sizeof(stack));
		temp->value=x;
		temp->index=i;
		temp->next=head;
		head=temp;
		return head->next->index;
	}

	pop();
	return push(x,i);
}

int main()
{
	long long int t,z;
	scanf("%lld",&t);

	for(z=0;z<t;z++)
	{
		head=NULL;
		long long int n,k,worse=0;
		scanf("%lld %lld",&n,&k);

		long long int i,a[n],b[n],last=-1;
	

		for(i=0;i<n;i++)
		{
		 	scanf("%lld",&a[i]);
			if(i!=0 && a[i]<a[i-1]) worse=1;


		}
		for(i=0;i<n;i++)
		{
			b[i]=push(a[i],i);
		}

		while(head!=NULL) pop();
		

		for(i=k-1;i<n;i++)
		{
			if(worse==0)
			{
			 printf("%lld",a[i-k+1]);
			 if(i!=n-1) printf(" ");
			}

			else
			{	
			if(a[i]<=last)
			{
				last=a[i];
				printf("%lld",a[i]);
				 if(i!=n-1) printf(" ");
			
			}
			else
			{
				long long int left=b[i],temp=a[i];
				while(left!=-1 && left>=i-k+1)
				{
					temp=a[left];
					left=b[left];
				}
				printf("%lld",temp);
			 	if(i!=n-1) printf(" ");
				last=temp;
			}
			}
		}
		printf("\n");

	}
	return 0;
}