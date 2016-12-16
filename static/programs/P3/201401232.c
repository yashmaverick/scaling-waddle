#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n--)
	{
		long long int size,i,s[100000];
		scanf("%lld",&size);
		scanf("%lld",&s[0]);
		long long int min=s[0],diff=0;
		for(i=1;i<size;i++)
		{
			scanf("%lld",&s[i]);
			if(s[i]<min)
				min=s[i];
			if(diff<(s[i]-min))
				diff=s[i]-min;
		}
		printf("%lld\n",diff);
	}
	return 0;
}
