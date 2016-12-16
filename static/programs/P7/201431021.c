#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int n,i,a[1000000],j,t;
	long long int ans,k;
	scanf("%d",&t);
	for ( j= 0; j < t; ++j)
	{
		/* code */
		ans=0;
		scanf("%d",&n);
		for (i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}	
		qsort(a,n,sizeof(int),comp);
		k=1;
		for (i = 0; i < n-1; i++)
		{
			if(a[i]==a[i+1])
				k++;
			else
			{
				ans=ans+(k*(k-1))/2;
				k=1;
			}
		}
		ans=ans+(k*(k-1))/2;
		printf("%lld\n",ans);
	}
return 0;
}