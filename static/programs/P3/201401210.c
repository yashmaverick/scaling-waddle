#include<stdio.h>

int md(int A[],int n)
{
    int diff = 0;
    int min = A[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(A[i] - min > diff)
            diff = A[i] - min;
        if(min > A[i])
            min = A[i];
    }
    return diff;
}

int main()
{
    int A[100005] , t , n , i , ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
        ans = md(A,n);
        printf("%d\n",ans);
        
    }
    return 0;
}