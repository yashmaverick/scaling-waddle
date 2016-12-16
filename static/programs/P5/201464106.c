#include<stdio.h>
int compare(int *m,int *n)
{
    return *m-*n;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a[n];
        char s[100000];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            scanf("%d",&a[i]);
        }
        int l,r,flag=0;
        qsort(a,n,4,compare);
        for(i=0;i<n-2;i++)
        {
            l=i+1;
            r=n-1;
            while(l<r)
            {
                if(a[i]+a[l]+a[r]==k)
                {
                    flag=1;
                    break;
                }
                else if(a[i]+a[l]+a[r]<k)
                    l++;
                else
                    r--;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}




