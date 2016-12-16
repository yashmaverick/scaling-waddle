#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,i,j,k;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int max=a[1]-a[0];
		int min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]-min>max)
			{
				max=a[i]-min;
			}
			if(a[i]<min)
			{
				min=a[i];
			}

		}
		if(max>=0)
		{
		printf("%d\n",max);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
