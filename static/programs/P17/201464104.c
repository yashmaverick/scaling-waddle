#include<stdio.h>
#include<stdlib.h>
int main()
{
        int n,t,a,b,ai,bi,ap,bp,i,j,k;
        scanf("%d",&n);
        int *pre=(int *)malloc(sizeof(int)*n);
        int *in=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
                scanf("%d",&pre[i]);
        for(i=0;i<n;i++)
                scanf("%d",&in[i]);
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                scanf("%d %d",&a,&b);
                for(j=0;j<n;j++)
                {
                        if(in[j]==a)
                                ai=j;
                        if(in[j]==b)
                                bi=j;
                }
                if(ai>bi)
                {
                        int t=ai;
                        ai=bi;
                        bi=t;
                }
                for(j=0;j<n;j++)
                {
                        for(k=ai;k<=bi;k++)
                        {
                                if(pre[j]==in[k])
                                {
                                        printf("%d\n",in[k]);
                                        k=bi;
                                        j=n;
                                        break;
                                }
                        }
                }
        }
        return 0;
}

