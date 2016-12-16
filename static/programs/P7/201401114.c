#include<stdio.h>
#include<stdlib.h>
long long int combination(int x)
{
	return ((long long int)x*(x-1))/2;
}
int main()
{
        int T, N,i;
        int a[1000010],min,max;

	long long int ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(i=0; i<N; i++)
		     scanf("%d", &a[i]);
		max=-10000000;
		min=10000000;
		for(i=0; i<N; i++)
	         {
		 	 if(a[i]<min)
				min=a[i];
			 if(a[i]>max)
				 max=a[i];
		 }

		for(i=0; i<N; i++)
			a[i]=a[i]-min;
		
		int b[1000010]={0};
		ans=0;
		int val;
		for(i=0; i<N;i++)
		{
			val=a[i];
			b[val]++;
		}
		for(i=0; i<=1000001; i++)
			if(b[i]>1)
				ans=ans+combination(b[i]);
		printf("%lld\n", ans);
	}
	return 0;
}



