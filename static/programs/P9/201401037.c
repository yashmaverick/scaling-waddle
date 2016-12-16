#include<stdio.h>
#include<stdlib.h>

typedef struct arrp{
     int sum;
     int *p;
}ar;

int comp(const void *a,const void *b)
{
     ar *p=(ar*)a;
     ar *q=(ar*)b;

     if(p->sum > q->sum)
         return 1;
     else
          return -1;
}
int main (){
    int i,j,w,n,m,mod,*b,sum,*p;
     ar *a,temp;
     scanf("%d%d",&n,&mod);
     a=(ar*)malloc((n+1)*sizeof(ar));

     for(i=0;i<n;i++)
     {
          scanf("%d",&m);

          b=(int*)malloc((m+1)*sizeof(int));
          sum=0;
          for(j=1;j<=m;j++)
          {
           //    sum=0;
               scanf("%d",&b[j]);
               sum=(sum+b[j])%mod;
          }
          sum=sum%mod;
          b[0]=m;
          a[i].sum=sum;
          a[i].p=b;
        //  free(b);
     }

    qsort(a,n,sizeof(ar),comp);

     for(i=0;i<n;i++)
     {   printf("%d\n",(a[i].sum));
          for(j=1;j<=(*(a[i].p));j++)
               printf("%d\n",*((a[i].p)+j));
          printf("\n");
     }

     return 0;
}
