/*
 Algorithm:
	Given problem: To find solutions of a1^d+a2^d+a3^d = m (mod N)
	Solution: If we apply modulo N to both sides than basically we have to check if LHS%N=m for which values of a1,a2,a3.
		  Now since d is a very very large value and if we consider that it takes the CPU around 1 second to compute a value raised to the 			  power of 10^9, we instead calclulate the values raised to the power of N. 
		  Now on LHS%N = (a1^d)%n + (a2^d)%n + (a3^d)%n => (a1%n)^d + (a2%n)^d + (a3%n)^d.
		  In the above we consider that a1%n to be x, a2%n to be y and a3%n to be z. Now we check if ((x+y+z)%n==m).
		  If true, then we now have to count the number of values of each of a1, a2 and a3 for which the above condition hold true and so 			  that we thus get our result by adding the count of each pair of(x,y,z) to result, thus, giving us the total number of solutions of 			  the given equation.

NOTE: WE ARE USING N AS THE POWER IN THE ABOVE. SO BASICALLY WE CAN SAY THAT N DIVIDES THE RANGE OF [0,UPPER] INTO EQUAL PARTS (of size N) IF N DIVIDES UPPER.
AND SO COUNTING THE NUMBER OF ABOVE INTERVALS .I.E., (UPPER/N) WILL GIVE US THE COUNT OF THE POSSIBLE VALUES OF a1,a2,a3 FOR WHICH THE EQUATION HOLDS.
HOWEVER IF N DOESN'T DIVIDE UPPER, WE WILL HAVE A LAST INTERVAL OF RANGE(LAST INTERVAL)<N. 
SO IN THIS CASE WE ALREADY KNOW THAT COUNT OF THE POSSIBLE VALUES OF A1,A2,A3 WILL BE GREATER THAN (UPPER/N). NOW ONE WILL REALISE ( upon racking one's brain for 1.5 agonising day(s) ) THAT THERE CAN OBVIOUSLY BE ONLY ONE COUNT OF THE POSSIBLE VALUE(S) OF a1,a2,a3 FOR WHICH THE EQUATION HOLDS TRUE IN THE LAST INTERVAL. AND SO IN THIS CASE WE WILL CONSIDER (1+(UPPER/N)).
*/
#include<stdio.h>
typedef long long int LL;
#define MOD 1000000007

LL n;

LL power(LL a,LL b)//, LL m)//Lalit Kundu DS Lab
{
    if(b==0)
        return  1;
    LL x=power(a,b/2);//m); 	
    LL y=(x*x)%n;//%m;
    if(b%2)
        return (a*y)%n;//%m;
    return y;
}


int main()
{
    LL a,b,c,upper,d,m,count,result,i,j,k,t;

    scanf("%lld",&t);

    while(t-->0)
    {
        scanf("%lld %lld %lld %lld",&upper,&d,&m,&n);

        result=0;
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                for(k=0;k<n;++k)
                {
                    a=power(i,d);//,n);
                    b=power(j,d);//,n);
                    c=power(k,d);//,n);
                    if((a+b+c)%n==m)
                    {
                        count=1;
                        if(i<=(upper%n))
                            count=(count*(1+(upper/n)))%MOD;
                        else
                            count=(count*(upper/n))%MOD;
                        if(j<=(upper%n))
                            count=(count*(1+(upper/n)))%MOD;
                        else
                            count=(count*(upper/n))%MOD;
                        if(k<=(upper%n))		
                            count=(count*(1+(upper/n)))%MOD;
                        else
                            count=(count*(upper/n))%MOD;
                        result=(result+count)%MOD;
                    }
                }
            }
        }
        printf("%lld\n",result%MOD);
    }
    return 0;
}
