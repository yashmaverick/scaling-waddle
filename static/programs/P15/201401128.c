
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int stack[10005];
int top,bottom;

int main()
{
    int t,n,k;
    scanf("%d",&t);

    int i;
    int A[10005];

    while(t--)
    {
        top=bottom=-1;
        scanf("%d%d",&n,&k);

        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }

        stack[++top]=0;
        ++bottom;
        for(i=1;i<k;i++)
        { 
            if(A[i]>=A[stack[top]])
                stack[++top]=i;
            else
            {
                while(top>=bottom && A[stack[top]]>A[i])
                    top--;
                stack[++top]=i;
            }
        }
        printf("%d",A[stack[bottom]]);

        for(i=k;i<n;i++)
        {
            if(i-k==stack[bottom])
                bottom++;
            if(A[i]>=A[stack[top]])
                stack[++top]=i;
            else
            {
                while(top>=bottom && A[stack[top]]>A[i])
                    top--;
                stack[++top]=i;
            }
            printf(" %d",A[stack[bottom]]);
        }

        printf("\n");


    }


    return 0;
}
