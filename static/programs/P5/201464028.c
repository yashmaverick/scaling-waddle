#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
       return ( *(int*)a - *(int*)b );
}
int main()
{int i,j,a,b,c,t,n,*q,k,count,m,l;
    scanf("%d",&t);
    while(t--)
    {count=0;
        scanf("%d%d",&a,&b);
        getchar();
        q=(int *)malloc(sizeof(int)*(a+8));
        for(k=0;k<a;k++)
        {while((c=getchar())!=' ')
        count=0;
        scanf("%d",&q[k]);
        getchar();
}
qsort(q,a,sizeof(int),cmpfunc);
count=0;
for(n=0;n<(a-2);n++)
{
    m=a-1;
    l=n+1;
    while(m>l)
    {
        if((q[n]+q[l]+q[m])==b)
        {count=1;
            break;
        }
        else if((q[n]+q[m]+q[l])<b)
        l++;
        else
            m--;
    }
    if(count==1)
        break;
}
if(count==1)
    printf("YES\n");
    else
    printf("NO\n");
    free(q);

    }
    return 0;}








