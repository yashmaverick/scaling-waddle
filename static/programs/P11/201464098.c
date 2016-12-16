#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
	long long int *s;
	long long int top;
}st;
st *p=NULL;
void pop()
{
	p->top--;
}
void push(long long int number)
{
	p->top++;
	p->s[p->top]=number;
}
int main()
{
	long long int i,n,t;
	while(1)
	{
		long long int max=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		p=(st *)malloc(sizeof(st));
		p->s=(long long int *)malloc((n+1)*sizeof(long long int));
		p->top=-1;
		long long int you;
		long long int *area;	
		long long int *arr;
		area=(long long int *)malloc(n*sizeof(long long int));
		arr=(long long int *)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<n;i++)
		{
			while(p->top!=-1)
			{
				you=p->s[p->top];
				if(arr[i]<=arr[you])
				{
					pop();
				}
				else
					break;
			}
			if((p->top)==-1)
				t=-1;
			else
				t=you;
			area[i]=i-t-1;
			push(i);
		}
	while((p->top)!=-1)
		pop();
	for(i=n-1;i>=0;i--)
	{
		while((p->top)!=-1)
		{
			you=p->s[p->top];
			if(arr[i]<=arr[you])
				pop();
			else
			break;
		}
	if((p->top)==-1)
		t=n;
	else
		t=you;
	area[i]+=t-i-1;
	push(i);
	}
	/*for(i=0;i<n;i++)
	printf("%d",area[i]);
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		area[i]=arr[i]*(area[i]+1);
		if(area[i]>max)
			max=area[i];
	}
	printf("%lld\n",max);
  }
return 0;
}
