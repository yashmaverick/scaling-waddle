#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct abc
{
    long long int size;
   long long int sum;
   
    long long int *p;
};
typedef struct abc bag;

int main()
{
    bag A[1000];
    long long int i,j,k,l,M,N,sum,temp,temp3;
    long long int MOD;
    long long int *temp2;
    scanf("%lld %lld",&N,&MOD);
    long long int* b[N];
    for(j=0;j<N;j++)
    {

        sum=0;
        scanf("%lld",&M);
        b[j]=(long long int *)malloc(M*sizeof(long long int));
        for(i=0;i<M;i++)
        {
            scanf("%lld",(b[j]+i));

            sum=sum+(*(b[j]+i));
        }
        A[j].sum=sum%MOD;
        A[j].p=b[j];
        A[j].size=M;
    }
    for(i=0;i<N;i++)
        for(j=i+1;j<N;j++)
        {
            if(A[j].sum<A[i].sum)
            {
                temp=A[i].sum;
                temp2=A[i].p;
                temp3=A[i].size;
                A[i].sum=A[j].sum;
                A[i].p=A[j].p;
                A[i].size=A[j].size;
                A[j].sum=temp;
                A[j].p=temp2;
                A[j].size=temp3;
            }
        }
    for(i=0;i<N;i++)
    {
        printf("%lld\n",A[i].sum);
        for(j=0;j<A[i].size;j++)
        {
            printf("%lld\n",*(A[i].p+j));
        }
        printf("\n");

    }
    return 0;
}
