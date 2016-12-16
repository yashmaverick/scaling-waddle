#include <stdio.h>
void scanint(int *p);
int main()
{
    int test,i,j,k,len;
    int temp,max,min,dif;
    int a[100000];
    scanint(&test);
    while(test--)
    {
        scanint(&len);
        for(i=0;i<len;i++)
            scanint(&a[i]);
        max=0;
        min=a[0];
        temp=dif=0;
        for(i=0;i<len;i++)
        {
            temp = a[i] - min;
            if(a[i]<min)
                min = a[i];
            if(temp > max)
                max = temp;
        }
        printf("%d\n",max);
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


