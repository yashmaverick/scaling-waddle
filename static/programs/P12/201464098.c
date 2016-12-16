#include<stdio.h>
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int a[n];
		long long int i,g;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int stack[n];
		long long int top=0,k;
		stack[0]=0;
		long long int count=0;
		for(i=1;i<n;i++)
		{
			if(a[i] <= a[stack[top]])
			{
				stack[++top]=i;
			}
			else
			{
				while(top!=-1 && a[i]>a[stack[top]])
				{ 		
					count+=n-1-i;
					k=top;
					while(k>1 && a[stack[k]]==a[stack[k-1]])
						k--;
					if(k==0)
						k=1;
						count=count+k-1;
						//printf("count=%lld\n",count);
					top--;
				}
				top++;
				stack[top]=i;
			}
		}
		long long int luck;
		while(top>1)
		{
			luck=top;
			k=top;
			while(k>1 && a[stack[k]]==a[stack[k-1]])
				k--;
			if(k==0)
				k=1;
			top=luck;
			count=count+k-1;
			top--;
		}
		printf("%lld\n",count);
	}
	return 0;
}
