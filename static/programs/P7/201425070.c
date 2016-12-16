#include <stdio.h>

typedef struct xyz{
    long long int val;
    long long int count;
}data;
void scanint(int *p);
long long int cmp(const void *a,const void *b);
int main()
{
    long long int test,i,j,k,n,temp,perm,sum;
    long long int a[1000000];
    scanf("%lld",&test);
    while(test--)
    {
        sum = 0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        qsort(a,n,sizeof(long long int),cmp);
        data var;
        var.val = a[0];
        var.count = 0;
        for(i=0;i<n;i++)
        {
            temp = a[i];
            if(var.val == temp)
                var.count++;
            else
            {
                if(n<2)
                    perm = 0;
                else
                    perm = (var.count*(var.count-1))/2;
                var.val = temp;
                var.count = 1;
                sum = perm + sum;
            }
        }

        if(n<2)
            perm = 0;
        else
            perm = (var.count*(var.count-1))/2;
        sum = perm + sum;
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
long long int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
