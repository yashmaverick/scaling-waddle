#include<stdio.h>
int main()
{
	
        long long int A[100001],B[100001],C[100001],n,a,i,max;
	scanf("%lld",&n);
	while(n--)
	{       max=0;
		scanf("%lld",&a);
		for(i=0;i<a;i++)
			scanf("%lld",&A[i]);
		B[0]=A[0];
		C[a-1]=A[a-1];
	        for(i=1;i<a;i++)
		{        
			if(A[i]<=B[i-1])
				B[i]=A[i];
			else
				B[i]=B[i-1];
		}
	        for(i=a-1;i>0;i--){
			if(A[i-1]>=C[i])
				C[i-1]=A[i-1];
			else
				C[i-1]=C[i];
                }
//		for(i=0;i<a;i++)
//			printf("%lld   %lld\n",B[i],C[i]);
		for(i=0;i<a;i++)
		{
			if((C[i]-B[i])>=max)
				max=C[i]-B[i];
		}
		printf("%lld\n",max);
	}
return 0;
}
