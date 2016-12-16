#include<stdio.h>
#include<string.h>
long long int stack[500001],n,i,freq[500001],A[500001],count,top;
int main()
{
	long long int j,k,count_equal;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
			top=0;
			for(i=0;i<n;i++)
				scanf("%lld",&A[i]);
			stack[0]=A[0];
			count=0;
			for(i=1;i<n;i++)
			{
				if(A[i]<=stack[top])
				{
						k=top;
						while(k!=-1 && A[i]==stack[k])
						{
							k--;
						}
						if(k>=0)
							count+=k;
				
					top++;
					stack[top]=A[i];
				}	
				else if(A[i]>stack[top])
				{
					while(top!=-1 && A[i]>stack[top])
					{
						count+=n-i-1;
						top--;
					}
						k=top;
						while(k!=-1 && A[i]==stack[k])
						{
							k--;
						}
						if(k>=0)
							count+=k;
						top++;
						stack[top]=A[i];
				}
				

			}
				printf("%lld\n",count);
		}
	}
	return 0;	
}
