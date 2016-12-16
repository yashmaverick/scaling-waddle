//program to print n-k+1 integers where the ith integer represents the minimum of a[i]----a[i+k-1]
//created by dipankar jain
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define tab printf("\t")
#define endl printf("\n")
#define space printf(" ")

int *array;

int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int n,k,i,j;
		gi(n);
		gi(k);
		array = (int *)malloc(n*sizeof(int));
		for( i=0 ; i<n ; i++ )
			gi(array[i]);
		int min=0;
		for( i=1 ; i<k ; i++ )
		{
			if(array[i] <= array[min])
				min = i;
		}
		pi(array[min]);
		if(n != k)
			space;
		for( i=k ; i<n ; i++ )
		{
			if(array[i] <= array[min])
				min = i;
			else
				if((i-min) >= k)
				{
					min = i-k+1;
					for( j=(i-k+2) ; j<=i ; j++)
					{
						if(array[j] <= array[min])
							min = j;
					}
				}
			pi(array[min]);
			if(i != n-1)
				space;
		}
		endl;
	}			
	return 0;
}
