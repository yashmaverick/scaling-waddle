#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	long long int pre[10000]={0};
	long long int tc,n,m,a,b,c,i,j,k;
	for(i=0;i<100;i++)
	{
		pre[i]=pre[i-1]+pow(2,i-1);
	}
	scanf("%lld", &tc);
	for(k=0;k<tc;k++)
	{
	scanf("%lld", &n);
	long long int val;
	val=log(n)/log(2);
	if(pre[val+1]-n<((pow(2,val))/2))
		printf("%lld\n", val*2);
	else
		printf("%lld\n", val*2-1);
	}
	return 0;
}
