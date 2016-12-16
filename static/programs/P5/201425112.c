//The Three Nights

#include <stdio.h>
#include <string.h>

void quicksort(int values[], int start, int end);

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t!=0)
	{
		int n;
		scanf("%d", &n);
		
		int k;
		scanf("%d", &k);
		
		char string[1000];
		int values[1000];
		
		int i;
		for(i=0; i<n; i++)
		{
			scanf("%s", string);
			
			scanf("%d", &values[i]);
			
			/*/debug
			printf("%s ", string);
			printf("%d ", values[i]);
			printf("\n");
			/*/
		}
		
		/*/debug
		for(i=0; i<n; i++)
			printf("%d ", values[i]);
		printf("\n");
		/*/
		
		quicksort(values, 0, n-1);
		
		/*/debug
		for(i=0; i<n; i++)
			printf("%d ", values[i]);
		printf("\n");
		/*/
		
		int j;
		int h;
		int flag=0;
		int sum;
		
		for(i=0; i<n; i++)
		{
			j=i+1;
			h=n-1;
			
			while(j<h)
			{
				sum = values[j]+values[h]+values[i];
				
				if(sum==k)
				{
					flag=1;
					printf("YES\n");
					break;					
				}
				else if(sum<k)
				{
					j++;
				}
				else
				{
					h--;
				}
			}
			
			if(flag==1)
					break;			
		}
		
		if(flag==0)
		{
			printf("NO\n");
		}
		
		t--;
	}
	
	return 0;
}

void quicksort(int values[], int start, int end)
{
	int pivot;
	int left;
	int right;
	int sub;
	
	if (start<end)
	{
		pivot=start;
		left=start;
		right=end;
		
		/*/debug
		printf("%d %d %d", pivot, left, right);
		printf("\n");
		/*/
		
		while(left<right)
		{
			while(values[left]<=values[pivot] && left<=end)
			{
				left++;
			}
			
			/*/debug
			printf("%d", left);
			printf("\n");
			/*/
			
			while(values[right]>values[pivot] && right>=start)
			{
				right--;
			}
			
			/*/debug
			printf("%d", right);
			printf("\n");
			/*/
			
			if(left<right)
			{
				sub=values[left];
				values[left]=values[right];
				values[right]=sub;
			}
		}
		
		sub=values[right];
		values[right]=values[pivot];
		values[pivot]=sub;
		
		quicksort(values, right+1, end);
		quicksort(values, start, right-1);

			
	}
}
