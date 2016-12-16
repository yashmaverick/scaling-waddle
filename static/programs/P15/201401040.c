#include<stdio.h>
int main()
{
    int test,n,k,A[10010];
    int i,j;
    int a;
        scanf("%d",&test);
    while(test--)
    {
        int minimum,index;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
//        printf("%d %d %d\n",n,k,n-k);

        for(i=0,j=i+k-1;i<(n-k+1);i++,j++)
        {
  //          printf("%d\n",i);
            if(i==0)
            {
                minimum=A[i];
                index=i;
                for(a=i+1;a<=j;a++)
                {
                    if(A[a]<=minimum)
                    {
                        minimum=A[a];
                        index=a;
                    }
                }
            }
            else
            {

                if(A[j]<=minimum && index>=i)
                {
                    minimum=A[j];
                    index=j;
                }
                else if(index<i)
                {

                    minimum=A[i];
                    index=i;
                    for(a=i+1;a<=j;a++)
                    {
                        if(A[a]<=minimum)
                        {
                            minimum=A[a];
                            index=a;
                        }
                    }
                }
            }
            if(i==n-k)
                printf("%d\n",minimum);
            else
                printf("%d ",minimum);
        }
    }
    return 0;
}
