#include<stdio.h>
int main()
{
	int i,n,j,test,k,hy,d;
	long long int min,max,a[100000],akak=0;
	scanf("%d",&test);
	for(k=0;k<test;k++)
	{
		j=0,min=1000000000,max=0,akak=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		hy=0;
		while(j<n)
		{
			 if(a[j]<=min)
			 {	
                         min=a[j];
			 d=j;
                         }
			 else if(a[j]>=min)
			 {	
                         max=a[j];
			 hy=j;
                         }
                         if(max-min>=akak&&d<=hy) 
                         akak=max-min;
                         j++;
		
                }
			printf("%lld\n",akak);
	}
	return 0;
}
