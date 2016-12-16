#include<stdio.h>
long long int mystack[100005];
int main()
{
	long long int n;
	long long int R[100005];
	long long int L[100005];
	long long int i,area,maxarea,top;
	long long int A[100005];
	scanf("%lld",&n);
	while(n)
	{
		maxarea=0;
		top=1;
		mystack[0]=-1;
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		for(i=0;i<n;i++)
		{
			if(A[i]>A[mystack[top-1]])
			{
				L[i]=mystack[top-1];
				mystack[top]=i;
				top++;
			}
			else
			{
				while(A[i]<=A[mystack[top-1]] && top!=1)
				{
					top--;
				}
				L[i]=mystack[top-1];
				mystack[top]=i;
				top++;
			}
		}
		top=1;
		mystack[0]=n;
		for(i=n-1;i>=0;i--)
		{
			if(A[i]>A[mystack[top-1]])
			{
				R[i]=mystack[top-1];
				mystack[top]=i;
				top++;
			}
			else
			{
				while(A[i]<=A[mystack[top-1]] && top!=1)
				{
					top--;
				}
				R[i]=mystack[top-1];
				mystack[top]=i;
				top++;
			}
		}
		for(i=0;i<n;i++)
		{
			area=A[i]*(R[i]-L[i]-1);
			//				printf("l(%d)=%d r(%d)=%d ",i,L[i],i,R[i]);
			if(area>maxarea)
			{
				maxarea=area;
			}
		}
		printf("%lld\n",maxarea);
		scanf("%lld",&n);
	}
	return 0;
}
