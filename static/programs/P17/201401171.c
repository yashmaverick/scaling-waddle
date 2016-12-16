#include<stdio.h>

#define maxN 1234567

int prer[maxN], inr[maxN], in[maxN], pre[maxN];

int min(int a, int b) {if (a>b)return b; else return a;}
int max(int a, int b) {if (a>b)return a; else return b;}

int main()
{

    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        pre[i]=a;
        prer[a]=i;
    }
    for(i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        in[i]=a;
        inr[a]=i;
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        int j,a,b,mine,k;
        scanf("%d %d",&a,&b);
        int u = min (inr[a], inr[b]) , v = max(inr[a], inr[b]);
        mine=prer[in[u]]; 
        k=u;
        for(j=u;j<=v;j++)
        {
            if(mine>prer[in[j]])
            {
                mine=prer[in[j]];
                k=j;
            }
        }
        printf("%d\n",in[k]);
    }
    return 0;
}
