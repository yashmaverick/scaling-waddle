#include<stdio.h>
#include<stdlib.h>
typedef struct bags
{
    int num;
    int *a;
   long long int sum;
}bags;
int func (const void * a, const void * b)
{
    bags *lhs = (bags *)a;
    bags *rhs = (bags *)b;
    return ((lhs->sum)-(rhs->sum));
}
int main()
{
    int n,mod,m,i,j,k,t;
    scanf("%d%d",&n,&mod);
    bags bag[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&bag[i].num);
        bag[i].a=(int *)malloc(bag[i].num*sizeof(int));
        bag[i].sum=0;
        for(j=0;j<bag[i].num;j++)
        {
            scanf("%d",&bag[i].a[j]);
            //printf("%d",bag[i].a[j]);
            bag[i].sum=((bag[i].sum)%mod+(bag[i].a[j])%mod)%mod;
        }
//          for(k=0;k<(bag[i].num);k++)
  //          printf("%d\n",bag[i].sum);
        //    printf("%d ",bag[i].a[k]);
        //    printf("\n");
    }
    //printf("\n");
        qsort(bag,n,sizeof(bags),func);
        for(i=0;i<n;i++)
        {
         printf("%lld\n",bag[i].sum);
         for(j=0;j<bag[i].num;j++)
             printf("%d\n",bag[i].a[j]);
             printf("\n");
        }

    return 0;
}
