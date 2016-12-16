#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(long long int *a, long long int *b)
{
	long long int t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	long long int n,i,j,t,a,b;
	long long int preorder[10010];
	long long int inorder[10010];
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&preorder[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&inorder[i]);
	scanf("%lld",&t);
	int ab;
	for(ab=1;ab<=t;ab++)
	{
		int f=0;
		long long int p,q;
		scanf("%lld%lld",&p,&q);
		for(i=1;i<=n;i++)
		{
			if(inorder[i]==p)
				a=i;
			else if(inorder[i]==q)
				b=i;
		}
		if(a>b)
			swap(&a,&b);
		for(i=1;i<=n;i++)
		{
			for(j=a;j<=b;j++)
			{
				if(inorder[j]==preorder[i])
				{
					printf("%lld\n",inorder[j]);
					f=1;
					break;
				}
			}
			if(f==1)
				break;
		}
	}
	return 0;
}
