#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
           return ( *(int*)a - *(int*)b );
}
int main()
{
        int t1,t,n,flag,i,j,l;
        int *a;
        long long int c,s;
        scanf("%d",&t);
        for(t1=0;t1<t;t1++)
        {
                s=0;
                c=1;
                scanf("%d",&n);
                a=malloc(sizeof(int)*n);
                for(i=0;i<n;i++)
                        scanf("%d",&a[i]);
                qsort(a, n, sizeof(int), cmpfunc);
                l=a[0];
                for(j=1;j<n;j++)
                {
                       if(a[j]==l)
                               c++;
                       else
                       {
                               l=a[j];
                               s+=(c*(c-1))/2;
                               c=1;
                       }
                }
                s+=(c*(c-1))/2;
                printf("%lld\n",s);
                free(a);
        }
        return 0;
}

