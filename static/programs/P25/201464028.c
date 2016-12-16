#include<stdio.h>
#include<stdlib.h>
typedef struct lim
{
    int u;
    int v;
    int w;
}lim;
lim we[1000000];
int compare(void const *a,void const *b)
{
    lim *A=(lim *)a;
    lim *B=(lim *)b;
    return (A->w-B->w);
}
int weight[1000000],ancs[1000000];
int king(int x)
{
    if(ancs[x]==x)
        return x;
    ancs[x]=king(ancs[x]);
    return ancs[x];
}
void sort(int a,int b)
{
    if(a<b)
    {
        weight[king(b)]+=weight[king(a)];
        ancs[king(a)]=king(b);
    }
    else
    {
        weight[king(a)]+=weight[king(b)];
        ancs[king(b)]=king(a);
    }
}
int main()
{
    int i,j,k,l,t,n,a,b,c,temp=0;
    long long int count=0;
    scanf("%d%d",&t,&n);
    for(i=1;i<=t;i++)
    {
        ancs[i]=i;
        weight[i]=1;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&we[i].u,&we[i].v,&we[i].w);
    }
    qsort(we,n,sizeof(lim),compare);
    for(i=0;i<n;i++)
    {
        if(king(we[i].v)!=king(we[i].u))
        {
            count+=we[i].w;
            sort(we[i].u,we[i].v);
        }
    }
    if(weight[king(we[1].u)]==t)
    printf("%lld\n",count);
    else
        printf("-1\n");
    return 0;
}



