#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int stock[100000];
		int days,i;
		scanf("%d",&days);
		for(i=0;i<days;i++)
		{
			scanf("%lld",&stock[i]);
		}		
		long long int min=1000000000,maxdiff=0,k;
		for(i=0;i<days;i++)
		{
			if(min>stock[i])
			{
				min=stock[i];
			}
			k=stock[i]-min;
			if(maxdiff<k)
				maxdiff=k;	
		}
		printf("%lld\n",maxdiff);
	}
	return 0;
}
