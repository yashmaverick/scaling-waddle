#include<stdio.h>
#include<stdlib.h>
 
typedef struct l 
{
        int *a;
        long long int sum;
        int m;
}node;
node b[1000];
        
        int function(const void *a, const void *b)
{
        node *A,*B;
        A=(node *)a; 
        B=(node *)b;
      
//        if(A->sum > B->sum)
  //              return 1;
        return (A->sum - B->sum);
    //            return 0;
      //  else
        //        return -1;
}
int main()
{
        int n,mod;
        int i,j,k,z;
        scanf("%d %d",&n,&mod);
        //node *b;
        //b=malloc(sizeof(node)*n);
        for(i=0;i<n;i++)
        {
                b[i].sum=0;
                scanf("%d",&b[i].m);
                b[i].a = malloc(sizeof(long long int)*b[i].m);
                for(j=0;j<b[i].m;j++)
                {
                        scanf("%d",&b[i].a[j]);
                        b[i].sum = (b[i].sum + b[i].a[j])%mod;
                      //  b[i].sum=b[i].sum%mod;
                }
        }
        qsort(b,n,sizeof(node),function);
        for(k=0;k<n;k++)
        {
               printf("%lld\n",b[k].sum);
               for(z=0;z<b[k].m;z++)
               {
                      printf("%d\n",b[k].a[z]);
               }
               printf("\n");
        }
     return 0;
}
