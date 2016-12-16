#include<stdio.h>
#include<stdlib.h>


struct array{
   long long  int weight;
   long long  int spos;
   long long  int epos;
};

int main()
{
    long long int i,j,k; 
    long long int MOD;
    long long int N,M;
    scanf("%lld %lld",&N,&MOD);
    long long int *a[1010];
   // a=(int**)(malloc(N*sizeof(int)));
    struct array element[N];
    for(i=0;i<N;i++)
    { 
        scanf("%lld",&M);
        long long int values=0;
       // int a[i];
        a[i]=(long long int *)malloc(M*sizeof(long long int));
        for(j=0;j<M;j++)
        {
            scanf("%lld",&a[i][j]);
                values=(values%MOD+(a[i][j]%MOD))%MOD;
        }
        long long int fvalue=values;
        element[i].weight=fvalue;
        element[i].spos=i;
        element[i].epos=j;

    }

    for(i=1;i<N;i++)
    {
        for(j=i;j>0;j--)
        {
            if(element[j].weight < element[j-1].weight)
            {
                struct array temp;
                temp=element[j];
                element[j]=element[j-1];
                element[j-1]=temp;
            }
        }
    }
   
    for(i=0;i<N;i++)
    {
       printf("%lld\n",element[i].weight);
       long long int start=element[i].spos;
       long long int end=element[i].epos;
       for(j=0;j<end;j++)
       {
         printf("%d\n",a[start][j]);
       }
       printf("\n"); 
    }
       

return 0;
}
