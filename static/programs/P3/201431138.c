#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		long long int s[100000];
		int d,i;
		scanf("%d",&d);
		for(i=0;i<d;i++)
		{
			scanf("%lld",&s[i]);
		}		
		long long int m=1000000000,diff=0,k;
		for(i=0;i<d;i++)
		{
			if(m>s[i])
			{
				m=s[i];
			}
			k=s[i]-m;
			if(diff<k)
				diff=k;	
		}
		printf("%lld\n",diff);
	}
	return 0;
}
