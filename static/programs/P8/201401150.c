#include <stdio.h>
#define s(n) scanf("%d",&n)
#define ll long long
#define MOD 1000000007

ll fmm(int base,int exp,int mod)
{
	ll ans=1,newbase=base;
	while(exp>0)
	{
		if(exp&1==1)
			ans=(ans*newbase)%mod;
		newbase=(newbase*newbase)%mod;
		exp/=2;
	}

	return ans;
}

void initA(ll A[],int N,int d)
{
	int i;
	for(i=0;i<N;i++)
		A[i]=fmm(i,d,N);
}

ll Cardinal(int a,int U,int N)
{
	int f=0;
	if(a<=U%N)
		f=1;
	return (U/N)+f;
}

void printArr(ll A[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%lld\n",A[i]);
}

int main()
{
	int t,i,N,k,U,j,l,d,m,A1,A2,A3;ll A[40],sum;
	s(t);
	for(i=0;i<t;i++)
	{	
		sum=0;
		s(U);s(d);s(m);s(N);
		initA(A,N,d);
		for(A1=0;A1<N;A1++)
			for(A2=0;A2<N;A2++)
				for(A3=0;A3<N;A3++)				
					if((A[A1]+A[A2]+A[A3])%N==m)
					{						
						
						sum=(sum+(Cardinal(A1,U,N)*Cardinal(A2,U,N)%MOD)*Cardinal(A3,U,N))%MOD;
					}		
	printf("%lld\n",sum);
	}
	return 0;
}
