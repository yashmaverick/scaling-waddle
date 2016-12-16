#include<stdio.h>
int main()
{
	long long int test,j,n;
	scanf("%lld",&test);
	for(j=0;j<test;j++)
	{
		long long int value=0;
		scanf("%lld",&n);
		long long int count=0,flag=0;
		long long int t=n;
		while(t>1)
		{
			t=t/2;
			count++;
		//         printf("%dxxxxx\n",count);
		}
		t=n;
		while(t>1)
		{

			if(t==2)
			{
				flag=1;
				long long int value=2*count-1;
				printf("%lld\n",value);
				break;
			}
		       t=t/2;
		}
		if(flag==0)
		{
			long long int value=2*count;
		
		printf("%lld\n",value); 
		}
		//printf("%d\n",value);
	}
	return 0;
}










