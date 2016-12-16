#include<stdio.h>
int main()
{
	int N,M[1001],i,j,k,z,y=2,x;
	long long int MOD,m[1001],n;
	scanf("%d%d",&N,&MOD);
	//n=(N*1000000)+1;
	long long int a[1001000],s[1001],smin,l;
	m[0]=0;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&M[i]);
		/*long long int d=(long long int *)malloc(sizeof(long long int)*M[i]);*/
		m[i]=m[i-1]+M[i];
		s[i]=0;
		for(x=m[i-1]+1;x<=m[i];x++)
		{
			scanf("%lld",&a[x]);
			s[i]=(s[i]+a[x])%MOD;
			//y=x+1;
		}
	}
	//smin=10000000000;
	for(i=1;i<=N;i++)
	{
		smin=10000000000;
		for(k=1;k<=N;k++)
		{
			if(s[k]<smin)
			{
				smin=s[k];
				z=k;
			}
		}
		printf("%lld\n",smin);
		for(l=m[z-1]+1;l<=m[z];l++)
		{
			printf("%lld\n",a[l]);
		}
		printf("\n");
		s[z]=10000000000;
	}
	return 0;
}
