#include<stdio.h>
#include<stdlib.h>

struct stack{
	long long int val;
	long long int pos;
	struct stack *next;
};

long long int counter=0;
long long int num=0;

struct stack* mystack=NULL;

void push(long long int x, long long int y)
{
	num++;
	struct stack* tempptr=malloc(sizeof(struct stack));
	tempptr->val=x;
	tempptr->pos=y;
	tempptr->next=mystack;
	mystack=tempptr;
	counter++;
}

void pop()
{
	if(mystack!=NULL)
	{
		mystack=mystack->next;
		counter--;
		num--;
	}
}

int isempty()
{
	if(mystack==NULL)
		return 1;
	else
		return 0;
}

int top()
{
	return mystack->val;
}

int top1()
{
	return mystack->pos;
}

int main()
{
	long long int a,b,c,i,j,k,n,m,count=0;
	long long int sum=0;
	int A[500001];
	int pre[500001];
	int post[500001];
	scanf("%lld", &n);
	while(n!=0)
	{
		mystack=NULL;
		counter=0;
		num=0;
		sum=0;
		pre[0]=0;
		post[0]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &A[i]);
			pre[i+1]=0;
			post[i+1]=0;
		}
		for(i=0;i<n;i++)
		{
			count=0;
			while(isempty()!=1 && top()<A[i])
			{
				count++;
				pre[i+1]+=post[top1()];
				pop();
			}
			while(isempty()!=1 && top()==A[i])
			{
				post[i+1]=post[top1()]+1;
				pop();
			}
			pre[i+1]+=count;
			if(isempty()!=1)
			{
				sum++;
			}
			push(A[i],i+1);
			sum+=post[i+1]+pre[i+1];
		}
		printf("%lld\n", n*(n-1)/2-sum);
		scanf("%lld", &n);
	}
	return 0;
}
