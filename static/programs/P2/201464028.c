#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,*A,*B,k,*C,*D,n1,n2,n3,m,t,n;
    long long int total,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        A=(int *)malloc(sizeof(int)*n1);
        for(k=0;k<n1;k++)
            scanf("%d",&A[k]);
        scanf("%d",&n2);
        B=(int *)malloc(sizeof(int)*n2);
        for(k=0;k<n2;k++)
            scanf("%d",&B[k]);
        scanf("%d",&n3);
        C=(int *)malloc(sizeof(int)*n3);
        for(k=0;k<n3;k++)
            scanf("%d",&C[k]);
        D=(int *)malloc(sizeof(int)*n2);
        m=0;
        n=0;
        sum=0;
        while(m<n2)
        {
            if(B[m]>=A[n] && m>=n)
            {
                sum++;
                n++;
            }
            else
            {D[m]=sum;
                m++;}
}
m=0;
n=0;
total=0;
sum=0;

        while(m<n3)
        {
            if(C[m]>=B[n] && (m>=n && n<n2))
            {sum=sum+D[n];
                n++;
            }
            else
            {total=total+sum;
                m++;}}
        printf("%lld\n",total);
        free(A);
        free(B);
        free(C);
        free(D);

    }
return 0;
}


