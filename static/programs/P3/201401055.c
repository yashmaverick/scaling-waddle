#include<stdio.h>

int main()
{
	int t,n,j,k;
	long long int a[100000],maxp,minstock;
	scanf("%d",&t);
	//printf("\n");
	int i;
	//minstock=a[0];
	//maxp=a[1]-a[0];
	for(i=0;i<t;i++)   //test cases
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);  //stock values
		minstock=a[0];
		maxp=a[1]-a[0];
		for(k=0;k<n;k++)
		{
			if(a[k]-minstock>maxp)
				maxp=a[k]-minstock;
			if(a[k]<minstock)
				minstock=a[k];
		}


		printf("%lld\n",maxp);
	}
	return 0;
}


