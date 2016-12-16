#include<stdio.h>
long long int b[100000],head=0,len=0;
void push(long long int x)
{
	b[head+len]=x;
	len++;
}
void pop()
{
	len--;
}
void dq()
{
	head++;
	len--;
}
int isempty()
{
	if(len==0)
		return 1;
	else
		return 0;
}
long long int top()
{
	return b[head+len-1];
}
long long int  front()
{
	return b[head];
}
int main()
{
	long long int t,i,n,k,a[100000],j;
	scanf("%lld",&t);
	while(t--)
	{
		len=0;
		head=0;
		scanf("%lld %lld",&n,&k);
		for(i=0;i<k;i++)
		{
			scanf("%lld",&a[i]);
			while(!isempty() && a[top()]>a[i])
			{
				pop();
			}
			push(i);
		}
/*		for(j=0;j<len;j++)
		{
			printf("%lld ",b[j+head]);
		}
		printf("\n");*/
		if(n!=k)
		{
			printf("%lld ",a[front()]);
		}
		else
		{
			printf("%lld\n",a[front()]);
		}
		for(i=k;i<n;i++)
		{
			scanf("%lld",&a[i]);
			while(!isempty() && front()<=(i-k))
			{
			//	printf("hello\n");
				dq();
			//	printf("%lld %lld\n",head,len);
			}
			while(!isempty() && a[top()]>a[i])
			{
		//		printf("hello ");
				pop();
			}
			push(i);
		//	printf("\n");
		/*	for(j=0;j<len;j++)
			{
				printf("%lld ",b[j+head]);
			}
			printf("\n");*/
			if(i!=(n-1))
			{
				printf("%lld ",a[front()]);
			}
			else
			{
				printf("%lld\n",a[front()]);
			}
		}
	}
	return 0;
}
