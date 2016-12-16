#include<stdio.h>

int main()
{
	int t,i;
	scanf("%d",&t);


	for(i=0;i<t;i++)
	{
		long long int n;
		scanf("%lld",&n);

		if(n==0) printf("0\n");
		else if(n==1) printf("0\n");
		else
		{	

		long long int a[n];

		long long int p;
		for(p=0;p<n;p++)
		{
			scanf("%lld",&a[p]);
		}
	



		long long int min=a[0];
		long long int pro=0;

		for(p=1;p<n;p++)
		{
			if(a[p]<min) min=a[p];
			else if((a[p]-min)>pro) pro=a[p]-min;
		}
		printf("%lld\n",pro);
		}
	}
	return 0;	
}