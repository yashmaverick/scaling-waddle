#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int factorial(long long int n)
{
   long long int c;
   long long int result = 1;
 
   for( c = 1 ; c <= n ; c++ )
      result = result*c;
 
   return ( result );
}

long long int find_ncr(long long int n, long long int r)
{
   long long int result;
 
   result = factorial(n)/(factorial(r)*factorial(n-r));
 
   return result;
}


int main()
{
    long long int t, i, j;
    char s[100000];
    
    scanf("%lld", &t);
    
    while (t--)
    {
        scanf("%s", s);
        long long int count = 1;
        long long int touch = 0;
        
        for (i = 0; i < strlen(s); i++)
        {
            for (j = i; j < strlen(s); j++)
             {  
                if (s[j] == 'J')
                {
                    touch += -500000;
                }
                
                else if (s[j] == 'M')
                {
                    touch += 500001;
                }
                
                else if (s[j] == 'R')
                {
                    touch += -1;
                }
                
                if (touch == 0)
                {
                    count++;
                }
            }
        }
        
        printf("%lld\n", find_ncr(count, 2));
    }
    
    return 0;
}
    
    
        
