#include<stdio.h>
#include<stdlib.h>
#define f(x) scanf("%d",&x)
typedef struct limit
{
    int vertex;
    char dir;
}lim;
int main()
{
    int i,j,k,l,*q,*r,t,n,a,b,*c,m=0,s=0;
        lim *d;
    f(t);
    q=malloc(sizeof(int)*t);
    r=malloc(sizeof(int)*t);
    c=malloc(sizeof(int)*t);
    d=malloc(sizeof(lim)*t);
    for(i=0;i<t;i++)
        f(q[i]);
    for(i=0;i<t;i++)
        f(r[i]);
    f(n);
    for(i=0;i<n;i++)
    {
        f(a);
        f(b);
        m=0;
        s=0;
        for(k=0;k<t;k++)
        {
            m=0;
            s=0;
            if(q[k]==a || q[k]==b)
            {
                printf("%d\n",q[k]);
                break;
            }
            else
            {for(l=0;r[l]!=q[k];l++)
            {
                if(r[l]==a)
                    m=1;
                if(r[l]==b)
                    s=1;
                if(r[l]==q[k])
                    break;
            }
            if(m!=s)
            {
                printf("%d\n",q[k]);
                break;
            }}
        }
    }
    return 0;
}














