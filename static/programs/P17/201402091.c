#include<stdio.h>
#include<stdlib.h>
int pre[100000];
int inv[100000];
int k;
int lca(int n11,int n21,int st,int end)
{
    int index=inv[pre[k]];
    int n1=inv[n11];
    int n2=inv[n21];
//    printf("index=%d,n1 pos=%dn2 pos=%d\n",index,n1,n2);
    if(n11==n21)
        return n11;
    if(n1==index)
        return n11;
    if(n2==index)
        return n21;
    if((n1<index && n2>index)||(n2<index && n1>index))
        return pre[k];
    if(n1<index && n2<index)
    {   
        k=k+1;
        return lca(n11,n21,st,index-1);
    }
    if(n1>index && n2>index)
    {   
        k=k+(index-st+1);
        return lca(n11,n21,index+1,end);
    }
}
int main()
{
    int t,i,n,n1,n2,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        inv[t]=i;
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {   k=0;
        scanf("%d %d",&n1,&n2);
        x=lca(n1,n2,0,n-1);
        printf("%d\n",x);
    }
    return 0;
}

