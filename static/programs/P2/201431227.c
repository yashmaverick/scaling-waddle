#include<stdio.h>
int main()
{
    int i,j,k,t,l,A[100005],B[100005],C[100005],p,q,r,D[100005];
    long long int sum,total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d",&A[i]);
        scanf("%d",&q);
        for(i=0;i<q;i++)
            scanf("%d",&B[i]);
        scanf("%d",&r);
        for(i=0;i<r;i++)
            scanf("%d",&C[i]);
        i=0,j=0;
        while(j<q)
        {
            if(B[j]>=A[i] && j>=i && i<p)
            i++;
            D[j]=i;
            j++;
        }
        i=0,j=0,total=0,sum=0;
        while(j<r)
        {
            if(C[j]>=B[i] && j>=i && i<q)
            {sum=sum+D[i];
                i++;
            }
            total=total+sum;
            j++;
        }
        printf("%lld\n",total);
    }
    return 0;
}




        
