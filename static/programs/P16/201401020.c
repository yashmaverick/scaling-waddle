#include<stdio.h>
long long int a[35];
int main()
{
	long long int n,l,k,i;
	scanf("%lld",&n);
	a[0]=1;
	for(i=1;i<31;i++)
		a[i]=2*a[i-1];
	while(n--)
	{
		scanf("%lld",&l);
		k=0;
		while(a[k]<=l)
		{
			k++;
		}
		k--;
		if(l<(a[k]+a[k+1])/2)
			printf("%lld\n",2*k-1);
		else
			printf("%lld\n",2*k);
	}
	return 0;
}
