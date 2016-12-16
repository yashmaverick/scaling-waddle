#include<stdio.h>
#include<stdlib.h>
int min(int *a,int K,int i)
{
        int m=a[i],p=i,t=i;
        for(;i<=t+K-1;i++)
                if(m>a[i])
                {
                        m=a[i];
                        p=i;
                }
        return p;
}
int main()
{
        int T,N,K,*a,l,m,j,p;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d %d",&N,&K);
                l=K-1;
                a=(int *)malloc(sizeof(int)*N+1);
                int i=1;
                for(;i<=N;i++)
                        scanf("%d",&a[i]);
                p=min(a,K,1);
                printf("%d",a[p]);
                for(i=2;i<=N-l;i++)
                {
                        if(a[p]>a[i+l] && i-1!=p)
                                p=i+l;
                        else if(i==p+1)
                                p=min(a,K,i);
                        printf(" %d",a[p]);
                }
                printf("\n");
        }
        return 0;
}
