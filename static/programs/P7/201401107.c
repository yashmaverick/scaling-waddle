#include<stdio.h>
#define int long long int
	int a[1000002],n,t,num,i,k,l,size,j;
int main()
{
	int sum=0;
	int b[1000002]={0};
	int m;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		for(m=0;m<1000002;m++)
		{
			b[m]=0;
		}
		 int min=400000000;

		scanf("%lld",&size);
		
		for(j=0;j<size;j++)
		{
			scanf("%lld", &a[j]);
			if(a[j]<min)
				min=a[j];
		}

		for(k=0;k<size;k++)
		{
			b[a[k]-min]++;
		//	int z=b[a[k]-min];
		//	printf("%lld ",z);
		}
	               sum=0;

		       


		for(l=0;l<1000002;l++)
		{
			sum+=b[l]*(b[l]-1)/2;
		//	printf("%ll);
		}

		printf("%lld\n",sum);
	
	}

	return 0;
}
