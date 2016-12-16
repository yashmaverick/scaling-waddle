#include<stdio.h>
#define modulo 1000000007
int main()
{
    int t;
    int i=0,j=0,k=0;
    scanf("%d",&t);
    while(t--)
    {
        long long int answer = 0;
        long long int arr[100001];
        int p1=0,n1=0;
        int p2=0,n2=0;
        int p3=0,n3=0;
        scanf("%d",&n1);
        int A[n1];
        for(i=0;i<n1;i++)
            scanf("%d",&A[i]);
        scanf("%d",&n2);
        int B[n2];
        for(i=0;i<n2;i++)
            scanf("%d",&B[i]);
        scanf("%d",&n3);
        int C[n3];
        for(i=0;i<n3;i++)
            scanf("%d",&C[i]);

        //Main Code Starts
        int temp=0;
        for(i=0;i<n2;i++)
        {
            if(temp<i)
                temp=(n3<=i?n3:i);
            while(temp<n3 && C[temp]<B[i])
                temp++;
            arr[i]=n3-temp;
        }
        for(i=n2-2;i>=0;i--)
            arr[i] += arr[i+1];
        temp=0;
        for(i=0;i<n1;++i)
        {
            if(temp<i)
                temp=(n2<=i?n2:i);
            while(temp<n2 && B[temp]<A[i])
                temp++;
            answer = (arr[temp] + answer)%modulo;
        }
        printf("%lld\n",answer);
    }
    return 0;
}
