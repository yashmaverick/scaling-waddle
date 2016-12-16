#include<stdio.h>
#include<malloc.h>
int compare(const void *p,const void *q)
{
    return ((*(long long int* )p-*(long long int* )q));
}
int main()
{
    long long int n,i,j;
    long long int mod,m,w;
    scanf("%lld%lld",&n,&mod);
    long long int **a=malloc(n*sizeof(long long int *));
    long long int temp[n];
    long long int s=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&m);
        a[i]=malloc((m+2)*sizeof(long long int));
        a[i][0]=m;
        for(j=2;j<=(m+1);j++)
        {
            scanf("%lld",&w);
            s=(s+w)%mod;
            a[i][j]=w;
        }
  //      printf("s=%lld ",s);
        a[i][1]=s;
        temp[i]=s;
        s=0;
    }
 //   for(i=0;i<n;i++)
 //       printf("%lld ",a[i][0]);
 //   printf("\n");
    qsort(temp,n,sizeof(long long int),compare);
 //   for(i=0;i<n;i++)
 //       printf("%lld ",temp[i]);
 //   printf("\n");
    long long int k,l;
    long long int size;
    for(j=0;j<n;j++)
    {
        for(l=0;l<n;l++)
        {
            if(temp[j]==a[l][1] && a[l][1]!=-1)
            {
                size=a[l][0];
//                printf("size=%lld ",size);
                printf("%lld\n",temp[j]);
                for(k=2;k<size+2;k++)
                    printf("%lld\n",a[l][k]);
                printf("\n");
                a[l][1]=-1;
            }
        }
    }




    //    for(i=0;i<n;i++)
    //        printf("%lld ",temp[i]);
    //    printf("\n");
    return 0;
}

