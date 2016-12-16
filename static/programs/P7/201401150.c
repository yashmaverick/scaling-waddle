#include <stdio.h>
#define s(n) scanf("%d",&n)

long long nCr(int n,int r)
{
    long long ans=1;
    r=r>n-r?n-r:r;
    int j;
    for(j=1;j<=r;j++,n--)
    {
        if(n%j==0)        
            ans*=n/j;
        else if(ans%j==0)
            ans=ans/j*n;
        else        
            ans=(ans*n)/j;      
    }
    return ans;
}

int main()
{
	int t,i,n,j,A[1000000],B[1000000];long long int sum=0;
	s(t);
	for(i=0;i<t;i++)
	{
		s(n);int min=10000000,max=-10000000;
		sum=0;
		for(j=0;j<1000000;j++)
		{
			if(j<n)
			{
				s(A[j]);
				if(A[j]<min)
					min=A[j];
				if(A[j]>max)
					max=A[j];
			}
			B[j]=0;
		}
		for(j=0;j<n;j++)
			B[A[j]-min]++;
		for(j=0;j<(max-min)+1;j++)
			if(B[j]>1)
				sum+=nCr(B[j],2);

		printf("%lld\n",sum);
	}
	return 0;
}