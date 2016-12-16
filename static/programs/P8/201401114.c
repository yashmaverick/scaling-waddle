#include<stdio.h>
typedef long long int ll;
 
long long int powermodulo(long long int a,long long int b,long long int m)
{
	        if(b==0)
		     return 1;
	        else 
		{
	          if(b%2==0)
                     return powermodulo((a*a)%m,b/2,m)%m;
                   else
		    return (a*powermodulo((a*a)%m,(b-1)/2,m))%m;
		 }

}
int main()
{
	int T;
	ll ul,d,m,n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld %lld %lld %lld" , &ul, &d, &m, &n);
		ll count=0, ans, count1, count2, count3, add1,add2,add3;
		ll MOD=n;
		ll i,j,k;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				for(k=0; k<n; k++)
				{
					if((powermodulo(i,d,n)+powermodulo(j,d,n)+powermodulo(k,d,n))%n==(m))
                                        {
						if(i<=ul%n)
						{
							add1=1;
						}
						else
						{
							add1=0;

						}
						if(j<=ul%n)
						{
							add2=1;
						}
						else
						{
							add2=0;
						}
						if(k<=ul%n)
						{
							add3=1;
						}
						else
						{
							add3=0;
						}
					 count1=(((ul)/n)+add1)%1000000007;
					 count2=(((ul)/n)+add2)%1000000007;
					 count3=(((ul)/n)+add3)%1000000007;
					//count=count+((((ul-i)%m/n)%m)*(((ul-j)%m/n)%m)*(((ul-k)%m/n)%m))%m;
					//count=(count+((count1*count2)%1000000007)*count3)%1000000007);
					count=(count+((count1*count2)%1000000007)*count3)%1000000007;
					}
				}
			}
		}
		//printf("%lld\n", count);
		ans=count;
		printf("%lld\n", count);
	}
	return 0;
}

	
