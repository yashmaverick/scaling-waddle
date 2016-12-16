
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int A[1000001]={0};
int B[1000001];
int main()
{
    int t,n,i;
    long long dupl,min,max;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        if(n!=0)
        {
        scanf("%d",&B[0]);
        max=min=B[0];
        }
        for(i=1;i<n;i++)
        {
            scanf("%d",&B[i]);
            if(B[i]<min)
                min=B[i];
            if(B[i]>max)
                max=B[i];
        }
      //  printf("min is %d and max is%d\n",min,max);
        dupl=0;
        
            for(i=0;i<n;i++)
            {   
                A[B[i]-min]++;
            }

        for(i=0;i<max-min+1;i++)
        {   
            dupl=dupl+((long long)A[i]*(long long)(A[i]-1))/2;
            A[i]=0;
           // printf("dupl:%d\n",dupl);
        }
        printf("%lld\n",dupl);

    }


    return 0;
}
