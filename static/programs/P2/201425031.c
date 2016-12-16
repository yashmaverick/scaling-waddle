#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i,z,j,k,A[100000],B[100000],C[100000];
    int p,q,r,T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        z=0;
        scanf("%d",&p);
        for(m=0;m<p;m++)
            scanf("%d",&A[m]);
        scanf("%d",&q);
        for(n=0;n<q;n++)
            scanf("%d",&B[n]);
        scanf("%d",&r);
        for(m=0;m<r;m++)
            scanf("%d",&C[m]);
        for(i=0;i<p;i++)
        {
            for(j=i;j<q;j++)
            {
                if(A[i]<=B[j])
                {
                    for(k=j;k<r;k++)
                    {
                        if(B[j]<=C[k])
                            z++;
                    }
                }
            }
        }
        printf("%d\n",z);
    }
    return 0;
}





