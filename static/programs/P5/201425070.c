// Authored : Jaipal Singh Goud
// DS Assignment
// P5

#include <stdio.h>
int a[1000]={0};
char s[10000];
void scanint(int *p);
int compare(const void *a, const void *b);
int main()
{
    int i,j,k,l,n;
    int test;
    int count;
    char c;
    int sum=0;
    scanf("%d",&test);
    while(test--)
    {
        count = -1;
        scanf("%d",&n);
        scanf("%d",&sum);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            scanint(&a[i]);
        }

        qsort(a,n,sizeof(int),compare);
        int x,y,z;
        for(x=0;x<n;x++)
        {
            z=n-1;
            for(y=x+1;y<z;)
            {
                if(a[x]+a[y]+a[z] == sum)
                {
                    printf("YES\n");
                    count = 0;
                    break;
                }
                if(a[x]+a[y]+a[z] > sum)
                    z--;
                else
                    y++;
            }
            if(count == 0)
                break;
        }
        if(count != 0)
            printf("NO\n");
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
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
