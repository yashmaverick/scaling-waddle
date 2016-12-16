#include<stdio.h>
#include<stdlib.h>
typedef struct bag{
    long long int m;
    long long int *weight;
    long long int total;
}bag;

int main()
{
    long long int n,m,mod;
    long long int i,j;
    bag b[1001];
    bag temp;
    scanf("%lld%lld",&n,&mod);
    
    for(i=0;i<n;i++)
    {
        b[i].total=0;
    }
    
    for(i=0;i<n;i++)
    {

        scanf("%lld",&b[i].m);
        b[i].weight=(long long int*)malloc(sizeof(long long int)*b[i].m);
        for(j=0;j<b[i].m;j++)
        {
            scanf("%lld",&b[i].weight[j]);
            b[i].total=(b[i].total+b[i].weight[j])%mod;
        }
        b[i].total%=mod;
        
    }
    
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
        {
            if(b[j].total>b[j+1].total)
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }

    for(i=0;i<n;i++)
    {
        printf("%lld\n",b[i].total);
        for(j=0;j<b[i].m;j++)
            printf("%lld\n",b[i].weight[j]);
        printf("\n");
    }
    return 0;
    }
