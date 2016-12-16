#include<stdio.h>
long long int A[1000008];
long long int top;
void push(long long int n)
{
	top++;
	A[top]=n;
}
void pop()
{
	top--;
}
void print()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%lld ",A[i]);
	}
	printf("\n");
}
int emp()
{
	if (top==-1)
	{
		return 0;
	}
	return 1;
}
int main()
{
	while(1)
	{
		top=-1;
		long long int n,i,c=0,count=0,k;
		scanf("%lld",&n);
		long long int a[n];
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(top==-1)
			{
				push(i);
				if(top>1)
				{
					k=top-1;
					while(a[A[k]]==a[A[top]]&&k!=-1)
					{
						k--;
					}
					if(k!=-1)
						c=c+k;
				}
				//		i++;

			}

			else if(a[i]<=a[A[top]])
			{
				push(i);
				if(top>1)
				{
					k=top-1;
					while(a[A[k]]==a[A[top]]&&k!=-1)
					{
						k--;
					}
					if(k!=-1)
						c=c+k;
				}
				//		i++;
			}
			//	while(a[i]>A[top])
			else
			{
				count=count+(n-i-1);
				pop();
				/*	if(emp()==0)
					{
					push (a[i]);
					break;
					}*/
				i--;

			}

		}
		printf("%lld\n",(count+c));
	}
	return 0;
}
