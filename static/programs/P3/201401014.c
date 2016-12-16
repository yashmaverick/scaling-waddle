#include<stdio.h>
int main()
{
	long long int t,A[100001],n,i,j,min,max,diff;
	scanf("%lld",&t);
//	max=-1;
	while(t--)
	{
//		scanf("%lld",&A[0]);
//		min=A[0];
		max=0;
		scanf("%lld",&n);
		scanf("%lld",&A[0]);
		min=A[0];;
		for(j=1;j<n;j++)
		{
			scanf("%lld",&A[j]);
		//	for(j=0;j<i;j++)
		//	{
			//	if(max<(A[i]-A[j]))
		//			max=A[i]-A[j];
		//	}
			if(min<A[j])
			{
				if((A[j]-min)>max)
					max=A[j]-min;
			}
			if(min>A[j])
				min=A[j];
		}
	//	if(max<0)
	//		printf("0\n");
	//	else
			printf("%lld\n",max);
	}
	return 0;
}

