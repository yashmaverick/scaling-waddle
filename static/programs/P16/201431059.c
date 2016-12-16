#include<stdio.h>

int solve(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	if(n==3)
		return 2;
	return 2 + solve(n/2);
}


int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int q;
		scanf("%d",&q);
		printf("%d\n",solve(q));
	}
	return 0;
}
