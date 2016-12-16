#include<stdio.h>
int main()
{
	long long int n,a[100005],max,i,j,t;
	scanf("%lld",&t);
	while(t--)
	{
		max=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",a+i);
		i=0;j=1;
		while(j<n)
		{
			if(a[j]<a[i])
				i=j;
			else if((a[j]-a[i])>max)
				max=a[j]-a[i];
			j++;
		}
		printf("%lld\n",max);
	}
	return 0;
}



