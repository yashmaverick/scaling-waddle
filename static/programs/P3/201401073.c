#include<stdio.h>

#define MAX 100000

int main()
{
	int n,na,array[MAX],i,minimum,profit,tempprofit;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&na);
		for(i=0;i<na;i++)
			scanf("%d",&array[i]);		//array[i] < 10^9
		minimum = array[0];
		profit = 0;
		for(i=1;i<na;i++)
		{
			if(array[i]<=minimum)
				minimum = array[i];
			else
			{
				tempprofit = array[i] - minimum;
				if(tempprofit > profit)
					profit = tempprofit;
			}
		}
		printf("%d\n",profit);
	}
	return 0;
}


	
			


