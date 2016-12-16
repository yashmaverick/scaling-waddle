#include<stdio.h>
#include<limits.h>
int main()
{
	int t, size, price[100001], i, max, j, min, res;
	scanf("%d", &t);
	while(t--)
	{
		res = 0;
		max = INT_MIN;
		min = INT_MAX;
		scanf("%d", &size);
		if(size)
		{
			scanf("%d", &price[0]);
			max = min = price[0];
			res = max - min;
		}
		else
		{
			printf("0\n");
			break;
		}
		for(i = 1; i < size; i++)
		{
			scanf("%d", &price[i]);
			if(price[i] > max)
			{
				max = price[i];
				if(max - min > res)
				{
					res = max - min;
				}
			}
			if(price[i] < min)
			{
				min = max = price[i];		
				if(max - min > res)
				{
					res = max - min;
				}
			}
		}
		printf("%d\n", res);	
	}	
	return 0;
}
