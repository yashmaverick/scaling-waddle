#include<stdio.h>

int main()
{
	int T,n,i,cp,sp,profit,a[100000];

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
			scanf("%d",&a[i]);
			
		cp = sp = a[0];
		profit = 0;

		for(i=1;i<n-1;i++)
		{
			if( a[i]<=a[i+1] && a[i]<=a[i-1] && a[i]<cp )
				cp = a[i];
			else if( a[i]>=a[i-1] && a[i]>=a[i+1] )
			{	sp = a[i];

				if ( sp - cp > profit )
					profit = sp - cp;
			}
		}

		if(a[i] > a[i-1])
		{
			sp = a[i];

			if( sp - cp > profit )
				profit = sp - cp;		
		}
		printf("%d\n",profit);
	}
	return 0;
}
