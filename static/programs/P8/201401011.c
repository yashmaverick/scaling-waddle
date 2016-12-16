#include<stdio.h>
#define mod 1000000007
int main()
{
	long long int T;

	scanf("%lld",&T);
	while(T--)
	{
		long long int up,d,m,n,a[70],X,Y,Z,xd,i,j,k,sol,size_a;
		scanf("%lld%lld%lld%lld",&up,&d,&m,&n);
		long long int A[n];
		/* for repeated square */
		i=0;
		while(d != 0)
		{
			a[i] = d & 1;
			d >>= 1;
			i++;
		}
		size_a=i;
		/* A[i] = i^d % N , note : (i^d) % N = (i%n) ^ d */
		A[0] = (n == 0) ? 1 : 0 ;
		A[1] = 1;
		for(j=2;j<n;j++)
		{
			xd=1,i=size_a;
			for(i-=1;i>=0;i--)
			{
				xd = ( (xd%n) * (xd%n) ) % n;		
				if(a[i]==1)
					xd =( (xd%n) * (j%n)) % n;
			}
			A[j] = xd ;
		}
	/*	for(i=0;i<n;i++)
		printf("%lld  ",A[i]);
		printf("\n");	
	*/
		/* 0 se n-1 tak jitne solution hain , n se 2n-1 tak bhi utne 
		   honge ----- 1
		 *har n interval main utne honge. */
		sol = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if (((A[i] + A[j]+ A[k]) % n) == m )
					{	
						X = ( (i <= up % n)) ? ((up)/n) + 1 : (up)/n;
						Y = ( (j <= up % n)) ? ((up)/n) + 1 : (up)/n;
						Z = (  (k <= up % n)) ? ((up)/n) + 1 : (up)/n;
						//printf("%lld %lld %lld\n",A[i],A[j],A[k]);
						sol = (sol + ((X * Y)%mod * Z)%mod)%mod;
					}
				}
			}
		}
		printf("%lld\n",sol);
	}
	return 0;
}
