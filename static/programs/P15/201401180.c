#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int k;
		int a[10010];
		int i,j;
		int min = 10e6;
		int min1;
		int f = 0;
		scanf("%d%d",&n,&k);
		for (i = 1; i <= n; i++)
			scanf("%d",&a[i]);
		for (i = 1; i <= n-k+1; i++)
		{
			if (f == 0)
			{
				for (j = i; j <= (i+k-1); j++)
				{
					if (a[j] < min)
					{
						min = a[j];
						min1 = j;
					}
				}
			}
			else 
			{
				if (min > a[i+k-1])
					min = a[i+k-1];
			}
			if (i == n-k+1)
				printf("%d",min);
			else
				printf("%d ",min);
			if (min1 == i)
			{
				f = 0;
				min = 10e6;
			}
			else f = 1;
		}
		printf("\n");
	}
	return 0;
}
