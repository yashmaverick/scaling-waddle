
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%d",&n)
#define sc(n) scanf("%lld",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; Sc(t); while(t--)
#define mod 1000000007
typedef long long LL;

int main()
{	
	DRT(){
		LL i,j,k,n,m,d,u,ar[42];
		sc(u);sc(d);sc(m);sc(n);
		LL cnt=0;
		for(i=2;i<n;i++)
		{LL x=i%n,ij=1,d1=d;
			while(d1)
			{	if(d1%2)
					ij=(x*ij)%n;
				x=(x*x)%n;
				d1>>=1;
			}
			ar[i]=ij;
//			printf("%lld %lld\n",ar[i],i);
		//	d=d1;
		}
		ar[0]=0;
		ar[1]=1%n;
	//	printf("djgdgh%lld\n",ar[1]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if((ar[i]+ar[j]+ar[k])%n==m)
					{cnt=((((u-i+n)/n)*((u-j+n)/n)%mod)*((u-k+n)/n)%mod+cnt)%mod;
//					printf("%lld %lld %lld\n",i,j,k);	

					}
		printf("%lld\n",cnt);


	}
}


