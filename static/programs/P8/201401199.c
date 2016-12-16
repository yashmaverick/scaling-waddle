#include<stdio.h>
#define mod 1000000007

long long int power(long long int a,long long int b,long long int N)
{
    long long int temp;
    if(b==1)
    {   
	temp=a;
	return temp;
    }   
    else
    {   
	if(b%2==0)
	{
	    temp=(power(a,b/2,N)%N);
	    temp=(temp*temp)%N;
	    return temp;
	}
	else
	{
	    temp=(power(a,b/2,N)%N);
	    temp=(temp*temp)%N;
	    temp=((a%mod)*(temp))%N;
	    return temp;
	}
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	long long int U,d,N,m,q,r,l,ans=0,ai,aj,ak,a[50]={0},pwr[50];
	long long int i,j,k;
	scanf("%lld",&U);
	scanf("%lld",&d);
	scanf("%lld",&m);
	scanf("%lld",&N);

	q=U/N;
//	printf("q=%lld\n",q);
	r=U%N;
//	printf("r=%lld\n",r);

	for(i=0;i<=45;i++)
	{
	    pwr[i]=power(i,d,N);
	}

//	printf("pwr table\n");
/*	for(i=0;i<=N;i++)
	{
	    printf("%lld ",pwr[i]);
	}
	printf("\n");
*/
//	printf("a[i] in begin\n");
	for(i=0;i<N;i++)
	{
	    if(i<=r)
		a[i]=q+1;
	    else
		a[i]=q;
//	    printf("%lld ",a[i]);
	}
//	printf("\n");

	if(U<N)
	    l=U+1;
	else
	    l=N;

	for(i=0;i<l;i++)
	{
//	    printf("i=%lld\n",i);
	    ai=pwr[i];
	    for(j=0;j<l;j++)
	    {
		aj=pwr[j];
		for(k=0;k<l;k++)
		{
		    ak=pwr[k];
		    if(((ai+aj+ak)%N)==m)
		    {
//			printf("%lld %lld %lld\n",i,j,k);
//			printf("%lld+%lld+%lld",ai,aj,ak);
//			printf("==%lld\n",m);
			ans+=((((a[i]%mod)*(a[j]%mod))%mod)*(a[k]%mod))%mod;
//			printf("ans --> %lld\n",ans);
		    }
		}
	    }
	}
	ans%=mod;
//	printf("\n");
	printf("%lld\n",ans);
    }
    return 0;
}
