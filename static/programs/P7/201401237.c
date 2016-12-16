#include<stdio.h>
#include <inttypes.h>
typedef long long int LONGLONGINT;
int main()
{
    LONGLONGINT  t;
    scanf("%lld",&t);
    while(t--)
    {
        LONGLONGINT i,n,count=0;
        scanf("%lld",&n);
        LONGLONGINT  array[n];
        LONGLONGINT  min,max;
        //scan array find min and max
        //printf("Read=%ld\n",n);
        // Read Numbers and get Min and Max
        for(i=0;i<n;i++)
        {
            // Read
            scanf("%lld",&array[i]);
            if (i==0)
            {
                min=array[i];
                max=array[i];
            }
            else
            {
                if(array[i]<min)
                    min=array[i];
                if(array[i]>max)
                    max=array[i];
            }
            
        }
        // Print Number
        //for(i=0;i<n;i++)
        //    printf("%ld ",array[i])
        //printf("\nMin: %ld Max: %ld\n",min,max)
        // Find Count
        LONGLONGINT countarray[(max-min+1)];

        //Initialize count array
        for(i=0;i<=(max-min);i++)
            countarray[i]=0;

        //count array values
        for(i=0;i<n;i++)
            countarray[array[i]-min]++;
        //Print Value
        //for(i=0;i<=(max-min);i++)
        //    printf("%ld ",countarray[i]);
        //printf("\n");

        //find pairs
        for(i=0;i<=(max-min);i++)
        {
            if(countarray[i]==2)
                count++;
            else if(countarray[i]>2)
                count+=(countarray[i]*(countarray[i]-1))/2;
        }
        printf("%lld\n",count);
    }
    return 0;
}
