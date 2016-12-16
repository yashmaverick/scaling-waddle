#include<stdio.h>
#include<stdlib.h>
#define g(x) scanf("%d",&x)
#define f(a,b) scanf("%d%d",&a,&b)
typedef struct info
{int member;
    int *weight;
   // int member;
    int total;
}info;
int compare (const void * a, const void * b)
{

    info *infoA,*infoB;
    infoA = (info *)a;
    infoB = (info *)b;

          return ( infoA->total - infoB->total );
}
int main()
{
    int i,j,a,b,t,mod,sum;
    info *q;
    f(t,mod);
    q=(info *)malloc(sizeof(info)*t);
    for(i=0;i<t;i++)
    {
        sum=0;
        g(q[i].member);
        q[i].weight=(int *)malloc(sizeof(int)*q[i].member);
        for(j=0;j<q[i].member;j++)
        {
            g(q[i].weight[j]);
            sum=(sum+q[i].weight[j])%mod;
        }
        q[i].total=sum;
    }
    qsort(q,t,sizeof(info),compare);
    for(i=0;i<t;i++)
    {printf("%d\n",q[i].total);
        for(j=0;j<q[i].member;j++)
            printf("%d\n",q[i].weight[j]);
        printf("\n");
    }
free(q);
return 0;
}

    
    


