#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n],i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int min=a[0];
		int max=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<min)
				min=a[i];
			if(a[i]-min>max)
				max=a[i]-min;
		}
		printf("%d\n",max);
	}
	return 0;
}

