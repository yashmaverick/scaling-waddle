#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    long long int n,sum,i,m,j,k,p,q,arr[500000];
    while(1)
    {
        scanf("%lld",&n);

        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        p=0;
        sum=0;
        for(i=0;i<n-1;i++)
        {
            
            
            for(j=i+2;j<n;j++)
            {
                
                for(m=i+1;m<j;m++)
                {
                    if(arr[i]<arr[m] || arr[j]<arr[m])
                    {
                        p++;

                            break;
                    }
                   
                }
               
                
            }
//            printf("%lld",p);
      /*      for(j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                    q++;
            }
            sum=sum+p*(n-1-i);
            sum=sum+q*(i-p);*/
        }

        printf("%lld\n",p);
    }
    return 0;
} 
