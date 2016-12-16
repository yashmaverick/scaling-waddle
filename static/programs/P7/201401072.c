#include<stdio.h>
int a[10000010];
int cmpfunc(const void *a,const void *b)
{
    return ( *(int *)a - *(int *)b );
}
 int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int i,j,m,n,count=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmpfunc);
        int val=a[0];
        m=1;
        for(i=1;i<n;i++)
        {
            if(a[i]==val)
                m++;
            else {
                val=a[i];
                if(m&1)
                count+=((m-1)/2)*m;
                else {
                    count+=(m/2)*(m-1);
                }
                m=1;
            }
        }
                if(m&1)
                count+=((m-1)/2)*m;
                else {
                    count+=(m/2)*(m-1);}

    printf("%lld\n",count);
    }
}
