#include<stdio.h>
int min(int a,int b)
{
    if(a<b)return a;
    return b;
}
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,n,t,exin[100005],in[100005],pre[100005];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
        exin[in[i]]=i;
    }
    scanf("%d",&t);
    while(t--)
    {
        int j,u,v,ans=0;
        scanf("%d%d",&u,&v);
        for(j=0;j<n;j++)
        {
            for(i=min(exin[u],exin[v]);i<=max(exin[u],exin[v]);i++)
                if(pre[j]==in[i])
                {
                    ans=pre[j];
                    break;
                }
            if(ans)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
