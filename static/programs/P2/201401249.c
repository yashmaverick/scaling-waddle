#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
    int A[100010]={0},B[100010]={0},C[100010]={0},D[100010]={0},E[100010]={0};
    int P,Q,R,i,j,k,count=0,ans=0,count2=0,ans2=0,result1=0;
    scanf("%d",&P);
    for (i=0;i<P;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&Q);
    for (i=0;i<Q;i++)
    {
        scanf("%d",&B[i]);
    }
     scanf("%d",&R);
    for (i=0;i<R;i++)
    {
        scanf("%d",&C[i]);
    }


    i=0;
    j=0;
     count=0;
    while (i<P&&j<Q)
    {

        if (B[j]>=A[i] && j>=i)
        {
            count+=1;
            i++;
        }
        else
        {
            D[j]=count;
            j++;
        }
        //D[k]=count;
        //k++;
    }
    while(j<Q)
    {
        D[j]=count;
        j+=1;
    }
    ans=0;
    k=0;
    i=0;
    j=0;
    while (i<Q&&j<R)
    {

        if (B[i]<=C[j])
        {
            if (i<=j)
            {
                E[i]=R-j;
            }
            else {
                    E[i]=R-i;
                    if(E[i]<=0)
                        E[i]=0;
            }

            i++;
        }
        else
            j++;
       /* if (k<p)
        {
        ans=ans+D[k]*E[k];
        k++;
        }*/

    }

    i=0;
    ans=0;
    while(i<R)
    {
        ans=ans+D[i]*E[i];
       //  printf("%d %d\n",D[i],E[i]);
         i+=1;
    }
    printf("%d\n",ans);
}
return 0;
}
