#include<stdio.h>
int x[1000000];
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int t,n,i,count,prev;
	long long int result;
	scanf("%lld",&t);
	while(t--)
	{
		result = 0; count = 1;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		qsort(x,n,sizeof(int),cmpfunc);
		prev = x[0];
		for(i=1;i<n;i++)
		{
			if(x[i]==prev)
				count++;
			else
				{
					result += (count*(count-1))/2;
					count = 1;
					prev = x[i];
				}

		}
		result += (count*(count-1))/2;
		printf("%lld\n",result);
	}
	return 0;
}
