#include<stdio.h>
#include<stdlib.h>
#define gi(n) scanf("%lld",&n); 
#define npi(n) printf("%lld\n",n); 
#define tgi(n,m) scanf("%lld %lld",&n,&m);
#define REP(i,n,k) for(i=k;i<n;i++) 
#define ml(n,x) malloc(n*x) 
#define coutendl printf("\n"); 
int main()
{
	long long int r,n,m,i,j,mod;tgi(n,mod)long long int sum=0;
	long long int *start=(long long int *)ml(n,sizeof(long long int));
	long long int *end=(long long int *)ml(n,sizeof(long long int));
	REP(i,n,0)start[i]=i;
	long long int **a=(long long int **)ml(n,(sizeof(long long int*)));
	REP(i,n,0)
	{
		gi(m);
		a[i]=(long long int *)ml((m+1),sizeof(long long int));
		end[i]=m;
		REP(j,m,0)
		{
			gi(a[i][j+1]);
			sum=((sum)%mod+(a[i][j+1])%mod)%mod;
		}
		a[i][0]=sum;
		sum=0;
	}
	REP(i,n-1,0)
	{
		REP(j,n,i+1)
		{
			if(a[start[i]][0]>a[start[j]][0])
			{
				start[i]=start[i]^start[j];
				start[j]=start[i]^start[j];
				start[i]=start[i]^start[j];
			}
		}
	}
	REP(i,n,0)
	{
		npi(a[start[i]][0])
		for(j=1;j<=end[start[i]];j++)
		{
			npi(a[start[i]][j])
		}
		coutendl;
	}
	return 0;
}
