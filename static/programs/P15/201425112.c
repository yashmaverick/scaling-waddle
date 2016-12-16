//fast minimum

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int n, k, i, j, min;
int arr[10000];

void run()
{
	//int n;
	scanf("%d", &n);
	//int k;
	scanf("%d", &k);
	
	//int min;
	//int i, j;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t!=0)
	{
		/*int arr[10000];
	
		int n;
		scanf("%d", &n);
		
		int k;
		scanf("%d", &k);
		
		int min;
		
		int i,j;
		for(i=1; i<=n; i++)
		{	
			scanf("%d", &arr[i]);
		}
		*/
		run();
		min=0;
		//int i, n, k, j, min;
		for(i=1; i<=(n-k+1); i++)
		{
			if (min<i || i==1)
			{
				min=i;
				
				for(j=(i+1); j<=(i+k-1); j++)
				{
					if(arr[min]>arr[j])
						min=j;
				}
			}
			
			else if (arr[min]>arr[i+k-1])
			{
					min=(i+k-1);
			}

			if(i==(n-k+1))
			{
				printf("%d", arr[min]);
			}
			
			else
			{
				printf("%d ",arr[min]);
			}
		}
		
		printf("\n");
		
		t--;
	}
	
	return 0;
}
