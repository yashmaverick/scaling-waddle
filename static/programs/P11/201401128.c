
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int stack[100005];
int SP;

void push(int d)
{
    stack[++SP]=d;
}

int pop()
{
    return stack[SP--];
}

int main()
{
    int A[100005],L[100005],R[100005];

    int i,n;
    long long int max_ar,cur_max;
    scanf("%d",&n);
    while(n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }

        SP=-1;
        L[0]=0;
        push(0);

        for(i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
            {
                L[i]=0;
                push(i);
            }
            else if(A[i]<=A[i-1])
            {
                L[i]=0;
                while(SP>=0 && A[stack[SP]]>=A[i])
                {
                    L[i]+=L[pop()]+1;
                }
                push(i);
            }
        }

        /* for(i=0;i<n;i++)
           {
           printf("%d ",L[i]);
           }

           printf("\n");
           */
        
        SP=-1;
        R[n-1]=0;
        push(n-1);

        for(i=n-2;i>=0;i--)
        {
            if(A[i]>A[i+1])
            {
                R[i]=0;
                push(i);
            }
            else if(A[i]<=A[i+1])
            {
                R[i]=0;
                while(SP>=0 && A[stack[SP]]>=A[i])
                {
                    R[i]+=R[pop()]+1;
                }
                push(i);
            }
        }
        
        max_ar=0;
        for(i=0;i<n;i++)
        {
           cur_max=(long long int)(L[i]+R[i]+1)*(long long int)A[i];
            if(cur_max>max_ar)
                max_ar=cur_max;
        }

        printf("%lld\n",max_ar);
        
        scanf("%d",&n);
    }


    return 0;
}
