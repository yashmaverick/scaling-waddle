#include<stdio.h> 
#include<stdlib.h>

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		long long int i;
		int n;                //i is input array size (1<=i<=10^5)
		long long int inarray[100010];
		long long int b;
		scanf("%d", &n);
		for(i=0; i<n; i++) 
		{
			scanf("%lld", &b);
			inarray[i] = b;
		}
		long long int profit[100010];
		for(i=0; i<n-1; i++)
			//if(inarray[j]<inarray[j+1] )
		{
			//for(e=0; e<n; e++)
			profit[i] = inarray[i+1]-inarray[i];
			/*if (inarray[j+1]<inarray[j+2] && (j+2)<=n)
			  {
			  profit2 = inarray[j+2]-inarray[j+1] ;
			  }*/
		}

		long long int max=0,sum=0;
		for(i=0; i<n-1; i++)
		{
			sum += profit[i] ;
			if(sum < 0)
			{
				sum=0;
			}
			if(sum>=max)
			{
				max=sum;
				//sum = profit[e] + profit[e+1];
			}
		}
		printf("%lld\n", max);
		/*sum += profit[e]
		  printf("0\n");

		  if(profit1 > profit2)
		  {
		  printf("%llu\n", profit1);
		  }
		  else
		  printf("%llu\n", profit2);
		 */

	}
	return 0;
}

