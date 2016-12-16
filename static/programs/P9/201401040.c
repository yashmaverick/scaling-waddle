#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}


int main()
{
	int n,m,mod,weight=0,i,j,temp,mstore[1000000];
	din(n);
	int *ptemp=NULL;
	int **parray=(int **)calloc(n,sizeof(int *));
	int *weights=(int *)calloc(n,sizeof(int));
	din(mod);
	for(i=0;i<n;i++)
	{
		din(m);
		mstore[i]=m;
		parray[i]=(int *)calloc(m,sizeof(int));
		weight=0;
		for(j=0;j<m;j++)
		{
			din(parray[i][j]);
			weight=(weight+parray[i][j])%mod;
		}
		weights[i]=weight;
	}
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
		{
			if(weights[i]>weights[i+1])
			{
				temp=weights[i];
				weights[i]=weights[i+1];
				weights[i+1]=temp;
				ptemp=parray[i];
				parray[i]=parray[i+1];
				parray[i+1]=ptemp;
				temp=mstore[i];
				mstore[i]=mstore[i+1];
				mstore[i+1]=temp;
			}
		}
	for(i=0;i<n;i++)
	{
		dout(weights[i]);
		for(j=0;j<mstore[i];j++)
			dout(parray[i][j]);
		pu(10);
	}
	return 0;
}
