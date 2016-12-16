#include <stdio.h>
#include <stdlib.h>
#define s(t) scanf("%d",&t)
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<=n;i++)
#define pY printf("YES\n")
#define pN printf("NO\n")
#define w(t) while(t--)
#define TRUE 1
#define FALSE 0
int a[1000];
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int check(int a[], int n, int sum)
{
    int l,r,i;
    qsort(a, n, sizeof(int), cmpfunc);
    f(i,n-2)
    {
        l=i+1;
        r=n-1;// index of the last element
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==sum)
                return TRUE;
            else if (a[i]+a[l]+a[r]<sum)
                l++;
            else
                r--;
        }
    }
    return FALSE;
}
int main()
{
    int t,n,sum,i;
    char st[100007];
    s(t);
    w(t)
    {
        s(n);s(sum);
        f(i,n)
        {
            scanf("%s",&st);
            s(a[i]);
        }
        (check(a, n, sum))?pY:pN;
    }
 
    getchar();
    return 0;
}