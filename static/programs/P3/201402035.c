#include<stdio.h>
int main()
{
	int t,n,i,k,max1,max,a[100000];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		
		max=0;
		max1=a[n-1];

		for(i=n-1;i>=0;i--)
		{
			k=	max1-a[i];
			if(k>max)
				max=k;

			if(a[i]>max1) 
			{
				max1=a[i];
			}
//			printf("%d %d\n",k,max);
		}

		printf("%d\n",max);
	}
	return 0;
}

