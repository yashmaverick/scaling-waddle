#include<stdio.h>
typedef struct node
{
	int data;
	int eq;
}node;
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			break;
		node b[n];
		int a[n];
		long long int cnt=0;
		int top=-1;
		int i=0;
		for(;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(top==-1)
			{
				top++;
				b[top].data=a[i];
				b[top].eq=0;
			}
			else
			{
				while(a[i]>b[top].data)
				{
					top--;
					cnt++;
					if(top==-1)
						break;
				}
				top++;
				b[top].data=a[i];
				if(top!=0)
				{	
					if(a[i]==b[top-1].data)
						b[top].eq=b[top-1].eq+1;
					else
						b[top].eq=1;
				}
				else
				{
					b[top].eq=0;
				}
				cnt+=b[top].eq;
			}
		}
		long long int k=(n*(n-1))/2;
		printf("%lld\n",k-cnt);
	}
	return 0;
}



					
				

				





			




