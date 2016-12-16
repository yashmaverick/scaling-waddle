#include<stdio.h>
long long int t,j,n,i,top=-1,count,A[1000001],S[100001];
void push(long long int x)
{
	top++;
	S[top]=x;
}
void pop()
{
	top--;
}
void daen()
{
	count=0;
	for(i=0;i<n;i++)
	{
		if(top==-1)
		{
			push(i);
			if(top>1)
			{
				j=top-1;
				while(A[S[j]]==A[S[top]]&&j!=-1)
					j--;
				if(j!=-1)
					count=count+j;
			}
		}
		else if (A[i]<=A[S[top]])
		{
			push(i);
			if(top>1)
			{
				j=top-1;
				while(A[S[j]]==A[S[top]]&&j!=-1)
					j--;
				if(j!=-1)
					count=count+j;
			}
		}
		else 
		{
			pop();
			count+=n-i-1;
				i--;
		}
	}
	printf("%lld\n",count);
}

int main()
{
	long long int i;
	scanf("%lld",&n);
	while(n!=0)
	{
		top=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
		}
		daen();
		scanf("%lld",&t);
		n=t;
	}
	return 0;
}
