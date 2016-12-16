#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct c
{
    int data,index;
    long long int sum;
}node;

int cmpfunc (const void *a, const void *b)
{
    long long int p=((node*)a)->sum;
    long long int q=((node*)b)->sum;
    int y=((node*)a)->sum;
    int z=((node*)b)->sum;
    if(p==q)
    {
        if(y<z)
            return 1;
        else
            return -1;
    }
    else if(p<q)
        return -1;
    else
        return 1;
}

int main()
{
    int n,i;
    int mod;
    scanf("%d %d",&n,&mod);
    node a[n];
    //*a=malloc(sizeof(node)*n);
    long long int *weight[n];
    //node *a=(node*)malloc(n*sizeof(node));
    for(i=0;i<n;i++)
    {
        //a[i]=NULL;
        int m;
        scanf("%d",&m);
        weight[i]=(long long int *)malloc(m*sizeof(long long int));
        int j=0;
        a[i].sum=0;
        a[i].data=i;
        a[i].index=m;
        while(m--)
        {
            long long int k;
            scanf("%lld",&k);
            weight[i][j]=k;
            a[i].sum=(a[i].sum+(weight[i][j])%mod)%mod;
            j++;
        }
       // printf("%lld\n",a[i].sum);
    }
    qsort(a,n,sizeof(node),cmpfunc);
    for(i=0;i<n;i++)
    {
        printf("%lld\n",a[i].sum);
        int j,r;
        r=a[i].data;
        for(j=0;j<a[i].index;j++)
        {
            printf("%lld\n",weight[r][j]);
        }
        printf("\n");
    }
    return 0;
}


