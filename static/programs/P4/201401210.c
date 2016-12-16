#include<stdio.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

typedef struct point
{
    int a , b , o;
};

struct point A[10000000];
ll ans ;

void hash(int x , int y)
{
    unsigned long long h = (ull)(x)*123456789 + (ull)(y);
    h %= 10000000;
    
    while(A[h].o != -1 )
    {
        if(A[h].a != x || A[h].b != y)
        {
            h++;
            if(h == 10000000)
                h = 0;
        }
        else if(A[h].a == x && A[h].b == y)
        {
            ans += A[h].o;
            A[h].o++;
            break;
        }
    }
    if(A[h].o == -1)
    {
        A[h].o = 1;
        A[h].a = x;
        A[h].b = y;
    }
}

void clear(int x , int y)
{
    unsigned long long h = (ull)(x)*123456789 + (ull)(y);
    h %= 10000000;
    
    while(A[h].o != -1)
    {
        A[h].o = -1;
        h++;
        if(h==10000000)
            h = 0;
    }
}

int main()
{
    int t , i , cj , cm , cr;
    char s[100005] ;
    scanf("%d",&t);
    memset(A,-1,sizeof A);
    while(t--)
    {
        ans = 0;
        cj = cm = cr = 0;
        hash(0,0);
        scanf(" %s",s);
        for(i=0;s[i];i++)
        {
            if(s[i] == 'J')
                cj++;
            else if(s[i] == 'M')
                cm++;
            else
                cr++;
            int a = cm - cj;
            int b = cr - cj;
            hash(a,b);
        }
        printf("%lld\n",ans);
        cj = cm = cr = 0;
        clear(0,0);
        for(i=0;s[i];i++)
        {
            if(s[i] == 'J')
                cj++;
            else if(s[i] == 'M')
                cm++;
            else
                cr++;
            int a = cm - cj;
            int b = cr - cj;
            clear(a,b);
        }
        
    }
    return 0;
}