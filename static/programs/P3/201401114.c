#include<stdio.h>
void profit(int a[], int NA)
{
	int i, min=1000000000, diff=0;

	for(i=0; i<NA; i++)
	{
		if(a[i]<min)
			min=a[i];
	
		if(diff<(a[i]-min))
			diff=a[i]-min;
	}

	printf("%d\n", diff);
}
int main()
{
	int N, NA, z,i;
	int a[100001];
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &NA);
		for(i=0; i<NA; i++)
		{
			scanf("%d", &a[i]);
		}

		profit(a, NA);
	}

	return 0;
}

