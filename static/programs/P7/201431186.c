#include<stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{  long long int n,j,a,min,max,sum;
		min=10000000;max=-10000000;
		scanf("%lld",&n);
		long long int A[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&A[j]);
			if((A[j])<=min)
				min=A[j];
			if((A[j])>=max)
				max=A[j];
	
		}
		j=max-min;
		//printf("%lld %lld\n",min,max);
	       long long int com[j+1];
       for(a=0;a<=j;a++)
           com[a]=0;

		for(a=0;a<n;a++)
		  com[A[a]-min]=com[A[a]-min]+1;
   sum=0;
	for(a=0;a<=j;a++)
	{ if(com[a]!=1&&com[a]!=0)
		sum=sum+(com[a]*(com[a]-1))/2;
	}
	printf("%lld\n",sum);
	}
	return 0;
}
	 


          
