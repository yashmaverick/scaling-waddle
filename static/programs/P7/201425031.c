#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int comparator (const void * a, const void * b);
int main()
{
    int T, n,p, y,z,arr[1000001],i,j,k,hash[1000001];
    scanf("%d",&T);
    while(T--)
    {
        long long int sum=0,tempsum;
        
        scanf("%d",&n);
        for(i=0;i<n;i++)
            hash[i]=0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr, n, sizeof(int), comparator);
   //     hash[0]=0;
        k=arr[0];
        p=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==k)
                hash[p]++;
            else
            {
                
                hash[++p]++;
                k=arr[i];
            }
        }
        for(i=0;i<=p;i++)
        {
            if(hash[i]>=2)
            {
                tempsum=((long long)(hash[i])*(long long )(hash[i]-1))/2;
                sum=sum+tempsum;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
int comparator (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

