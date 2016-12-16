#include<stdio.h>
#include<math.h>
long long int top=-1,A[500001],S[500001];
void push(long long int i)
{
	top=top+1;
	S[top]=i;
}
void pop()
{
	if(top==-1)
		return ;
	else
		top=top-1;
}
long long int topv()
{
	return top;
}
void scan(long long int n,long long int A[])
{
	int i;
	for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
}
void print(long long int count)
{
	printf("%lld\n",count);
}
int main()
{
	long long int i,j,bar,n,p,k,l;
	long long int count=0,area,c;
	l=1;
	while(l==1)
	{
		count=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		scan(n,A);
		i=0;
		while(i<n)
		{
			if(top==-1 || A[i]<=A[S[top]])
			{ 
				push(i);p=top;
				while(p>=0 && A[i]==A[S[p]])p--;
				//printf("pushed=%lld\n",i);
				if(p>0)	count=count+p;i++;
			}
			else
			{
				bar=i;pop();k=n-i-1;count=count+k;
				//printf("count=%lld\n",count);
			}
		}print(count);count=0;top=-1;
	}
	return 0;
}
