#include<stdio.h>
int fun(long long int a[],int n)
{
	int i,j,maxdiff,diff;
	maxdiff=i=0;
	for(j=i+1;j<n;j++)
	{
		diff=a[j]-a[i];
		if(diff<0)
			i=j;
		else if(maxdiff<diff)
			maxdiff=diff;
	}	
	return maxdiff;
}
int main()
{
int t,i,n,j;
long long int a[100001];
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%d",&n);
for(j=0;j<n;j++)
scanf("%lld",&a[j]);
printf("%d\n",fun(a,n));
}
return 0;
}
