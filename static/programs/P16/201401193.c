#include<stdio.h>
long long int a[40];
int find(long long int n)
{
	int i;
	for(i=0;i<40;i++)
		if(a[i]>n)
			return i;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	a[0]=1;
	for(i=1;i<40;i++)
		a[i]=a[i-1]*2;
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		int k=find(n)-1;
		if(n<a[k]+a[k-1])
			printf("%d\n",2*k-1);
		else
			printf("%d\n",2*k);
	}
	return 0;
}
