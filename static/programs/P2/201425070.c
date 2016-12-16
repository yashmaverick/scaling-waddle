// #Authored : Jaipal Singh Goud
// Part of : DS Assignment 1 
// Date : 31/1/2015
// Sem I-II
// Look Up editorial on CodeForces for 3 Sorted Arrays : Lalit Kundu

#include <stdio.h>
#include <stdlib.h>

void scanint(int *p);
int main()
{
    int test,i,j,k,tr,tr2;
    int x,y,z;
    int A[100001];
    int B[100001];
    int C[100001];
    int temp[100001];
    int temp2[10001];

    scanf("%d",&test);

    while(test--)
    {
        long long int sum,count=0,count2=0,count3=0;
        sum=0;
        
        scanf("%d",&x);             // Scanning Array 1
        for(i=0;i<x;i++)
            scanf("%d",&A[i]);;
       
        scanf("%d",&y);             // Scanning Array 2
        for(i=0;i<y;i++)
            scanf("%d",&B[i]);
        
        scanf("%d",&z);             // Scanning Array 3
        for(i=0;i<z;i++)
            scanf("%d",&C[i]);
        
        int m,n;
        m = n = count = 0;          // Initializing to 0
        while(m<y)
        {
            if(B[m]>=A[n] && n<=m && n<x)
            {
                count++;
                n++;
            }
            else
            {
                temp[m]=count;
                m++;
            }
        }
        m = n = count = 0;   // Initializing to 0
        while(m<z)
        {
            if(C[m]>=B[n] && (n<=m && n<y))
            {
                count=count+temp[n];
                n = n+1;
            }
            else
            {
                count3 = count3+1;
                m = m+1;
                sum=sum+count;
            }
            count3=count2+1;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

void scanint(int *p)
{
    register int c = getchar_unlocked();
    int x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked())
        ;
    for(;c>47 && c<58;c = getchar_unlocked())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    *p = x;
}
