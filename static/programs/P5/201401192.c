#include<stdio.h>
#include<stdlib.h>
int asdh(const void *first, const void *second)
{
	return (*(int*)first-*(int*)second);
}
int main()
{
	int t, n, K, enttValue[100001], i, j, k, success;
	char pointlessString[100001];
	scanf("%d", &t);
	while(t--)
	{
		success = 0;
		scanf("%d %d", &n, &K);
		for(i = 0; i < n; i++)
		{
			scanf("%s %d", pointlessString, &enttValue[i]);
		}
		qsort(enttValue, n, sizeof(int), asdh);
		for(i = 0; i < n; i++)
		{
			if(enttValue[i] < K)
			{
				j = i+1;
				k = n-1;
				while(j < k)
				{
					if(enttValue[i] + enttValue[j] + enttValue[k] > K)
					{
						k--;
					}
					else if(enttValue[i] + enttValue[j] + enttValue[k] < K)
					{
						j++;
					}
					else
					{
						printf("YES\n");
						success = 1;
						break;
					}
				}
				if(success)
				{
					break;
				}
			}
		}
		if(!success)
		{
			printf("NO\n");
		}

	}
	return 0;
}
