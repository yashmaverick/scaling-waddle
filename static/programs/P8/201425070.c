// #Authored : Jaipal Singh Goud
// Part of : DS Assignment 1
// Date : 31/01/2015
// P8
// Editorial Link : http://discuss.codechef.com/questions/20315/cntsols-editorial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

# define MAX 1000000007L

unsigned long long powModulo(unsigned long long a,unsigned long long k,unsigned long long m)
{
    if( a == 0 && k == 0 )	
        return 1;
    unsigned long long pow = 1;
    
    while(k > 0)
    {
        if( k % 2 )
            pow = (pow*a)%m ; 
        
        a = (a*a)%m;
        k /= 2;
    }
    return pow;
}


int main()
{
    unsigned long long i,j,k,test,n,d,m,upper,min,x,y,z,tr;
    unsigned long long ans = 0,temp;
	unsigned long long int a[100], b[100];
    scanf("%llu",&test);
    while(test--)
    {
        ans = 0;
        scanf("%llu %llu %llu %llu",&upper,&d,&m,&n);
        
		for (i = 0; i < n; i++)
		{
			a[i] = (upper / n) + ((upper %n) >= i);
		}

		for (i = 0; i < n; i++)
		{
			b[i] = powModulo(i, d, n);
		}

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
					tr = 0;
					tr += b[i];
					tr += b[j];
					tr += b[k];

                    if( ( b[i] + b[j] + b[k] ) % n == m )
					{   
                        temp = a[i]*a[j];         // For x*y % MAX
                        if(temp >= MAX)	
                            temp %= MAX;
                        
                        temp *= a[k];          // For x*y*z % MAX
                        if(temp >= MAX)	
                            temp %= MAX;
                        
                        ans += temp;        // For making sure that the answer+temp is < MAX
                        if(ans >= MAX)
                            ans %= MAX;
                    }
                }
            }
        }
        printf("%llu\n",ans);
    }	
    return 0;
} 
