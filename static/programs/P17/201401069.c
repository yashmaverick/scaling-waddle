#include<stdio.h>
#define MAX 1000001

int main()
{
    int t,pre[MAX],in[MAX],node,i,j,k,lca,in_k,in_j,min=2147483647,l;
    scanf("%d",&node);
    for(i=0;i<node;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<node;i++)
        scanf("%d",&in[i]);
    scanf("%d",&t);
    while(t--)
    {
        min=2147483647;
        lca=0;
        scanf("%d%d",&j,&k);
        for(i=0;i<node;i++)
            if(in[i]==j)
                break;
        in_j=i;
        for(i=0;i<node;i++)
            if(in[i]==k)
                break;
        in_k=i;
        //printf("in_j=%d in_k=%d\n",in_j,in_k);
        if(in_k<in_j)
        {
            for(i=in_k;i<=in_j;i++)
            {
                for(l=0;l<node;l++) 
                {
                    if(in[i]==pre[l])
                        if(l<min) 
                        {
                            min=l;
                            lca=pre[l];
                        }
                }                   
            }
        }
        else 
        {
            for(i=in_j;i<=in_k;i++)
            {
                for(l=0;l<node;l++) 
                {
                    if(in[i]==pre[l])
                        if(l<min) 
                        {
                            min=l;
                            lca=pre[l];
                        }
                }                   
            }
        }
        printf("%d\n",lca);
    }
    return 0;
}
