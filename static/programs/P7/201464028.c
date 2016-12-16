#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)

{
    return(*(int *)a-*(int *)b);
}
int main()
{
    int i,j,n,t,*q,a,k;
    long long int count,b;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        q=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&q[i]);
        qsort(q,n,sizeof(int),cmp);
        a=q[0];
        b=1;
        for(k=1;k<n;k++)
        {
            if(q[k]==a)
            {
                b++;
            }
            else
            {
                a=q[k];
                count=count+(b*(b-1))/2;
                b=1;
            }
        }
        count=count+(b*(b-1))/2;
        printf("%lld\n",count);
        free(q);
    }
    return 0;
}


        
        
