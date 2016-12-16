#include<stdio.h>
unsigned int Log2n(unsigned int n)
{
	return (n > 1)? 1 + Log2n(n/2): 0;
}
int twopown(int n)
{
	int i,ans=1;
	if(n==0)
		return 1;
	else
	{
		for(i=0;i<n;i++)
			ans=ans*2;
		return ans;
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		unsigned int Q;
		int x;
		scanf("%u",&Q);
		x=Log2n(Q);
		if(x==0)
			printf("0\n");
		else
		{
			if(Q<3*twopown(x-1))
				printf("%d\n",2*x-1);
			else
				printf("%d\n",2*x);
		}
	}
	return 0;
}
