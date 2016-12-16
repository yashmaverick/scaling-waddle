#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,j,k,kk,i,a[100000],flag=0;
        char nit[100000];
        scanf("%d%d",&n,&kk);
        for(i=0;i<n;i++)
        {
            scanf("%s%d",nit,&a[i]);
        }
        qsort(a,n,sizeof(int),cmpfunc);
        for(i=0;i<n-2;i++)
        {
            j=i+1;
            k=n-1;
            while(j!=k)
            {
                if(a[i]+a[j]+a[k]==kk)
                {
                    flag=1;
                    break;
                }
                else if(a[i]+a[j]+a[k]>kk)
                    k--;
                else if(a[i]+a[j]+a[k]<kk)
                    j++;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
