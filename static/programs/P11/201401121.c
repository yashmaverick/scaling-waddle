#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int val;
	long long int ind;
	long long int data;
}node;
int main()
{

	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int *a=malloc(n*sizeof(long long int));
		node *b=malloc(n*sizeof(node));
		long long int i=0;
		long long int top=-1;
		long long int max=0;
		for(;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(top==-1)
			{
				top++;
				b[top].data=a[i];
				b[top].val=1;
				b[top].ind=i;
			}
			else
			{
				long long int temp=b[top].val;
				long long int cnt=0;
				while(a[i] < b[top].data)
				{
					if(((i-1-b[top].ind+b[top].val) * b[top].data)> max)
						max=(i-1-b[top].ind+b[top].val) * b[top].data;

					cnt+=b[top].val;
					top--;
					if(top==-1)
						break;
					
				}
				b[top+1].val=cnt+1;
				b[top+1].ind=i;
				b[top+1].data=a[i];
				top++;
			}
		}
		for(i=0;i<=top;i++)
		{
			if(max < (n-1-b[i].ind+b[i].val)*b[i].data)
				max=(n-1-b[i].ind+b[i].val)*b[i].data;
		}
		printf("%lld\n",max);
		free(a);
		free(b);
	}

	return 0;
}






