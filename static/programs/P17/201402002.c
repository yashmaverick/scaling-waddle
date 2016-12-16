#include<stdio.h>

int LCA=-1;

void find_lca(int A, int B, int *pre, int P_start, int P_end, int *in, int I_start, int I_end)
{
    // P=pre start
    // I=in start

    int root=pre[P_start],fav=0,c=0;
    if (P_start>=P_end || I_start>=P_end || P_end<0 || I_end<0)
        return;
    if (A==root || B==root)
    {
        LCA=(A==root)?A:B;
        return;
    }

    while(in[I_start]!=root)
    {
        if(in[I_start]==A || in[I_start]==B)
            fav++;
        I_start++;
        c++;
    }

    if (fav==2)
        find_lca(A,B,pre,P_start+1,P_start+c,in,I_start-c,I_start-1);
    else if(fav==0)
        find_lca(A,B,pre,P_start+c+1,P_end,in,I_start+1,I_end);
    else if (fav==1)
        LCA=pre[P_start];
    return;
}


int main()
{
    int t,i,A,B,l;
    scanf("%d",&l);
    int pre[l],in[l];
    for(i=0;i<l;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<l;i++)
        scanf("%d",&in[i]);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&A ,&B);
        find_lca(A,B,pre,0,l-1,in,0,l-1);
        printf("%d\n",LCA);
    }
    return 0;
}
